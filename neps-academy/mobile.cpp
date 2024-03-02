// https://neps.academy/br/exercise/50
#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    bool c1 = a == b + c + d;
    bool c2 = d == b + c;
    bool c3 = b == c;

    if (c1 && c2 && c3) {
        cout << "S";
    } else {
        cout << "N";
    }

    cout << endl;

    return 0;
}
