// https://neps.academy/br/exercise/158
#include <cstdint>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    uint64_t fact = 1;
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }

    cout << fact << endl;

    return 0;
}
