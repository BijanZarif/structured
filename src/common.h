#ifndef _COMMON_H
#define _COMMON_H
#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)

#if defined(__ICC)
//#pragma message "__ICC is defined."
#define __COMPILER__ "INTEL"
#elif defined(__GNUC__)
//#pragma message "__GNUC__ is defined."
#define __COMPILER__ "GNU " STR(__GNUC__) "." STR(__GNUC_MINOR__) "." STR(__GNUC_PATCHLEVEL__)
#elif defined(__IBMC__)
//#pragma message "__IBMC__ is defined."
#define __COMPILER__ "IBM"
#endif

#include <omp.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <memory>
#include "thirdparty/cpptoml.h"
#include "thirdparty/cnpy.h"
#include "thirdparty/spdlog/spdlog.h"
#include "thirdparty/cmdline.h"
#include "thirdparty/rarray"
#include "thirdparty/rarrayio"

template<class T>
using Array3D = rarray<T, 3>;

template<class T>
using Array2D = rarray<T, 2>;

template<class T>
using Array1D = rarray<T, 1>;


constexpr auto GAMMA = 1.4;
#define PRINT_CONFIG(x)	logger->info(#x": {}", x);
#define MAX_NNZ 150




// #define ENABLE_EIGEN
// #define ENABLE_ARMA
// #define ENABLE_PETSC

#if defined(ENABLE_EIGEN) || defined(ENABLE_ARMA) || defined(ENABLE_PETSC)
#define ENABLE_ADOLC
#endif

#if defined(ENABLE_ADOLC)
#include "adolc/adolc.h"
#include "adolc/sparse/sparsedrivers.h"
#endif

#include <chrono>
class Timer {
public:
    Timer() {
        reset();
    }
    void reset() {
        m_timestamp = std::chrono::high_resolution_clock::now();
    }
    float diff() {
        std::chrono::duration<float> fs = std::chrono::high_resolution_clock::now() - m_timestamp;
        return fs.count();
    }
private:
    std::chrono::high_resolution_clock::time_point m_timestamp;
};

#endif
