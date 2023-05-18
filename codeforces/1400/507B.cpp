#include <bits/stdc++.h>
using namespace std;
    
int main() {
    double r,x,y,x1,y1;
    
    cin >> r >> x >> y >> x1 >> y1;
    
    double distance = sqrt(pow(x-x1, 2) + pow(y - y1, 2));
    
    if (distance - 2*r*floor(distance / (2*r)) == 0) {
        cout << floor(distance / (2*r));
    } else {
        cout << floor(distance / (2*r)) + 1;
    }
    
    
    
    return 0;
}