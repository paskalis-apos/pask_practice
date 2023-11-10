#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll n;
    cin >> n;
    vector<ll > a(n);
    vector<ll > b(n);
    ll mina = INT_MAX;
    ll minb = INT_MAX;
    ll asum = 0;
    ll bsum = 0;
    for(int i = 0 ;i < n; i++) {
        cin >> a[i];
        mina = min(mina , a[i]);
        asum += a[i];
    }
    for(int i =0 ;i < n; i++) {
        cin >> b[i];
        minb = min(minb , b[i]);
        bsum += b[i];
    }

    return min(bsum + mina * n, asum + minb * n);
}

int main() {
    int t;
    cin >> t;

    for(int i = 0;i < t;i++) {
        cout << solve() << endl;
    }
}