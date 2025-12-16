#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    freopen("cowrun.in","r",stdin);
    freopen("cowrun.out","w",stdout);
    ll n;
    cin >> n;   
    vector<ll> small;
    vector<ll> big;
    for(ll i = 0 ;i < n; i++) {
        ll num;
        cin >> num;
        if(num < 0) {
            small.push_back(num);
        }
        else {
            big.push_back(num);            
        }
    }
    big.push_back(0);
    small.push_back(0);

    sort(big.begin(), big.end());
    sort(small.rbegin(), small.rend());

    vector<vector<ll>> dp1(small.size() , vector<ll>(big.size() ,1e9));
    vector<vector<ll>> dp2(small.size() , vector<ll>(big.size(), 1e9));

    dp1[0][0] = 0;
    dp2[0][0] = 0;

    for(ll range = 1; range <= n; range++) {
        for(ll left = 0; left <= range && left < small.size(); left++) {
            ll right = range - left;
            if(right >= big.size()) {
                continue;
            }
            ll cost = n - range + 1;
            if(left > 0) {
                dp1[left][right] = dp1[left - 1][right] + (small[left - 1] - small[left]) * cost; 
                dp1[left][right] = min(dp1[left][right], dp2[left - 1][right] + (big[right] - small[left]) * cost);
            }   
            if(right > 0) {
                dp2[left][right] = dp2[left][right - 1] + (big[right] - big[right - 1]) * cost;
                dp2[left][right] = min(dp2[left][right], dp1[left][right - 1] + (big[right]-  small[left]) * cost);
            }
        }
    }

    cout << min(dp1[small.size() - 1][big.size() - 1], dp2[small.size() - 1][big.size() - 1]) << endl;



}