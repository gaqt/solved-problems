// https://neps.academy/br/exercise/1170
#include <iostream>
using namespace std;

#define SIDE 10

int main() {
    int n;
    cin >> n;

    bool t[SIDE+2][SIDE+2];


    for (int i = 0; i < SIDE+2; i++) {
        for (int j = 0; j < SIDE+2; j++)
            t[i][j] = true;
    }

    for (int i = 1; i < SIDE+1; i++) {
        for (int j = 1; j < SIDE+1; j++)
            t[i][j] = false;
    }

    bool valid = true;
    while(n--) {
        int d, l, r, c;
        cin >> d >> l >> r >> c;
        if (!valid) continue;

        for (int k = 0; k < l; k++)  {
            int rn = r + k*d;
            int cn = c + k*(1-d);

            if (t[rn][cn])
                valid = false;
            else
                t[rn][cn] = true;
        }
    }

    if (valid)
        cout << "Y";
    else
        cout << "N";

    cout << endl;
}
