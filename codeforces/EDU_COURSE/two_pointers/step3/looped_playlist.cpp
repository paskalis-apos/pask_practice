#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n , p;
    cin >> n >> p;
    
    vector<ll> v(n);
    ll loopsum = 0;
    for(auto &x : v) {
        cin >> x;
        loopsum += x;
    }

    ll loops = p / loopsum;
    p = p % loopsum;


    for(int i = 0;i < n;i++) {
        v.push_back(v[i]);
    }
    ll cursum = 0;
    ll minlength = 1e18;
    ll ind = -1;
    ll l = 0;
    ll r= 0;


    while(r < 2 * n) {
        cursum += v[r];
        r++;
        while(l < 2 * n && cursum - v[l] >= p)  {
            cursum -= v[l];
            l++;
        }

        if(minlength > r - l && cursum >= p) {
            ind = l + 1;
            minlength = r - l;
        }
    }

    if(p == 0) {
        ind = 1;
    }
    cout << ind << " " << minlength +  loops * n<< endl;
}