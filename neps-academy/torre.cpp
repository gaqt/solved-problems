// https://neps.academy/br/exercise/45
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int og[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> og[i][j];
        }
    }

    int prex[n][n];
    int prey[n][n];

    for (int i = 0; i < n; i++)
        prex[0][i] = og[0][i];

    for (int i = 0; i < n; i++)
        prey[i][0] = og[i][0];

    for (int x = 1; x < n; x++) {
        for (int y = 0; y < n; y++) {
            prex[x][y] = prex[x-1][y] + og[x][y];
        }
    }

    for (int y = 1; y < n; y++) {
        for (int x = 0; x < n; x++) {
            prey[x][y] = prey[x][y-1] + og[x][y];
        }
    }

    int res = 0;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            int crr = -2*og[x][y];
            crr += prex[n-1][y];
            crr += prey[x][n-1];

            res = max(res, crr);
        }
    }

    cout << res << endl;

    return 0;
}
