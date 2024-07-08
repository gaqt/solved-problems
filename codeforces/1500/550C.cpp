// https://codeforces.com/problemset/problem/550/C

#include <iostream>
using namespace std;

void yes(int x) {
    cout << "YES" << endl;
    cout << x << endl;
}

int main() {
    string s;
    cin >> s;

    int n = s.length();


    for (int a = 0; a < n; a++) {
        int x = s[a] - '0';

        if (x % 8 == 0) {
            yes(x);
            return 0;
        }

        for (int b = a+1; b < n; b++) {
            x = 10 * (s[a] - '0') +
                1 * (s[b] - '0');

            if (x % 8 == 0) {
                yes(x);
                return 0;
            }

            for (int c = b+1; c < n; c++) {
                x = 100 * (s[a] - '0') +
                    10 * (s[b] - '0') +
                    1 * (s[c] - '0');

                if (x % 8 == 0) {
                    yes(x);
                    return 0;
                }
            }
        }
    }

    cout << "NO" << endl;

    return 0;
}
