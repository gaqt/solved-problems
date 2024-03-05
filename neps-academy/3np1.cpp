#include <iostream>
using namespace std;

long _apply(long crr, long depth) {
    if (crr == 1) return depth;

    if (crr%2 == 0)
        return _apply(crr/2, depth+1);
    else
        return _apply(3*crr+1, depth+1);
}

long apply(long num) {
    return _apply(num, 1);
}

int main() {
    int n;
    cin >> n;
    cout << apply(n) << endl;
}
