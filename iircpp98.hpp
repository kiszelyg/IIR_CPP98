// iircpp98_hpp.txt template file, version: 01_02_01
// GENERATED FILE! MODIFY THIS FILE ONLY AT YOUR OWN RESPONSIBLITY!
// Header file of a general C++98 IIR filter implementation

#ifndef _IIRCPP98_HPP_
#define _IIRCPP98_HPP_

#include <vector>

#define RETURN_OK 0
#define RETURN_ERROR -1

template <typename T>
class CIirCoeffs
{
public:
    T m_a1;
    T m_a2;
    T m_b0;
    T m_b1;
    T m_b2;

    CIirCoeffs()
    {
    }

    CIirCoeffs(T f_a1, T f_a2, T f_b0, T f_b1, T f_b2)
    {
        m_a1 = f_a1;
        m_a2 = f_a2;
        m_b0 = f_b0;
        m_b1 = f_b1;
        m_b2 = f_b2;
    }
};

template <typename T>
class CIirCpp98
{
private:
    CIirCoeffs<T> m_coeffs;
    unsigned char m_n;
    T m_x; // filter input
    T m_y; // filter output
    std::vector<T> m_t1_vec;
    std::vector<T> m_t2_vec;

public:
    CIirCpp98(const CIirCoeffs<T>& f_coeffs)
    {
        m_n = 0;
        m_x = static_cast<T>(0.0); // filter input
        m_y = static_cast<T>(0.0); // filter output
        m_t1_vec = { static_cast<T>(0.0), static_cast<T>(0.0) };
        m_t2_vec = { static_cast<T>(0.0), static_cast<T>(0.0) };
        m_coeffs = f_coeffs;
    }

    long resetFilter()
    {
        m_n = 0;
        m_x = static_cast<T>(0.0); // filter input
        m_y = static_cast<T>(0.0); // filter output
        m_t1_vec = { static_cast<T>(0.0), static_cast<T>(0.0) };
        m_t2_vec = { static_cast<T>(0.0), static_cast<T>(0.0) };
        return RETURN_OK;
    }

    T& doFiltering(T f_inputVal)
    {
        m_x = f_inputVal;
        m_y = m_coeffs.m_b0 * m_x + m_t1_vec[(m_n + 1) % 2];
        return m_y;
    }

    void doRwdFiltering()
    {
        T l_xB1 = m_coeffs.m_b1 * m_x;
        T l_xB2 = m_coeffs.m_b2 * m_x;
        T l_yA1 = m_coeffs.m_a1 * m_y;
        T l_yA2 = m_coeffs.m_a2 * m_y;
        m_t1_vec[m_n % 2] = l_xB1 + m_t2_vec[(m_n + 1) % 2] + l_yA1;
        m_t2_vec[m_n % 2] = l_xB2 + l_yA2;
        m_n++;
        m_n %= 2;
    }

    ~CIirCpp98()
    {
    }
};

#endif
