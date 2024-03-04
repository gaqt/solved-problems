// https://neps.academy/br/exercise/52
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a=0, b=0;

    while(n--) {
        int in;
        cin >> in;

        switch (in) {
            case 1:
                a = 1-a;
                break;
            case 2:
                a = 1-a;
                b = 1-b;
        }
    }

    cout << a << endl << b << endl;

    return 0;
}
