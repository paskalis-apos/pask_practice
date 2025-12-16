#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){ 
    ll x, y;
    cin >> x >> y;

    if(x < y) {
        cout << 2 << endl;
        return;
    }
    if(x <= y + 1 || y == 1) {
        cout << -1 << endl;
        return;
    }
    cout << 3 << endl;
    }


int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t ;i++) {
        solve();
    }
}