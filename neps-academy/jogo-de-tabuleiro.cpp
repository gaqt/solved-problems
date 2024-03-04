// https://neps.academy/br/exercise/22
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int t[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> t[i][j];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            int x = t[i-1][j] + t[i][j-1] + t[i-1][j-1];
            if (x > 1)
                t[i][j] = 0;
            else
                t[i][j] = 1;
        }
    }

    cout << t[n-1][n-1] << endl;

    return 0;
}
