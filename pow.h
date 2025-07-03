#pragma once
#include <cstdint>

#ifdef USE_BIGINT
    #include <boost/multiprecision/cpp_int.hpp>
    boost::multiprecision::cpp_int big_pow(boost::multiprecision::cpp_int base, unsigned long long power);
    #define power big_pow
#else
    int64_t power(int64_t base, int64_t exp);
#endif
