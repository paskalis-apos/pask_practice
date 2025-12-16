#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define TOMOD ll(1e9 + 7)

ll exponent(ll a , ll b, ll mod) {
    if(b == 0) {
        return 1;
    }
    ll res = exponent(a , b / 2, mod);
    res *= res;
    res %= mod;
    if(b % 2 == 1) {
        res *= a ;
    }
    res %= mod;
    return res;
}

void solve() {
    ll a , b , c;
    cin >> a >> b >> c;

    b = exponent(b , c, TOMOD - 1);
    ll answer = exponent(a , b, TOMOD);

    cout << answer << endl;
}

int main() {
    int n;
    cin >> n;
    for(int i =0 ;i < n; i++) {
        solve();
    }
}