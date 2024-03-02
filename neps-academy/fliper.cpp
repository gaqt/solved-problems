// https://neps.academy/br/exercise/87
#include <iostream>
using namespace std;

int main() {
    int p, r;
    cin >> p >> r;

    if (p == 0) {
        cout << "C" << endl;
        return 0;
    }

    // Sabemos que p = 1
    if (r == 0) {
        cout << "B" << endl;
    } else {
        cout << "A" << endl;
    }

    return 0;
}
