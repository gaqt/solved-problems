#include <bits/stdc++.h>
using namespace std;
    
int main() {
    
    int T;
    cin >> T;
    
    while(T--) {
        double h, c, t;
        cin >> h >> c >> t;
        if (t <= (h+c)/2) cout << 2 << endl;
        else if (t >= h) cout << 1 << endl;
        else {
            double l=0, r=1e9, mid;
            double minDist = 1e9;
            long minX = 0;
            while (r - l > 1.0) {
                mid = (l+r)/2;
    
                double val = ((round(mid))*h + (round(mid)-1.0)*c)/(2.0*round(mid) - 1.0);
                double dist = t - val;
    
                if (abs(dist) == minDist) if(round(mid) < minX) minX = round(mid);
                if (abs(dist) < minDist) {minX = round(mid); minDist = abs(dist);}
    
                if (dist <= 0) l = mid;
                else r = mid;
            }
    
            cout << 2*minX-1 << endl;
        }
    }
    
    return 0;
}