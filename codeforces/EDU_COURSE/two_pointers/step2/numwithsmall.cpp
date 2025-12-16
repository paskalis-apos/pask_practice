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

    int l = 0 ;
    int r = 0;
    ll smallsegs = 0;
    ll cursum = 0;
    while(r < n) {
        cursum += v[r];
        while(cursum > s) {
            cursum -= v[l];
            l++;
        }
        r++;
        smallsegs += r - l;
    }

    cout << smallsegs << endl;
}