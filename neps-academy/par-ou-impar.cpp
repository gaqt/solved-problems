// https://neps.academy/br/exercise/148
#include <iostream>
using namespace std;

int main() {
    int b, c;
    cin >> b >> c;

    if ((b+c)%2 == 0) {
        cout << "Bino";
    } else {
        cout << "Cino";
    }

    cout << endl;

    return 0;
}
