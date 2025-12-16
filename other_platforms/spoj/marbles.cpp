#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll comb(ll n , ll k) {
    if(k > n - k) {
        k = n - k;
    }
    ll ret = 1;
    for(int i = 0;i < k ;i++) {
        ret = ret * (n - i) / (i + 1);
    }
    return ret;
}
void solve() {
    ll n , k;
    cin >> n >> k;
    cout << comb(n - 1, k - 1) << endl;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0 ;i < t ;i++) {
        solve();
    }
}