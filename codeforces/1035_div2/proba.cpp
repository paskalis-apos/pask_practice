#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll a , b , x , y;
    cin >> a >> b >> x >> y;
    if(b < a - 1 || b == a - 1 && a % 2 == 0){ 
        cout << -1 << endl;
        return;
    }
    if(b == a - 1) {
        cout << y << endl;
        return;
    }
    if(x <= y) {
        cout << (b - a) * x << endl;
        return;
    }
    if(a % 2 == 0) {
        ll ans;
        ans = (b - a ) / 2 * x + (b - a + 1) / 2 * y;
        cout << ans << endl;
        return;
    }
    ll ans;
    ans = (b - a) / 2* y + (b - a + 1) / 2 * x;
    cout << ans << endl;
    

}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        solve();
    }
}