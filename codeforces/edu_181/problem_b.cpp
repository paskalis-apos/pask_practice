#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll a, b ,k;
    cin >> a >> b >> k;

    ll tempa = a / gcd(a , b);
    ll tempb = b / gcd(a , b);
    if(tempa <= k && tempb <= k) {
        cout << 1;
    }
    else {
        cout << 2 ;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        solve();
    }
}