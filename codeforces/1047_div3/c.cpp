#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll a , b;
    cin >> a >> b;
    ll starb = b;

    a = a * b;
    b = 1;
    if(a % 2 == 1) {
        cout << a + b << endl;
        return;
    }
    a /= 2;
    b *= 2;
    if(a % 2 == 1 || starb % 2 == 1) {
        cout << -1 << endl;
        return;
    }
    cout << a + b << endl;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0;i< t; i++) {
        solve();
    }
}