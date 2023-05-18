#include <bits/stdc++.h>
using namespace std;
    
int main() {
        int A, B, res = 0;
        cin >> A >> B;
        while(A > -1 && B > -1) {
            res++;
            if(A > B) {
                    A-=2;
                    B--;
            } else {
                    A--;
                    B-=2;
            }
        }
        cout << --res;
        return 0;
}