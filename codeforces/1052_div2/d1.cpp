#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){ 
    int l, r;
    cin >> l >> r;
    map<int,int> together;
    vector<int> ans(r + 1);
    for(int i = r; i >= 0; i--) {
        int temp = 0;
        if(together[i]) {
            ans[i] = together[i];
            continue;
        }
        for(int j = 0;(1 << j) <= i; j++) {
            if(((1 << j) & i) == 0) {
                temp += (1 << j);
            }
        }
        together[temp] = i;
        ans[i] = temp;
    }

    ll sum = 0;
    for(int i = 0;i <= r; i++) {
        sum += (ans[i] | i);
    }
    cout << sum << endl;
    
    for(auto &x : ans ) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t;i++) {
        solve();
    }
}