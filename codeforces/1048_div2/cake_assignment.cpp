#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll k , x;
    cin >> k >> x;
    ll kk = 1ll << k;
    ll y = kk * 2 - x;
    vector<int> ans;
    while(x != y) {
        if(x < y) {
            y -= x;
            x *= 2;
            ans.push_back(1);
        }
        else {
            x -= y ;
            y *= 2;
            ans.push_back(2);
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(auto &x : ans) {
        cout << x << " ";
    }
    cout << endl;

}



int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t ;i++) {
        solve();
    }
}