// filtername_iirXXXcpp98_cpp.txt template file, version: 01_02_01
// GENERATED FILE! MODIFY THIS FILE ONLY AT YOUR OWN RESPONSIBLITY!
// Code file of MyFilter C++98 IIR filter implementation with the datatype of long long
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

#include "MyFilter_iiri64cpp98.hpp"

CMyFilterIirI64Cpp98::CMyFilterIirI64Cpp98()
{
    m_iirSegments_vec.clear();
    m_iirSegments_vec.assign({
        CIirCpp98<long long>(CIirCoeffs<long long>(static_cast<long long>(103038), static_cast<long long>(-42600), static_cast<long long>(1274), static_cast<long long>(2549), static_cast<long long>(1274))),
        CIirCpp98<long long>(CIirCoeffs<long long>(static_cast<long long>(93976), static_cast<long long>(-48960), static_cast<long long>(5130), static_cast<long long>(10260), static_cast<long long>(5130))),
        CIirCpp98<long long>(CIirCoeffs<long long>(static_cast<long long>(88090), static_cast<long long>(-59338), static_cast<long long>(9196), static_cast<long long>(18392), static_cast<long long>(9196))),
        });
    m_bitShifter = 16;
}

CMyFilterIirI64Cpp98::~CMyFilterIirI64Cpp98()
{
    m_iirSegments_vec.clear();
}

long CMyFilterIirI64Cpp98::resetFilter()
{
    long l_retVal = RETURN_ERROR;
    std::vector<CIirCpp98<long long>>::iterator l_iirSegments_itr = m_iirSegments_vec.begin();
    while (l_iirSegments_itr != m_iirSegments_vec.end())
    {
        l_retVal = l_iirSegments_itr->resetFilter();
        if (RETURN_ERROR == l_retVal)
        {
            return(l_retVal);
        }
        l_iirSegments_itr++;
    }
    return(l_retVal);
}

// Function calculates the output value
long long CMyFilterIirI64Cpp98::doFiltering(long long f_inputVal)
{
    long long l_retVal = f_inputVal;
    std::vector<CIirCpp98<long long>>::iterator l_iirSegments_itr = m_iirSegments_vec.begin();
    while (l_iirSegments_itr != m_iirSegments_vec.end())
    {
        l_retVal = (l_iirSegments_itr->doFiltering(l_retVal) >>= m_bitShifter);
        l_iirSegments_itr++;
    }
    return(l_retVal);
}

// Function calculates the rewards calculations of the filter
// This function can be called in a parallel thread, started immediatelly after the doFiltering function
// Calculations must be done before the next call of doFiltering
void CMyFilterIirI64Cpp98::doRwdFiltering()
{
    std::vector<CIirCpp98<long long>>::iterator l_iirSegments_itr = m_iirSegments_vec.begin();
    while (l_iirSegments_itr != m_iirSegments_vec.end())
    {
        l_iirSegments_itr->doRwdFiltering();
        l_iirSegments_itr++;
    }
}

