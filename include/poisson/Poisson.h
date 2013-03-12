#ifndef __POISSON_H__
#define __POISSON_H__

//Poisson
#ifdef _WIN32
    #ifdef INT
        #undef INT
    #endif
    #include <Windows.h>
    #include <Psapi.h>
#endif // _WIN32

#include "poisson/Time.h"

#include <sys/timeb.h>

#ifndef WIN32
#include <sys/time.h>
#endif

#if defined __GNUC__
    #pragma GCC system_header
#elif defined __SUNPRO_CC
    #pragma disable_warn
#elif defined _MSC_VER
    #pragma warning(push, 1)
#endif

#include "poisson/CmdLineParser.h"
#include "poisson/Factor.h"
#include "poisson/Geometry.h"
#include "poisson/MarchingCubes.h"
#include "poisson/Octree.h"
#include "poisson/SparseMatrix.h"
#include "poisson/CmdLineParser.h"
#include "poisson/Polynomial.h"
#include "poisson/PPolynomial.h"
#include "poisson/MemoryUsage.h"
//#include "poisson/omp.h"
#include "poisson/ply.h"
#include "poisson/PlyFile.h"
//#include "poisson/MultiGridOctreeData.h"

// #ifdef LoadImage
// 	//#undef LoadImage 
// #endif

#ifndef INT
	#define INT int
#endif

#endif __POISSON_H__
