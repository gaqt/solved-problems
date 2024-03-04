// https://neps.academy/br/exercise/236
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int sq[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> sq[i][j];
        }
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += sq[0][i];

    for (int x = 0; x < n; x++) {
        int a=0, b=0, c=0, d=0;
        for (int y = 0; y < n; y++) {
            a += sq[x][y];
            b += sq[y][x];
        }

        if (a != sum || b != sum) {
            cout << -1 << endl;
            return 0;
        }
    }

    int c=0, d=0;
    for (int x = 0; x < n; x++) {
        c += sq[x][x];
        d += sq[n-x-1][x];
    }

    if (c != sum || d != sum) {
        cout << -1 << endl;
        return 0;
    }

    cout << sum << endl;

    return 0;
}
