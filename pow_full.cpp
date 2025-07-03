#include "pow.h"
#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;

cpp_int big_pow(cpp_int base, unsigned long long power) {
    cpp_int result = 1;
    while (power > 0) {
        if (power & 1)
            result *= base;
        base *= base;
        power >>= 1;
    }
    return result;
}
