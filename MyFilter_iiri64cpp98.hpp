// filtername_iirXXXcpp98_hpp.txt template file, version: 01_02_01
// GENERATED FILE! MODIFY THIS FILE ONLY AT YOUR OWN RESPONSIBLITY!
// Header file of MyFilter C++98 IIR filter implementation with the datatype of long long
// File implements the following filter:
// INFINITE IMPULSE RESPONSE
// LOW PASS FILTER
// CHEBYSHEV APPROXIMATION
// A_s = -40.0 dB, d_r = 0.1
// f_sa = 16000.0 Hz
// f_c = 2000.0 Hz, f_s = 3000.0 Hz
// Requirement checksum: 4e7c287ac658902f6f571036d29ec519

// Created at unix time: 1613509730
// Designer DLL version: IIR_DESIGNER_01_01_02
// Licensed DLL user: Gabor Kiszely
// DLL license info: 2021_01_09
// Filter valid: True
// Validator DLL version: IIR_CPP98_VALIDATOR_01_02_01
// Result checksum: cd58a39575c71cd3cdec77c4bd71f689

#ifndef _MYFILTERIIRI64CPP_HPP_
#define _MYFILTERIIRI64CPP_HPP_

#include "iircpp98.hpp"
#include <vector>

class CMyFilterIirI64Cpp98
{
private:
    std::vector<CIirCpp98<long long>> m_iirSegments_vec;
    unsigned char m_bitShifter;
public:
    CMyFilterIirI64Cpp98();
    ~CMyFilterIirI64Cpp98();
    long long doFiltering(long long f_inputVal);
    void doRwdFiltering();
    long resetFilter();
};

#endif
