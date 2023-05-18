#include <bits/stdc++.h>
using namespace std;
    
struct pos {
    int x,y;
};
    
int main() {
    
    int n, x0, y0;
    
    cin >> n >> x0 >> y0;
    
    vector<pos> storm;
    
    for (int i = 0; i < n; i++) {
        int x,y;
        
        cin >> x >> y;
    
        pos p;
        p.x = x;
        p.y = y;
    
        storm.push_back(p);
    }
    
    int shots = 0;
    
    while (!storm.empty()) {
        pos a = storm[storm.size()-1];
        storm.pop_back();
    
        for (int i = 0; i < storm.size(); i++) {
            pos b = storm[i];
    
            if ( (a.x - x0)*(b.y - y0) == (b.x - x0)*(a.y - y0) ) {
                storm.erase(storm.begin()+i);
                i--;
            }
        }
        shots++;
    }
    
    cout << shots;
    
    return 0;
}