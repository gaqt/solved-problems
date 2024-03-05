// https://neps.academy/br/exercise/268
#include <cstdint>
#include <iostream>
#include <numeric>
using namespace std;

int main() {
    uint64_t a, b, c, d;
    cin >> a >> b >> c >> d;

    uint64_t den = lcm(b,d);
    uint64_t nom = den*a/b + den*c/d;
    uint64_t _gcd = gcd(nom, den);
    nom /= _gcd;
    den /= _gcd;

    printf("%ld %ld\n", nom, den);

    return 0;
}
