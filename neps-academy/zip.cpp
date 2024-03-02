// https://neps.academy/br/exercise/35
#include <iostream>
using namespace std;

int calc_total(int a, int b) {
    if (a == b)
        return 2*(a+b);
    else if (abs(a-b) == 1)
        return 3*(a+b);
    else
        return a+b;
}

int main() {
    int l1, l2, c1, c2;
    cin >> l1 >> l2 >> c1 >> c2;

    int l_total = calc_total(l1, l2);
    int c_total = calc_total(c1, c2);

    if (l_total == c_total) {
        cout << "empate";
    } else if (l_total > c_total) {
        cout << "Lia";
    } else {
        cout << "Carolina";
    }

    cout << endl;

    return 0;
}
