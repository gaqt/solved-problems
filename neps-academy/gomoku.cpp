// https://neps.academy/br/exercise/37
#include <iostream>
using namespace std;

int main() {
    int n = 15;

    int t[n+10][n+10];

    for (int i = 0; i < n+10; i++) {
        for (int j = 0; j < n+10; j++)
            t[i][j] = 0;
    }

    for (int i = 5; i < n+5; i++) {
        for (int j = 5; j < n+5; j++)
            cin >> t[i][j];
    }

    for (int i = 5; i < n+5; i++) {
        for (int j = 5; j < n+5; j++) {
            int center = t[i][j];
            if (center == 0) continue;

            bool valid0 = true;
            bool valid1 = true;
            bool valid2 = true;
            bool valid3 = true;
            for (int k = 1; k < 5; k++) {
                if (t[i][j+k] != center) valid0 = false;
                if (t[i+k][j] != center) valid1 = false;
                if (t[i+k][j+k] != center) valid2 = false;
                if (t[i+k][j-k] != center) valid3 = false;
            }

            if (valid0 || valid1 || valid2 || valid3) {
                cout << center << endl;
                return 0;
            }
        }
    }

    cout << 0 << endl;

    return 0;
}
