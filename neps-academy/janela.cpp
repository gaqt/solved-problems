// https://neps.academy/br/exercise/510
#include <iostream>
using namespace std;

int main() {
    int width = 200, height = 100;

    int f1, f2, f3;
    cin >> f1 >> f2 >> f3;

    int p1 = min(f1,min(f2,f3));
    int p3 = max(f1,max(f2,f3));
    int p2 = (f1+f2+f3) - (p1+p3);

    int total = 0;

    // intersection width
    total += max(0, p1+width - p2);
    total += max(0, p2+width - p3);

    total *= height;

    cout << total << endl;

    return 0;
}
