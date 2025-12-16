#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v) {
        cin >> x;
    }
    vector<map<int,int>> maxsize(n);
    for(int i = 0;i < n ;i++) {
        maxsize[i][v[i]] = 1;
    }

    for(int i = 1;i < n;i++) {
        for(auto [GCD , size] : maxsize[i - 1]) {
            int newgcd = gcd(GCD , v[i]);
            maxsize[i][newgcd] = max(maxsize[i][newgcd], size + 1);
        }
    }

    vector<int> ans(n + 1);
    for(int i = 0 ;i < n; i++) {
        for(auto [gcd , size] : maxsize[i]) {
            ans[size] = max(ans[size], gcd);
        }
    }

    for(int i = 1;i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;


}

int main(){
    int t;
    cin >> t;
    for(int i = 0 ;i < t ;i++) {
        solve();
    }
}