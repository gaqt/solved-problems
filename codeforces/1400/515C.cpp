#include <bits/stdc++.h>
using namespace std;
    
    
int main() {
    int n;
    cin >> n;
    
    char c[n+1];
    
    scanf("%s", c);
    
    vector<int> num;
    
    for (int i = 0; i < n; i++) {
        switch(c[i]) {
            case '9':
                num.push_back(7);
                num.push_back(3);
                num.push_back(3);
                num.push_back(2);
                break;
            case '8':
                num.push_back(7);
                num.push_back(2);
                num.push_back(2);
                num.push_back(2);
                break;
            case '7':
                num.push_back(7);
                break;
            case '6':
                num.push_back(5);
                num.push_back(3);
                break;
            case '5':
                num.push_back(5);
                break;
            case '4':
                num.push_back(3);
                num.push_back(2);
                num.push_back(2);
                break;
            case '3':
                num.push_back(3);
                break;
            case '2':
                num.push_back(2);
                break;
            default:
                break;
        }
    }
    
    sort(num.rbegin(), num.rend());
    
    for (int i = 0; i < num.size(); i++) {
        cout << num[i];
    }
    
    
    return 0;
}