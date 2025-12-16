#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n;
    cin >> n;
    vector<ll> prefxor(n + 1);
    vector<ll> v(n);
    prefxor[0] = 0;
    for(int i = 1;i <= n;i++) {
        cin >> v[i - 1];
        prefxor[i] = v[i - 1];
        prefxor[i] ^= prefxor[i - 1];
    }
    string bstring ;
    cin >> bstring;
    ll q;
    cin >> q;
    ll x0 = 0 , x1 = 0;
    vector<ll> binary(n);
    for(int i = 0;i < n ; i++) {
        binary[i] = bstring[i] - '0';
    }
    for(int i = 0 ;i < n;i++) {
        if(binary[i] == 0) {
            x0 ^= v[i];
        }
        else {
            x1 ^= v[i]; 
        }
    }
    for(int i = 0 ;i < q ;i++ ) {
        ll opp;
        cin >> opp;
        if(opp == 1) {
            ll l , r;
            cin >> l >> r;
            ll curchange = prefxor[r] ^ prefxor[l - 1];
            x1 ^= curchange;
            x0 ^= curchange;
        }
        else {
            ll num;
            cin >> num;
            if(num == 0) {
                cout << x0 << " ";
            }
            else {
                cout << x1 << " ";
            }
        }
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0 ;i < t; i++) {
        solve();
    }
}