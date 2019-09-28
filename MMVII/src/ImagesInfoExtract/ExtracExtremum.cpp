#include "include/MMVII_all.h"
#include "include/MMVII_2Include_Serial_Tpl.h"


namespace MMVII
{

template <class Type> int LexicoCmp(const std::vector<Type> & aV1,const std::vector<Type> & aV2)
{
    int aSz = std::min(aV1.size(),aV2.size());
    for (int aK=0 ; aK<aSz ; aK++)
    {
        if (aV1.at(aK) < aV2.at(aK))  return -1;
        if (aV1.at(aK) > aV2.at(aK))  return  1;
    }
    if (aV1.size() < aV2.size()) return -1;
    if (aV1.size() > aV2.size()) return 1;
    return 0;
}

template <class Type> class cAffineExtremum
{
    public :
       cAffineExtremum(const cDataIm2D<Type>  &anIm,double aRadius);
       cPt2dr OneIter(const cPt2dr &);
    private :
       const cDataIm2D<Type>  &  mIm;
       double                    mRadius;
       double                    mSqRad;
       cRect2                    mBox;
       cLeasSqtAA<tREAL4>        mSysPol;
       cDenseVect<tREAL4>        mVectPol;
       cDenseMatrix<tREAL4>      mMatPt;
       cDenseVect<tREAL4>        mVectPt;
};

template <class Type> cAffineExtremum<Type>::cAffineExtremum(const cDataIm2D<Type>  &anIm,double aRadius) :
    mIm      (anIm),
    mRadius  (aRadius),
    mSqRad   (Square(mRadius)),
    mBox     (cRect2::BoxWindow(round_up(aRadius+1))),
    mSysPol  (6),
    mVectPol (6),
    mMatPt   (2),
    mVectPt  (2)
{
}

template <class Type> cPt2dr cAffineExtremum<Type>::OneIter(const cPt2dr & aP0)
{    
   mSysPol.Reset();
   cPt2di aC = ToI(aP0);

   // #### 1 #####  fill the Least square sys  to compute the polynomial coeff
   for (const auto & aDP : mBox)
   {
      cPt2di aPix = aDP + aC;
      if (mIm.Inside(aPix)) // are we in image
      {
         double aN2 = SqN2(ToR(aPix)-aP0);
         if (aN2<mSqRad)  // Are we in circle
         {
            double aRatio = std::sqrt(aN2) / mRadius;
            double aWeight = CubAppGaussVal(aRatio);
            // A0 + A1 X + A2 Y + A3 X^2 + 2 A4 XY + A5 Y ^2
            mVectPol(0) = 1.0;
            mVectPol(1) = aDP.x();
            mVectPol(2) = aDP.y();
            mVectPol(3) = Square(aDP.x());
            mVectPol(4) = 2* aDP.x() * aDP.y();
            mVectPol(5) = Square(aDP.y());
            mSysPol.AddObservation(aWeight,mVectPol,mIm.GetV(aPix));
         }
      }
      else 
         return aP0;
   }
   // Compute the polynom
   cDenseVect<tREAL4>  aSolPol = mSysPol.Solve();

   // #### 2 #####   From the polynom get the extremum
   //   P.x  =  (A3 A4)-1  (-A1/2)
   //   P.y     (A4 A5)    (-A2/2)
   mMatPt.SetElem(0,0,aSolPol(3));
   mMatPt.SetElem(1,0,aSolPol(4));
   mMatPt.SetElem(0,1,aSolPol(4));
   mMatPt.SetElem(1,1,aSolPol(5));

   mVectPt(0) = -aSolPol(1)/2.0;
   mVectPt(1) = -aSolPol(2)/2.0;

   cDenseVect<tREAL4> aSolPt = mMatPt.Solve(mVectPt);

   // Solution was in "local" coordinates, put it in absolute
   return cPt2dr( aC.x()+aSolPt(0) , aC.y()+aSolPt(1));
}


template  class cAffineExtremum<tREAL4>;

/*
template <class Type,class FDist>  std::vector<Type>  SparseOrder(const std::vector<Type> & aV,const std::vector<Type>& aRepuls0)
{
     int aNb=aV.size();
     std::vector<Type> aRes = aRepuls0;
     std::vector<bool> aVSel(aNb,false);

     for (int aNbIter=0 ; aNbIter<aNb ; aNbIter++)
     {
         double aDMax = 0.0;
         for (
         
     }
} 
*/

// std::vector<cPt2di> SparsedVectOfRadius(const double & aR0,const double & aR1) // > R0 et <= R1

std::vector<cPt2di> SortedVectOfRadius(const double & aR0,const double & aR1) // > R0 et <= R1
{
    std::vector<cPt2di> aRes;

    double aR02 = Square(aR0);
    double aR12 = Square(aR1);
    
    for (const auto & aP : cRect2::BoxWindow(round_up(aR1)))
    {
        double aR2 = SqN2(aP);
        if ((aR2>aR02) && (aR2<=aR12))
           aRes.push_back(aP);
    }
    std::sort(aRes.begin(),aRes.end(),CmpN2<int,2>);

    return aRes;
}


/// Compute etremum point of an image
/** 
     This class computes extremum of an image, also it may seems
     quite complex for a basic definition, it deals with three specification :
        * makes comparison using a strict order (cmp Val, then x, then y )
        * be efficient using a maximum of "cuts", so order the comparison to maximize
          the probability that we know asap that we are not a max/min
        * be relarively easy to read

     The comparison is lexicographic with "Val(x,y) x y"
*/

template <class Type> class cComputeExtrem1Im
{
     public :

         cComputeExtrem1Im(const cDataIm2D<Type>  &anIm,cResultExtremum &,double aRadius);
         void ComputeRes();
         int  NbIn() const {return mNbIn;}
         const std::vector<cPt2di>& SortedNeigh() const {return mSortedNeigh;}
     protected :
        void TestIsExtre1();

        inline bool IsImCSupCurP(const cPt2di & aDP) const
        {
             Type aV = mDIM.GetV(mPCur+aDP);
             // Compare values
             if (aV>mVCur) return true;
             if (aV<mVCur) return false;
             // if equals compare x
             if (aDP.x()>0) return true;
             if (aDP.x()<0) return false;
             // if equals compare y
             return aDP.y() >  0;
        }

        const cDataIm2D<Type>  & mDIM;  ///< Image analysed
        cResultExtremum &    mRes;      ///< Storing of results
        double               mRadius;   ///< Size of neighboorhood
        std::vector<cPt2di>  mSortedNeigh;  ///< Neighooring point sorted by growing distance
        cPt2di               mPCur;      ///< Current point explored
        Type                 mVCur;      ///< Value of current point
        int                  mNbIn;
};

/// Compute etremum point between two images

/**
   This class is equivalent to cComputeExtrem1Im but deal with the
  case where we have 3 image, I0,I1,I2 assimilated to a 3-dimentionnal
  image (e.q. Iz(x,y) ) . 

   To facilitate the computation, the lexicographic comparison is :

        "Val(x,y) z x y"
*/

template <class Type> class cComputeExtrem3Im : public cComputeExtrem1Im<Type>
{
     public :
         cComputeExtrem3Im
         (
               const cDataIm2D<Type>  &anIUp,
               const cDataIm2D<Type>  &anImC,
               const cDataIm2D<Type>  &anIBottom,
               cResultExtremum &,
               double aRadius
         );
        void ComputeRes();
     protected :
        typedef cComputeExtrem1Im<Type> t1Im;
        void TestIsExtre3();

        // Test for 2 dif scaled images, as lexico is "V z x y", if V are equals
        // we  know the solution because z are not

         ///  test >=  with "up" image (if == then Z+1 > Z)
         inline bool IsImUpSupCurP(const cPt2di & aDP) const
         {
             return  (mDIMUp.GetV(t1Im::mPCur+aDP)>=t1Im::mVCur) ; 
         }
         ///  test >=  with "Bottom" image (if == then Z-1 < Z)
         inline bool IsImBotSupCurP(const cPt2di & aDP) const
         {
             return  (mDIMBot.GetV(t1Im::mPCur+aDP)>t1Im::mVCur) ; 
         }
         
         const cDataIm2D<Type>  & mDIMUp; ///< "Up" Image in the pyramid
         const cDataIm2D<Type>  & mDIMBot; ///< "Bottom" Image in the pyramid
};


/*   ================================= */
/*         cResultExtremum             */
/*   ================================= */

void cResultExtremum::Clear()
{
    mPtsMin.clear();
    mPtsMax.clear();
}

/*   ================================= */
/*         cComputeExtrem1Im           */
/*   ================================= */

template <class Type> void cComputeExtrem1Im<Type>::TestIsExtre1()
{
     mVCur = mDIM.GetV(mPCur);
     // Compare with left neighboor ,  after we know if it has to be a min or a max
     bool IsMin = IsImCSupCurP(cPt2di(-1,0));

     //   Now we know that if any comparison with a neighboor is not coherent with
     // the first one, it cannot be an extremum

     if (IsImCSupCurP(cPt2di(1,0)) != IsMin) return;
     if (IsImCSupCurP(cPt2di(0,1)) != IsMin) return;
     if (IsImCSupCurP(cPt2di(0,-1)) != IsMin) return;
 
     for (const auto & aDP : mSortedNeigh)
         if (IsImCSupCurP(aDP) != IsMin) 
            return;
    if (IsMin)
       mRes.mPtsMin.push_back(mPCur);
    else
       mRes.mPtsMax.push_back(mPCur);
}



template <class Type> 
    cComputeExtrem1Im<Type>::cComputeExtrem1Im(const cDataIm2D<Type>  &anIm,cResultExtremum & aRes,double aRadius) :
       mDIM  (anIm),
       mRes  (aRes),
       mRadius       (aRadius),
       mSortedNeigh  (SortedVectOfRadius(1.01,mRadius))
{
}

template <class Type> void cComputeExtrem1Im<Type>::ComputeRes()
{
    mRes.Clear();
    cPt2di aSzW = cPt2di::PCste(round_down(mRadius));
    cRect2 aRectInt (mDIM.Dilate(-aSzW));
    mNbIn = 0;
    
    for (const auto & aPCur : aRectInt)
    {
         mPCur = aPCur;
         TestIsExtre1();
         mNbIn ++;
    }
}

template <class Type> void ExtractExtremum1(const cDataIm2D<Type>  &anIm,cResultExtremum & aRes,double aRadius)
{
    cComputeExtrem1Im<Type> aCEI(anIm,aRes,aRadius);
    aCEI.ComputeRes();
}


/*   ================================= */
/*         cComputeExtrem3Im           */
/*   ================================= */

template <class Type> void cComputeExtrem3Im<Type>::TestIsExtre3()
{
     t1Im::mVCur = t1Im::mDIM.GetV(t1Im::mPCur);
     // Compare with left neighboor ,  after we know if it has to be a min or a max
     bool IsMin = t1Im::IsImCSupCurP(cPt2di(-1,0));

     //   Now we know that if any comparison with a neighboor is not coherent with
     // the first one, it cannot be an extremum

     if (t1Im::IsImCSupCurP(cPt2di(1,0)) != IsMin) return;
     if (t1Im::IsImCSupCurP(cPt2di(0,1)) != IsMin) return;
     if (t1Im::IsImCSupCurP(cPt2di(0,-1)) != IsMin) return;
   
     // Test vertical 
     if (IsImUpSupCurP (cPt2di(0,0)) != IsMin) return;
     if (IsImBotSupCurP(cPt2di(0,0)) != IsMin) return;

     // Test first neighboor
     if (IsImUpSupCurP (cPt2di(-1,0)) != IsMin) return;
     if (IsImBotSupCurP(cPt2di(-1,0)) != IsMin) return;

     // Test 3 neigh => !! this is necessary to do it 
     // explicitely as mSorteNeigh "DO NOT" contain 4-Neighboors
     if (IsImUpSupCurP (cPt2di( 1, 0)) != IsMin) return;
     if (IsImBotSupCurP(cPt2di( 1, 0)) != IsMin) return;
     if (IsImUpSupCurP (cPt2di( 0, 1)) != IsMin) return;
     if (IsImBotSupCurP(cPt2di( 0, 1)) != IsMin) return;
     if (IsImUpSupCurP (cPt2di( 0,-1)) != IsMin) return;
     if (IsImBotSupCurP(cPt2di( 0,-1)) != IsMin) return;

 
     // Now classicaly test all neighboors
     for (const auto & aDP : t1Im::mSortedNeigh)
     {
         if (t1Im::IsImCSupCurP  (aDP) != IsMin) return;
         if (IsImUpSupCurP (aDP) != IsMin) return;
         if (IsImBotSupCurP(aDP) != IsMin) return;
     }
     // Now if all test are passed it is an extrema
     if (IsMin)
        t1Im::mRes.mPtsMin.push_back(t1Im::mPCur);
     else
        t1Im::mRes.mPtsMax.push_back(t1Im::mPCur);
}

template <class Type> 
    cComputeExtrem3Im<Type>::cComputeExtrem3Im
    (
               const cDataIm2D<Type>  &anIUp,
               const cDataIm2D<Type>  &anImC,
               const cDataIm2D<Type>  &anIBottom,
               cResultExtremum & aRes,
               double aRadius
    ) :
      cComputeExtrem1Im<Type>(anImC,aRes,aRadius),
      mDIMUp   (anIUp),
      mDIMBot  (anIBottom)
       
{
    anImC.AssertSameArea(anIUp);
    anImC.AssertSameArea(anIBottom);
}

template <class Type> void cComputeExtrem3Im<Type>::ComputeRes()
{
    t1Im::mRes.Clear();
    cPt2di aSzW = cPt2di::PCste(round_down(t1Im::mRadius));
    cRect2 aRectInt (t1Im::mDIM.Dilate(-aSzW));
    
    for (const auto & aPCur : aRectInt)
    {
         t1Im::mPCur = aPCur;
         TestIsExtre3();
    }
}

template <class Type> void ExtractExtremum3
                           (
                                const cDataIm2D<Type>  &anImUp,
                                const cDataIm2D<Type>  &anImC,
                                const cDataIm2D<Type>  &anImBot,
                                cResultExtremum & aRes,
                                double aRadius
                           )
{
    cComputeExtrem3Im<Type> aCEI(anImUp,anImC,anImBot,aRes,aRadius);
    aCEI.ComputeRes();
}


/* ========================== */
/*     cDataGenUnTypedIm      */
/* ========================== */


#define MACRO_INSTANTIATE_ExtractExtremum(Type)\
template  class cComputeExtrem1Im<Type>;\
template  class cComputeExtrem3Im<Type>;\
template void ExtractExtremum1(const cDataIm2D<Type>  &anIm,cResultExtremum & aRes,double aRadius);\
template void ExtractExtremum3(const cDataIm2D<Type>  &anImUp,const cDataIm2D<Type>  &anIm, const cDataIm2D<Type>  &anImDown,cResultExtremum & aRes,double aRadius);\




MACRO_INSTANTIATE_ExtractExtremum(tREAL4);
MACRO_INSTANTIATE_ExtractExtremum(tINT2);


/* ============================================================== */
/*                                                                */
/*               BENCH                                            */
/*                                                                */
/* ============================================================== */

/**
 Extremum exraction has to be rigourous even in case where there is
 many equality (case when dealing with int image)
 This function create an image with a lot of "plateau".
*/

cIm2D<tINT2> ImageBenchExtrem(const cPt2di aSz,int aNbVal,int aSzMaj)
{
    cIm2D<tINT2> aRes(aSz);
    cDataIm2D<tINT2> & aDRes(aRes.DIm());

    // Pure random image on NbVal
    for (const auto & aP : aDRes)
    {
        aDRes.SetV(aP,round_ni(RandUnif_N(aNbVal)));
    }
    
    // regularize it with majority-filter
    SelfLabMaj(aRes,cRect2::BoxWindow(aSzMaj));

    return aRes;
}

/**  Test if two vector of points are equal, use Hash code, give informatio, when not */
void OneTestEqual_RE
     (
        const std::vector<cPt2di> & aV1,
        const std::vector<cPt2di> & aV2,
        const std::string & aMessage
     )
{
    if (HashValue(aV1,true)==HashValue(aV2,true) )
       return;

    for (const auto & aP : aV1)
    {
        if (!BoolFind(aV2,aP))
           StdOut() << "Difff1 " << aP << "\n";
    }
    for (const auto & aP : aV2)
    {
        if (!BoolFind(aV1,aP))
           StdOut() << "Difff2 " << aP << "\n";
    }
    MMVII_INTERNAL_ASSERT_bench
    (
         false,
         "Set in Bench Extre : " + aMessage
    );
}
/**  Test if two results of Extremum are equal, use Hash code */
void TestEqual_RE(cResultExtremum & aR1,cResultExtremum & aR2)
{
    OneTestEqual_RE(aR1.mPtsMin,aR2.mPtsMin,"Min");
    OneTestEqual_RE(aR1.mPtsMax,aR2.mPtsMax,"Min");
}

/**  Test extremum with different parameters simulation
*/

void OneBenchExtrem(int aNbLab,int aSzMaj,double aRay)
{
    // Create images
    cPt2di aSz(150,200);

    cIm2D<tINT2> aI1 = ImageBenchExtrem(aSz,aNbLab,aSzMaj);  // Center image
    cDataIm2D<tINT2> & aDI1(aI1.DIm());

    cIm2D<tINT2> aI0 = ImageBenchExtrem(aSz,aNbLab,aSzMaj); // "Up" image
    cDataIm2D<tINT2> & aDI0(aI0.DIm());
    cIm2D<tINT2> aI2 = ImageBenchExtrem(aSz,aNbLab,aSzMaj);  // "Bottom" image
    cDataIm2D<tINT2> & aDI2(aI2.DIm());


    // Compute extrema in one image, the "fast" way
    cResultExtremum aExtr1;
    cComputeExtrem1Im<tINT2> aCEI(aDI1,aExtr1,aRay);
    aCEI.ComputeRes();

    cResultExtremum aExtr3;
    ExtractExtremum3 (aDI0,aDI1,aDI2,aExtr3,aRay);


    int aNbIn = 0;
    // std::vector<cPt2di>  aVMin1;
    // std::vector<cPt2di>  aVMax;
    cResultExtremum aTestE1;
    cResultExtremum aTestE3;

    int aIRay =  round_down(aRay); // If x or y > aRay, cannot be in disc
    for (const auto & aP : aDI1)
    {
        bool IsMin1 = true;
        bool IsMax1 = true;
        bool IsOut = false;
        bool IsMin3 = true;
        bool IsMax3 = true;
        // lexicographic description on this pixel
        std::vector<int> aVImP({aDI1.GetV(aP),0,aP.x(),aP.y()}); 
        for (int aDx = -aIRay ;  aDx<= aIRay ; aDx++)  // parse box 
        {
            for (int aDy = -aIRay ;  aDy<= aIRay ; aDy++)
            {
                cPt2di aDP(aDx,aDy);   // neighoor offset
                int aR2 = Square(aDx)+Square(aDy);  // square dist of DP
                if (aR2  <= Square(aRay))  // Are we in the circle
                {
                    cPt2di aQ = aP + aDP;  // This is the neighoor
                    if (aDI1.Inside(aQ))   // Is it inside image ?
                    {
                       int aVQ0 = aDI0.GetV(aQ);
                       int aVQ1 = aDI1.GetV(aQ);
                       int aVQ2 = aDI2.GetV(aQ);
                       {
                          std::vector<int> aVImQ1({aVQ1,0,aQ.x(),aQ.y()});
                          // Make lexicall comparison
                          int  aCmp1 = LexicoCmp(aVImP,aVImQ1);
                          if (aCmp1==1)
                          {
                              IsMin1 = false;
                              IsMin3 = false;
                          }
                          if (aCmp1==-1)
                          {
                              IsMax1 = false;
                              IsMax3 = false;
                          }
                         
                          // Now for multiscale 
                          int aSign = 1;  // To facilitate swap
                          std::vector<int> aVImQ0({aVQ0,aSign,aQ.x(),aQ.y()});
                          std::vector<int> aVImQ2({aVQ2,-aSign,aQ.x(),aQ.y()});
                          int  aCmp0 = LexicoCmp(aVImP,aVImQ0);
                          int  aCmp2 = LexicoCmp(aVImP,aVImQ2);

                          if ((aCmp0==1) || (aCmp2==1))
                          {
                              IsMin3 = false;
                          }
                          if ((aCmp0==-1) || (aCmp2==-1))
                          {
                              IsMax3 = false;
                          }
                       }
                    }
                    else
                    {
                        IsOut = true;
                        IsMin1 = false;
                        IsMax1 = false;
                        IsMin3 = false;
                        IsMax3 = false;
                    }
                }
            }
        }
       
        if (IsMin1) 
           aTestE1.mPtsMin.push_back(aP);
        if (IsMax1) 
           aTestE1.mPtsMax.push_back(aP);
        if (IsMin3) 
           aTestE3.mPtsMin.push_back(aP);
        if (IsMax3) 
           aTestE3.mPtsMax.push_back(aP);
        if (! IsOut) 
        {
           aNbIn++;
        }
    }
    if (0) // May be used again for debug
    {
       for (const auto & aP : aTestE1.mPtsMin)
       {
            if (!BoolFind(aExtr1.mPtsMin,aP))
               StdOut() << "Difff " << aP << "\n";
       }
    }
    // Before all, be reasonnably sure it's the same set
    MMVII_INTERNAL_ASSERT_bench(aNbIn==aCEI.NbIn() ,"Set in Bench Extre ");

    TestEqual_RE(aTestE1,aExtr1);
    TestEqual_RE(aTestE3,aExtr3);
}


void OneBenchAffineExtre()
{
    static int aCpt=0;
    aCpt++;
    int aSign = (aCpt%2) ? 1 : -1;

    cPt2di aSz(60,60);

    // Generate parameter of quadratic shape
    double aCste = 10* RandUnif_0_1(); 
    double aVA = aSign * (RandUnif_0_1() * 0.1); 
    double aVB = aSign *(RandUnif_0_1() * 0.1); 
    double aVC = aSign *(RandUnif_0_1() * 0.1); 
    cPt2dr aCenter (aSz.x()/2.0+RandUnif_C()*3,aSz.y()/2.0+RandUnif_C()*3);

    // Generate image 
    cIm2D<tREAL4> aIm(aSz);
    cDataIm2D<tREAL4> & aDIm = aIm.DIm();
    for (const auto aPix : aDIm)
    {
         cPt2dr aDif = aCenter - ToR(aPix);
         tREAL4 aVal = aCste + aVA * Square(aDif.x()) + 2 * aVB * aDif.x()*aDif.y() + aVC * Square(aDif.y());
         aDIm.SetV(aPix,aVal);
    }


    cAffineExtremum<tREAL4> anAff(aDIm,10.0);

    for (int aK=0 ; aK<10 ; aK++)
    {
         // Initialize at a random distance of 2 pixel 
         cPt2dr  aP0 = aCenter + cPt2dr(RandUnif_C(),RandUnif_C())*2.0;
         cPt2dr  aCurC = aP0;
         for (int aNbIter=0 ; aNbIter< 6 ;aNbIter ++)
         {
             aCurC = anAff.OneIter(aCurC);
         }
         MMVII_INTERNAL_ASSERT_bench(Norm2(aCurC-aCenter)<1e-3,"Sz set in  cAppli_MMRecall");
    }
}

void BenchAffineExtre()
{
   for (int aK=0 ; aK<10 ; aK++)
   {
      OneBenchAffineExtre();
   }
}


void BenchExtre()
{
     for (int aNbLab=2 ; aNbLab<5 ; aNbLab+=2)
     {
         for (int aSzW=2 ; aSzW<5 ; aSzW+=2)
         {
             OneBenchExtrem(aNbLab,aSzW,3.1);
             OneBenchExtrem(aNbLab,aSzW,3.0);
             OneBenchExtrem(aNbLab,aSzW,2.9);
         }
     }
     BenchAffineExtre();
     StdOut() << "Bench Extremmum\n";
}


};
