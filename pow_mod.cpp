#include "pow.h"

static const int64_t MOD = 1000000000;

int64_t power(int64_t base, int64_t exp) {
    int64_t result = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return result;
}
