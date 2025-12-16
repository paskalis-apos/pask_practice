#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for(auto &x : v) {
        cin >> x;
    }

    ll answer = 0;

    for(int bit = 0; bit <= 30; bit++) {
        ll p = 1 << bit;

        ll pref = 0;
        ll count0 = 1, count1 = 0;
        int oldpref = 0;
        int minus = 0;
        for(int i = 0;i < n ;i++) {
            ll bitvalue = (v[i] & p) ? 1 : 0;
            pref ^= bitvalue;
            if(pref != oldpref) {
                minus++;
                oldpref = pref;
            }
            if(pref == 0) {
                count0++;
            }
            else {
                count1++;
            }
        }
        
        ll diff = count1 * count0;
        diff -= minus;
        answer += diff * p;
    }
    cout << answer << endl;


}