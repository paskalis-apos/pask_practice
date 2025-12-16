#include<bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    int n;
    cin >> n;
    vector<int> weights(n);
    for(auto &x : weights) {
        cin >> x;
    }

    ll ans = INT_MAX;

    for(int mask = 0 ;mask < (1 << n); mask++) {
        ll sum1 = 0;
        ll sum2 = 0;
        for(int i =0 ;i < n ;i++) {
            
            if(mask & (1 << i)) {
                sum1 += weights[i];
            }
            else {
                sum2 += weights[i];
            }
        }        
        ans = min(ans, abs(sum1 - sum2));
    }

    cout << ans;


}