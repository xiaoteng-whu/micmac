// File Automatically generated by eLiSe
#include "StdAfx.h"
#include "cGeneratedCodeTestCam.h"


cGeneratedCodeTestCam::cGeneratedCodeTestCam():
    cElCompiledFonc(2)
{
   AddIntRef (cIncIntervale("CCam",3,6));
   AddIntRef (cIncIntervale("CD",9,11));
   AddIntRef (cIncIntervale("F",16,17));
   AddIntRef (cIncIntervale("K2",11,12));
   AddIntRef (cIncIntervale("K4",12,13));
   AddIntRef (cIncIntervale("K6",13,14));
   AddIntRef (cIncIntervale("PGr",0,3));
   AddIntRef (cIncIntervale("PP",14,16));
   AddIntRef (cIncIntervale("W",6,9));
   Close(false);
}



void cGeneratedCodeTestCam::ComputeVal()
{
   double tmp0_ = mCompCoord[0];
   double tmp1_ = mCompCoord[3];
   double tmp2_ = tmp0_ - tmp1_;
   double tmp3_ = mCompCoord[1];
   double tmp4_ = mCompCoord[4];
   double tmp5_ = tmp3_ - tmp4_;
   double tmp6_ = mCompCoord[2];
   double tmp7_ = mCompCoord[5];
   double tmp8_ = tmp6_ - tmp7_;
   double tmp9_ = mLocR0_0_2 * (tmp2_);
   double tmp10_ = mLocR0_1_2 * (tmp5_);
   double tmp11_ = tmp9_ + tmp10_;
   double tmp12_ = mLocR0_2_2 * (tmp8_);
   double tmp13_ = tmp11_ + tmp12_;
   double tmp14_ = mLocR0_0_1 * (tmp2_);
   double tmp15_ = mLocR0_1_1 * (tmp5_);
   double tmp16_ = tmp14_ + tmp15_;
   double tmp17_ = mLocR0_2_1 * (tmp8_);
   double tmp18_ = tmp16_ + tmp17_;
   double tmp19_ = mCompCoord[7];
   double tmp20_ = mLocR0_0_0 * (tmp2_);
   double tmp21_ = mLocR0_1_0 * (tmp5_);
   double tmp22_ = tmp20_ + tmp21_;
   double tmp23_ = mLocR0_2_0 * (tmp8_);
   double tmp24_ = tmp22_ + tmp23_;
   double tmp25_ = tmp19_ * (tmp13_);
   double tmp26_ = mCompCoord[8];
   double tmp27_ = tmp26_ * (tmp18_);
   double tmp28_ = tmp25_ - tmp27_;
   double tmp29_ = tmp24_ + tmp28_;
   double tmp30_ = mCompCoord[6];
   double tmp31_ = tmp30_ * (tmp18_);
   double tmp32_ = tmp19_ * (tmp24_);
   double tmp33_ = tmp31_ - tmp32_;
   double tmp34_ = tmp13_ + tmp33_;
   double tmp35_ = (tmp29_) / (tmp34_);
   double tmp36_ = mCompCoord[9];
   double tmp37_ = tmp35_ - tmp36_;
   double tmp38_ = ElSquare(tmp37_);
   double tmp39_ = tmp26_ * (tmp24_);
   double tmp40_ = tmp30_ * (tmp13_);
   double tmp41_ = tmp39_ - tmp40_;
   double tmp42_ = tmp18_ + tmp41_;
   double tmp43_ = (tmp42_) / (tmp34_);
   double tmp44_ = mCompCoord[10];
   double tmp45_ = tmp43_ - tmp44_;
   double tmp46_ = ElSquare(tmp45_);
   double tmp47_ = tmp38_ + tmp46_;
   double tmp48_ = mCompCoord[11];
   double tmp49_ = tmp48_ * (tmp47_);
   double tmp50_ = mCompCoord[12];
   double tmp51_ = ElSquare(tmp47_);
   double tmp52_ = tmp50_ * tmp51_;
   double tmp53_ = tmp49_ + tmp52_;
   double tmp54_ = mCompCoord[13];
   double tmp55_ = VCube(tmp47_);
   double tmp56_ = tmp54_ * tmp55_;
   double tmp57_ = tmp53_ + tmp56_;
   double tmp58_ = mCompCoord[16];

  mVal[0] = (mCompCoord[14] + (tmp35_ + (tmp37_) * (tmp57_)) * tmp58_) - mLocMesIm_x;

  mVal[1] = (mCompCoord[15] + (tmp43_ + (tmp45_) * (tmp57_)) * tmp58_) - mLocMesIm_y;

}


