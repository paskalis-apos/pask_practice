#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> v(2 * n);
    for(auto &x : v){ 
        cin >> x;
    }
    sort(v.begin(), v.end());
    vector<ll> ans(n + 2);
    ll sum = 0;
    for(int i = 0;i < 2 * n ;i++) {
        if(i < n) {
            sum -= v[i];
        }
        else {
            sum += v[i];
        }
    }
    ans[n] = ans[n + 1] = sum;
    for(int i = n - 1; i > 0; i--) {
        ans[i] = ans[i + 2] + 2 * (v[i] - v[2 *n - i - 1]);
    }

    for(int i = 1;i <= n;i++) {
        cout << ans[i] << " ";
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