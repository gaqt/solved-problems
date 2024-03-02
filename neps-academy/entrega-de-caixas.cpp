// https://neps.academy/br/exercise/891
#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int m1 = min(a,min(b,c));
    int m3 = max(a,max(b,c));
    int m2 = (a+b+c) - (m1+m3);

    if (m1 != m2 && m2 != m3)
        cout << 1;
    else if (m1 + m2 < m3)
        cout << 1;
    else if ((m1==m2) != (m2==m3)) // XOR
        cout << 2;
    else
        cout << 3;

    cout << endl;

    return 0;
}
