// https://neps.academy/br/exercise/980
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int req[2] = { 0 };

    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        req[t-1]++;
    }

    int tot[2];
    cin >> tot[0] >> tot[1];

    if (tot[0] < req[0] || tot[1] < req[1])
        cout << "N";
    else
        cout << "S";

    cout << endl;

    return 0;
}
