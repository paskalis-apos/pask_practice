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
    ll minlength = 1e18;
    ll l = 0;
    ll r = 0;
    while(r <= n){
        if(cursum >= s){
            minlength = min(minlength, r - l);
            cursum -= v[l];
            l++;
        }
        else {
            if(r < n) {
                cursum += v[r];
            }
            r++;
        }
    }
    if(minlength == 1e18) {
        minlength = -1;
    }
    cout << minlength << endl;
}