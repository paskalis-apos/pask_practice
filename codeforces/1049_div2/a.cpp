#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int zerocount = 0;
    string bs;
    cin >> bs;
    for(auto &x : bs) {
        x -= '0';
        if( x== 0) {
            zerocount++;
        }
    }
    int ans = 0;
    for(int i = 0;i < zerocount; i++) {
        if(bs[i] == 1){
            ans++;
        }
    }

    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t; i++) {
        solve();
    }
}