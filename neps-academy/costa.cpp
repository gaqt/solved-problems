// https://neps.academy/br/exercise/329
#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> m >> n;

    int c[n+2][m+2];

    for (int i = 0; i < n+2; i++) {
        for (int j = 0; j < m+2; j++) {
            c[i][j] = '.';
        }
    }

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++)
            c[i+1][j+1] = s[j];
    }

    int res = 0;

    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < m+1; j++) {
            if (c[i][j] != '#') continue;

            if (c[i-1][j] == '.' ||
                c[i+1][j] == '.' ||
                c[i][j-1] == '.' ||
                c[i][j+1] == '.') {

                res++;
            }
        }
    }

    cout << res << endl;

    return 0;
}