void cGeneratedCodeTestCam::ComputeValDeriv()
{
   double tmp0_ = mCompCoord[0];
   double tmp1_ = mCompCoord[3];
   double tmp2_ = tmp0_ - tmp1_;
   double tmp3_ = mCompCoord[1];
   double tmp4_ = mCompCoord[4];
   double tmp5_ = tmp3_ - tmp4_;
   double tmp6_ = mCompCoord[2];
   double tmp7_ = mCompCoord[5];
   double tmp8_ = tmp6_ - tmp7_;
   double tmp9_ = mLocR0_0_2 * (tmp2_);
   double tmp10_ = mLocR0_1_2 * (tmp5_);
   double tmp11_ = tmp9_ + tmp10_;
   double tmp12_ = mLocR0_2_2 * (tmp8_);
   double tmp13_ = tmp11_ + tmp12_;
   double tmp14_ = mLocR0_0_1 * (tmp2_);
   double tmp15_ = mLocR0_1_1 * (tmp5_);
   double tmp16_ = tmp14_ + tmp15_;
   double tmp17_ = mLocR0_2_1 * (tmp8_);
   double tmp18_ = tmp16_ + tmp17_;
   double tmp19_ = mCompCoord[7];
   double tmp20_ = mLocR0_0_0 * (tmp2_);
   double tmp21_ = mLocR0_1_0 * (tmp5_);
   double tmp22_ = tmp20_ + tmp21_;
   double tmp23_ = mLocR0_2_0 * (tmp8_);
   double tmp24_ = tmp22_ + tmp23_;
   double tmp25_ = tmp19_ * (tmp13_);
   double tmp26_ = mCompCoord[8];
   double tmp27_ = tmp26_ * (tmp18_);
   double tmp28_ = tmp25_ - tmp27_;
   double tmp29_ = tmp24_ + tmp28_;
   double tmp30_ = mCompCoord[6];
   double tmp31_ = tmp30_ * (tmp18_);
   double tmp32_ = tmp19_ * (tmp24_);
   double tmp33_ = tmp31_ - tmp32_;
   double tmp34_ = tmp13_ + tmp33_;
   double tmp35_ = (tmp29_) / (tmp34_);
   double tmp36_ = mCompCoord[9];
   double tmp37_ = tmp35_ - tmp36_;
   double tmp38_ = ElSquare(tmp37_);
   double tmp39_ = tmp26_ * (tmp24_);
   double tmp40_ = tmp30_ * (tmp13_);
   double tmp41_ = tmp39_ - tmp40_;
   double tmp42_ = tmp18_ + tmp41_;
   double tmp43_ = (tmp42_) / (tmp34_);
   double tmp44_ = mCompCoord[10];
   double tmp45_ = tmp43_ - tmp44_;
   double tmp46_ = ElSquare(tmp45_);
   double tmp47_ = tmp38_ + tmp46_;
   double tmp48_ = mLocR0_0_2 * tmp19_;
   double tmp49_ = mLocR0_0_1 * tmp26_;
   double tmp50_ = tmp48_ - tmp49_;
   double tmp51_ = mLocR0_0_0 + tmp50_;
   double tmp52_ = (tmp51_) * (tmp34_);
   double tmp53_ = mLocR0_0_1 * tmp30_;
   double tmp54_ = mLocR0_0_0 * tmp19_;
   double tmp55_ = tmp53_ - tmp54_;
   double tmp56_ = mLocR0_0_2 + tmp55_;
   double tmp57_ = (tmp29_) * (tmp56_);
   double tmp58_ = tmp52_ - tmp57_;
   double tmp59_ = ElSquare(tmp34_);
   double tmp60_ = (tmp58_) / tmp59_;
   double tmp61_ = mCompCoord[11];
   double tmp62_ = tmp61_ * (tmp47_);
   double tmp63_ = mCompCoord[12];
   double tmp64_ = ElSquare(tmp47_);
   double tmp65_ = tmp63_ * tmp64_;
   double tmp66_ = tmp62_ + tmp65_;
   double tmp67_ = mCompCoord[13];
   double tmp68_ = VCube(tmp47_);
   double tmp69_ = tmp67_ * tmp68_;
   double tmp70_ = tmp66_ + tmp69_;
   double tmp71_ = 2 * (tmp60_);
   double tmp72_ = tmp71_ * (tmp37_);
   double tmp73_ = mLocR0_0_0 * tmp26_;
   double tmp74_ = mLocR0_0_2 * tmp30_;
   double tmp75_ = tmp73_ - tmp74_;
   double tmp76_ = mLocR0_0_1 + tmp75_;
   double tmp77_ = (tmp76_) * (tmp34_);
   double tmp78_ = (tmp42_) * (tmp56_);
   double tmp79_ = tmp77_ - tmp78_;
   double tmp80_ = (tmp79_) / tmp59_;
   double tmp81_ = 2 * (tmp80_);
   double tmp82_ = tmp81_ * (tmp45_);
   double tmp83_ = tmp72_ + tmp82_;
   double tmp84_ = mCompCoord[16];
   double tmp85_ = mLocR0_1_2 * tmp19_;
   double tmp86_ = mLocR0_1_1 * tmp26_;
   double tmp87_ = tmp85_ - tmp86_;
   double tmp88_ = mLocR0_1_0 + tmp87_;
   double tmp89_ = (tmp88_) * (tmp34_);
   double tmp90_ = mLocR0_1_1 * tmp30_;
   double tmp91_ = mLocR0_1_0 * tmp19_;
   double tmp92_ = tmp90_ - tmp91_;
   double tmp93_ = mLocR0_1_2 + tmp92_;
   double tmp94_ = (tmp29_) * (tmp93_);
   double tmp95_ = tmp89_ - tmp94_;
   double tmp96_ = (tmp95_) / tmp59_;
   double tmp97_ = 2 * (tmp96_);
   double tmp98_ = tmp97_ * (tmp37_);
   double tmp99_ = mLocR0_1_0 * tmp26_;
   double tmp100_ = mLocR0_1_2 * tmp30_;
   double tmp101_ = tmp99_ - tmp100_;
   double tmp102_ = mLocR0_1_1 + tmp101_;
   double tmp103_ = (tmp102_) * (tmp34_);
   double tmp104_ = (tmp42_) * (tmp93_);
   double tmp105_ = tmp103_ - tmp104_;
   double tmp106_ = (tmp105_) / tmp59_;
   double tmp107_ = 2 * (tmp106_);
   double tmp108_ = tmp107_ * (tmp45_);
   double tmp109_ = tmp98_ + tmp108_;
   double tmp110_ = mLocR0_2_2 * tmp19_;
   double tmp111_ = mLocR0_2_1 * tmp26_;
   double tmp112_ = tmp110_ - tmp111_;
   double tmp113_ = mLocR0_2_0 + tmp112_;
   double tmp114_ = (tmp113_) * (tmp34_);
   double tmp115_ = mLocR0_2_1 * tmp30_;
   double tmp116_ = mLocR0_2_0 * tmp19_;
   double tmp117_ = tmp115_ - tmp116_;
   double tmp118_ = mLocR0_2_2 + tmp117_;
   double tmp119_ = (tmp29_) * (tmp118_);
   double tmp120_ = tmp114_ - tmp119_;
   double tmp121_ = (tmp120_) / tmp59_;
   double tmp122_ = 2 * (tmp121_);
   double tmp123_ = tmp122_ * (tmp37_);
   double tmp124_ = mLocR0_2_0 * tmp26_;
   double tmp125_ = mLocR0_2_2 * tmp30_;
   double tmp126_ = tmp124_ - tmp125_;
   double tmp127_ = mLocR0_2_1 + tmp126_;
   double tmp128_ = (tmp127_) * (tmp34_);
   double tmp129_ = (tmp42_) * (tmp118_);
   double tmp130_ = tmp128_ - tmp129_;
   double tmp131_ = (tmp130_) / tmp59_;
   double tmp132_ = 2 * (tmp131_);
   double tmp133_ = tmp132_ * (tmp45_);
   double tmp134_ = tmp123_ + tmp133_;
   double tmp135_ = -(1);
   double tmp136_ = tmp135_ * mLocR0_0_2;
   double tmp137_ = tmp135_ * mLocR0_0_1;
   double tmp138_ = tmp135_ * mLocR0_0_0;
   double tmp139_ = tmp136_ * tmp19_;
   double tmp140_ = tmp137_ * tmp26_;
   double tmp141_ = tmp139_ - tmp140_;
   double tmp142_ = tmp138_ + tmp141_;
   double tmp143_ = (tmp142_) * (tmp34_);
   double tmp144_ = tmp137_ * tmp30_;
   double tmp145_ = tmp138_ * tmp19_;
   double tmp146_ = tmp144_ - tmp145_;
   double tmp147_ = tmp136_ + tmp146_;
   double tmp148_ = (tmp29_) * (tmp147_);
   double tmp149_ = tmp143_ - tmp148_;
   double tmp150_ = (tmp149_) / tmp59_;
   double tmp151_ = 2 * (tmp150_);
   double tmp152_ = tmp151_ * (tmp37_);
   double tmp153_ = tmp138_ * tmp26_;
   double tmp154_ = tmp136_ * tmp30_;
   double tmp155_ = tmp153_ - tmp154_;
   double tmp156_ = tmp137_ + tmp155_;
   double tmp157_ = (tmp156_) * (tmp34_);
   double tmp158_ = (tmp42_) * (tmp147_);
   double tmp159_ = tmp157_ - tmp158_;
   double tmp160_ = (tmp159_) / tmp59_;
   double tmp161_ = 2 * (tmp160_);
   double tmp162_ = tmp161_ * (tmp45_);
   double tmp163_ = tmp152_ + tmp162_;
   double tmp164_ = tmp135_ * mLocR0_1_2;
   double tmp165_ = tmp135_ * mLocR0_1_1;
   double tmp166_ = tmp135_ * mLocR0_1_0;
   double tmp167_ = tmp164_ * tmp19_;
   double tmp168_ = tmp165_ * tmp26_;
   double tmp169_ = tmp167_ - tmp168_;
   double tmp170_ = tmp166_ + tmp169_;
   double tmp171_ = (tmp170_) * (tmp34_);
   double tmp172_ = tmp165_ * tmp30_;
   double tmp173_ = tmp166_ * tmp19_;
   double tmp174_ = tmp172_ - tmp173_;
   double tmp175_ = tmp164_ + tmp174_;
   double tmp176_ = (tmp29_) * (tmp175_);
   double tmp177_ = tmp171_ - tmp176_;
   double tmp178_ = (tmp177_) / tmp59_;
   double tmp179_ = 2 * (tmp178_);
   double tmp180_ = tmp179_ * (tmp37_);
   double tmp181_ = tmp166_ * tmp26_;
   double tmp182_ = tmp164_ * tmp30_;
   double tmp183_ = tmp181_ - tmp182_;
   double tmp184_ = tmp165_ + tmp183_;
   double tmp185_ = (tmp184_) * (tmp34_);
   double tmp186_ = (tmp42_) * (tmp175_);
   double tmp187_ = tmp185_ - tmp186_;
   double tmp188_ = (tmp187_) / tmp59_;
   double tmp189_ = 2 * (tmp188_);
   double tmp190_ = tmp189_ * (tmp45_);
   double tmp191_ = tmp180_ + tmp190_;
   double tmp192_ = tmp135_ * mLocR0_2_2;
   double tmp193_ = tmp135_ * mLocR0_2_1;
   double tmp194_ = tmp135_ * mLocR0_2_0;
   double tmp195_ = tmp192_ * tmp19_;
   double tmp196_ = tmp193_ * tmp26_;
   double tmp197_ = tmp195_ - tmp196_;
   double tmp198_ = tmp194_ + tmp197_;
   double tmp199_ = (tmp198_) * (tmp34_);
   double tmp200_ = tmp193_ * tmp30_;
   double tmp201_ = tmp194_ * tmp19_;
   double tmp202_ = tmp200_ - tmp201_;
   double tmp203_ = tmp192_ + tmp202_;
   double tmp204_ = (tmp29_) * (tmp203_);
   double tmp205_ = tmp199_ - tmp204_;
   double tmp206_ = (tmp205_) / tmp59_;
   double tmp207_ = 2 * (tmp206_);
   double tmp208_ = tmp207_ * (tmp37_);
   double tmp209_ = tmp194_ * tmp26_;
   double tmp210_ = tmp192_ * tmp30_;
   double tmp211_ = tmp209_ - tmp210_;
   double tmp212_ = tmp193_ + tmp211_;
   double tmp213_ = (tmp212_) * (tmp34_);
   double tmp214_ = (tmp42_) * (tmp203_);
   double tmp215_ = tmp213_ - tmp214_;
   double tmp216_ = (tmp215_) / tmp59_;
   double tmp217_ = 2 * (tmp216_);
   double tmp218_ = tmp217_ * (tmp45_);
   double tmp219_ = tmp208_ + tmp218_;
   double tmp220_ = (tmp29_) * (tmp18_);
   double tmp221_ = -(tmp220_);
   double tmp222_ = tmp221_ / tmp59_;
   double tmp223_ = 2 * (tmp222_);
   double tmp224_ = tmp223_ * (tmp37_);
   double tmp225_ = -(tmp13_);
   double tmp226_ = tmp225_ * (tmp34_);
   double tmp227_ = (tmp42_) * (tmp18_);
   double tmp228_ = tmp226_ - tmp227_;
   double tmp229_ = (tmp228_) / tmp59_;
   double tmp230_ = 2 * (tmp229_);
   double tmp231_ = tmp230_ * (tmp45_);
   double tmp232_ = tmp224_ + tmp231_;
   double tmp233_ = (tmp13_) * (tmp34_);
   double tmp234_ = -(tmp24_);
   double tmp235_ = (tmp29_) * tmp234_;
   double tmp236_ = tmp233_ - tmp235_;
   double tmp237_ = (tmp236_) / tmp59_;
   double tmp238_ = 2 * (tmp237_);
   double tmp239_ = tmp238_ * (tmp37_);
   double tmp240_ = (tmp42_) * tmp234_;
   double tmp241_ = -(tmp240_);
   double tmp242_ = tmp241_ / tmp59_;
   double tmp243_ = 2 * (tmp242_);
   double tmp244_ = tmp243_ * (tmp45_);
   double tmp245_ = tmp239_ + tmp244_;
   double tmp246_ = -(tmp18_);
   double tmp247_ = tmp246_ * (tmp34_);
   double tmp248_ = (tmp247_) / tmp59_;
   double tmp249_ = 2 * (tmp248_);
   double tmp250_ = tmp249_ * (tmp37_);
   double tmp251_ = (tmp24_) * (tmp34_);
   double tmp252_ = (tmp251_) / tmp59_;
   double tmp253_ = 2 * (tmp252_);
   double tmp254_ = tmp253_ * (tmp45_);
   double tmp255_ = tmp250_ + tmp254_;
   double tmp256_ = 2 * tmp135_;
   double tmp257_ = tmp256_ * (tmp37_);
   double tmp258_ = tmp256_ * (tmp45_);
   double tmp259_ = (tmp37_) * (tmp70_);
   double tmp260_ = tmp35_ + tmp259_;
   double tmp261_ = (tmp83_) * tmp61_;
   double tmp262_ = 2 * (tmp83_);
   double tmp263_ = tmp262_ * (tmp47_);
   double tmp264_ = tmp263_ * tmp63_;
   double tmp265_ = tmp261_ + tmp264_;
   double tmp266_ = 3 * (tmp83_);
   double tmp267_ = tmp266_ * tmp64_;
   double tmp268_ = tmp267_ * tmp67_;
   double tmp269_ = tmp265_ + tmp268_;
   double tmp270_ = (tmp109_) * tmp61_;
   double tmp271_ = 2 * (tmp109_);
   double tmp272_ = tmp271_ * (tmp47_);
   double tmp273_ = tmp272_ * tmp63_;
   double tmp274_ = tmp270_ + tmp273_;
   double tmp275_ = 3 * (tmp109_);
   double tmp276_ = tmp275_ * tmp64_;
   double tmp277_ = tmp276_ * tmp67_;
   double tmp278_ = tmp274_ + tmp277_;
   double tmp279_ = (tmp134_) * tmp61_;
   double tmp280_ = 2 * (tmp134_);
   double tmp281_ = tmp280_ * (tmp47_);
   double tmp282_ = tmp281_ * tmp63_;
   double tmp283_ = tmp279_ + tmp282_;
   double tmp284_ = 3 * (tmp134_);
   double tmp285_ = tmp284_ * tmp64_;
   double tmp286_ = tmp285_ * tmp67_;
   double tmp287_ = tmp283_ + tmp286_;
   double tmp288_ = (tmp163_) * tmp61_;
   double tmp289_ = 2 * (tmp163_);
   double tmp290_ = tmp289_ * (tmp47_);
   double tmp291_ = tmp290_ * tmp63_;
   double tmp292_ = tmp288_ + tmp291_;
   double tmp293_ = 3 * (tmp163_);
   double tmp294_ = tmp293_ * tmp64_;
   double tmp295_ = tmp294_ * tmp67_;
   double tmp296_ = tmp292_ + tmp295_;
   double tmp297_ = (tmp191_) * tmp61_;
   double tmp298_ = 2 * (tmp191_);
   double tmp299_ = tmp298_ * (tmp47_);
   double tmp300_ = tmp299_ * tmp63_;
   double tmp301_ = tmp297_ + tmp300_;
   double tmp302_ = 3 * (tmp191_);
   double tmp303_ = tmp302_ * tmp64_;
   double tmp304_ = tmp303_ * tmp67_;
   double tmp305_ = tmp301_ + tmp304_;
   double tmp306_ = (tmp219_) * tmp61_;
   double tmp307_ = 2 * (tmp219_);
   double tmp308_ = tmp307_ * (tmp47_);
   double tmp309_ = tmp308_ * tmp63_;
   double tmp310_ = tmp306_ + tmp309_;
   double tmp311_ = 3 * (tmp219_);
   double tmp312_ = tmp311_ * tmp64_;
   double tmp313_ = tmp312_ * tmp67_;
   double tmp314_ = tmp310_ + tmp313_;
   double tmp315_ = (tmp232_) * tmp61_;
   double tmp316_ = 2 * (tmp232_);
   double tmp317_ = tmp316_ * (tmp47_);
   double tmp318_ = tmp317_ * tmp63_;
   double tmp319_ = tmp315_ + tmp318_;
   double tmp320_ = 3 * (tmp232_);
   double tmp321_ = tmp320_ * tmp64_;
   double tmp322_ = tmp321_ * tmp67_;
   double tmp323_ = tmp319_ + tmp322_;
   double tmp324_ = (tmp245_) * tmp61_;
   double tmp325_ = 2 * (tmp245_);
   double tmp326_ = tmp325_ * (tmp47_);
   double tmp327_ = tmp326_ * tmp63_;
   double tmp328_ = tmp324_ + tmp327_;
   double tmp329_ = 3 * (tmp245_);
   double tmp330_ = tmp329_ * tmp64_;
   double tmp331_ = tmp330_ * tmp67_;
   double tmp332_ = tmp328_ + tmp331_;
   double tmp333_ = (tmp255_) * tmp61_;
   double tmp334_ = 2 * (tmp255_);
   double tmp335_ = tmp334_ * (tmp47_);
   double tmp336_ = tmp335_ * tmp63_;
   double tmp337_ = tmp333_ + tmp336_;
   double tmp338_ = 3 * (tmp255_);
   double tmp339_ = tmp338_ * tmp64_;
   double tmp340_ = tmp339_ * tmp67_;
   double tmp341_ = tmp337_ + tmp340_;
   double tmp342_ = tmp257_ * tmp61_;
   double tmp343_ = 2 * tmp257_;
   double tmp344_ = tmp343_ * (tmp47_);
   double tmp345_ = tmp344_ * tmp63_;
   double tmp346_ = tmp342_ + tmp345_;
   double tmp347_ = 3 * tmp257_;
   double tmp348_ = tmp347_ * tmp64_;
   double tmp349_ = tmp348_ * tmp67_;
   double tmp350_ = tmp346_ + tmp349_;
   double tmp351_ = tmp135_ * (tmp70_);
   double tmp352_ = tmp258_ * tmp61_;
   double tmp353_ = 2 * tmp258_;
   double tmp354_ = tmp353_ * (tmp47_);
   double tmp355_ = tmp354_ * tmp63_;
   double tmp356_ = tmp352_ + tmp355_;
   double tmp357_ = 3 * tmp258_;
   double tmp358_ = tmp357_ * tmp64_;
   double tmp359_ = tmp358_ * tmp67_;
   double tmp360_ = tmp356_ + tmp359_;
   double tmp361_ = (tmp45_) * (tmp70_);
   double tmp362_ = tmp43_ + tmp361_;

  mVal[0] = (mCompCoord[14] + (tmp260_) * tmp84_) - mLocMesIm_x;

  mCompDer[0][0] = (tmp60_ + (tmp60_) * (tmp70_) + (tmp269_) * (tmp37_)) * tmp84_;
  mCompDer[0][1] = (tmp96_ + (tmp96_) * (tmp70_) + (tmp278_) * (tmp37_)) * tmp84_;
  mCompDer[0][2] = (tmp121_ + (tmp121_) * (tmp70_) + (tmp287_) * (tmp37_)) * tmp84_;
  mCompDer[0][3] = (tmp150_ + (tmp150_) * (tmp70_) + (tmp296_) * (tmp37_)) * tmp84_;
  mCompDer[0][4] = (tmp178_ + (tmp178_) * (tmp70_) + (tmp305_) * (tmp37_)) * tmp84_;
  mCompDer[0][5] = (tmp206_ + (tmp206_) * (tmp70_) + (tmp314_) * (tmp37_)) * tmp84_;
  mCompDer[0][6] = (tmp222_ + (tmp222_) * (tmp70_) + (tmp323_) * (tmp37_)) * tmp84_;
  mCompDer[0][7] = (tmp237_ + (tmp237_) * (tmp70_) + (tmp332_) * (tmp37_)) * tmp84_;
  mCompDer[0][8] = (tmp248_ + (tmp248_) * (tmp70_) + (tmp341_) * (tmp37_)) * tmp84_;
  mCompDer[0][9] = (tmp351_ + (tmp350_) * (tmp37_)) * tmp84_;
  mCompDer[0][10] = (tmp360_) * (tmp37_) * tmp84_;
  mCompDer[0][11] = (tmp47_) * (tmp37_) * tmp84_;
  mCompDer[0][12] = tmp64_ * (tmp37_) * tmp84_;
  mCompDer[0][13] = tmp68_ * (tmp37_) * tmp84_;
  mCompDer[0][14] = 1;
  mCompDer[0][15] = 0;
  mCompDer[0][16] = tmp260_;
  mVal[1] = (mCompCoord[15] + (tmp362_) * tmp84_) - mLocMesIm_y;

  mCompDer[1][0] = (tmp80_ + (tmp80_) * (tmp70_) + (tmp269_) * (tmp45_)) * tmp84_;
  mCompDer[1][1] = (tmp106_ + (tmp106_) * (tmp70_) + (tmp278_) * (tmp45_)) * tmp84_;
  mCompDer[1][2] = (tmp131_ + (tmp131_) * (tmp70_) + (tmp287_) * (tmp45_)) * tmp84_;
  mCompDer[1][3] = (tmp160_ + (tmp160_) * (tmp70_) + (tmp296_) * (tmp45_)) * tmp84_;
  mCompDer[1][4] = (tmp188_ + (tmp188_) * (tmp70_) + (tmp305_) * (tmp45_)) * tmp84_;
  mCompDer[1][5] = (tmp216_ + (tmp216_) * (tmp70_) + (tmp314_) * (tmp45_)) * tmp84_;
  mCompDer[1][6] = (tmp229_ + (tmp229_) * (tmp70_) + (tmp323_) * (tmp45_)) * tmp84_;
  mCompDer[1][7] = (tmp242_ + (tmp242_) * (tmp70_) + (tmp332_) * (tmp45_)) * tmp84_;
  mCompDer[1][8] = (tmp252_ + (tmp252_) * (tmp70_) + (tmp341_) * (tmp45_)) * tmp84_;
  mCompDer[1][9] = (tmp350_) * (tmp45_) * tmp84_;
  mCompDer[1][10] = (tmp351_ + (tmp360_) * (tmp45_)) * tmp84_;
  mCompDer[1][11] = (tmp47_) * (tmp45_) * tmp84_;
  mCompDer[1][12] = tmp64_ * (tmp45_) * tmp84_;
  mCompDer[1][13] = tmp68_ * (tmp45_) * tmp84_;
  mCompDer[1][14] = 0;
  mCompDer[1][15] = 1;
  mCompDer[1][16] = tmp362_;
}


