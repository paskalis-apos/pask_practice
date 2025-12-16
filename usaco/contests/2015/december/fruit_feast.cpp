#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("feast.in","r",stdin);
    freopen("feast.out","w",stdout);
    int t, a, b;
    cin >> t >> a >> b;

    vector<bool> dp1(t + 1);
    vector<bool> dp2(t + 1);

    dp1[0] = true;

    for(int i = 0 ;i <= t; i++) {
        if(dp1[i] == true) {
            if(i + a <= t) {
                dp1[i + a] = true;
            }
            if(i + b <= t) {
                dp1[i + b] = true;
            }
            dp2[i / 2] = true;
        }
    }
    for(int i = 0 ;i < t;i++) {
        if(dp2[i] == true) {
            if(i + a <= t) {
                dp2[i + a] = true;
            }
            if(i + b <= t) {
                dp2[i + b] = true;
            }
        }
    }

    for(int i = t; i >= 0; i--) {
        if(dp1[i] || dp2[i]) {
            cout << i << endl;
            break;
        }
    }
    
}