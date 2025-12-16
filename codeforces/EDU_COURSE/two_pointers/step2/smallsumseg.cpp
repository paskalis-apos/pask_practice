#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n , s;
    cin >> n >> s;
    vector<ll> v(n);
    for(auto &x : v) {
        cin >> x;
    }

    ll cursum = 0;
    ll maxlength = 0;
    ll l = 0;
    ll r = 0;
    while(r <= n){
        if(cursum <= s){
            maxlength = max(maxlength, r - l);
            if(r < n) {
                cursum += v[r];
            }
            r++;
        }
        else {
            cursum -= v[l];
            l++;
        }
    }

    cout << maxlength << endl;
}