void cGeneratedCodeTestCam::ComputeValDerivHessian()
{
  ELISE_ASSERT(false,"Foncteur cGeneratedCodeTestCam Has no Der Sec");
}

void cGeneratedCodeTestCam::SetMesIm_x(double aVal){ mLocMesIm_x = aVal;}
void cGeneratedCodeTestCam::SetMesIm_y(double aVal){ mLocMesIm_y = aVal;}
void cGeneratedCodeTestCam::SetR0_0_0(double aVal){ mLocR0_0_0 = aVal;}
void cGeneratedCodeTestCam::SetR0_0_1(double aVal){ mLocR0_0_1 = aVal;}
void cGeneratedCodeTestCam::SetR0_0_2(double aVal){ mLocR0_0_2 = aVal;}
void cGeneratedCodeTestCam::SetR0_1_0(double aVal){ mLocR0_1_0 = aVal;}
void cGeneratedCodeTestCam::SetR0_1_1(double aVal){ mLocR0_1_1 = aVal;}
void cGeneratedCodeTestCam::SetR0_1_2(double aVal){ mLocR0_1_2 = aVal;}
void cGeneratedCodeTestCam::SetR0_2_0(double aVal){ mLocR0_2_0 = aVal;}
void cGeneratedCodeTestCam::SetR0_2_1(double aVal){ mLocR0_2_1 = aVal;}
void cGeneratedCodeTestCam::SetR0_2_2(double aVal){ mLocR0_2_2 = aVal;}



double * cGeneratedCodeTestCam::AdrVarLocFromString(const std::string & aName)
{
   if (aName == "MesIm_x") return & mLocMesIm_x;
   if (aName == "MesIm_y") return & mLocMesIm_y;
   if (aName == "R0_0_0") return & mLocR0_0_0;
   if (aName == "R0_0_1") return & mLocR0_0_1;
   if (aName == "R0_0_2") return & mLocR0_0_2;
   if (aName == "R0_1_0") return & mLocR0_1_0;
   if (aName == "R0_1_1") return & mLocR0_1_1;
   if (aName == "R0_1_2") return & mLocR0_1_2;
   if (aName == "R0_2_0") return & mLocR0_2_0;
   if (aName == "R0_2_1") return & mLocR0_2_1;
   if (aName == "R0_2_2") return & mLocR0_2_2;
   return 0;
}


cElCompiledFonc::cAutoAddEntry cGeneratedCodeTestCam::mTheAuto("cGeneratedCodeTestCam",cGeneratedCodeTestCam::Alloc);


cElCompiledFonc *  cGeneratedCodeTestCam::Alloc()
{  return new cGeneratedCodeTestCam();
}

