#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll n , p , k;
int main() {
    cin >> n >> p >> k;
    vector<pair<ll,ll>> audpoints(n);
    for(int i = 0 ;i < n ;i++) {
        audpoints[i].second = i;
        cin >> audpoints[i].first;
    }
    sort(audpoints.rbegin(), audpoints.rend());
    vector<vector<ll>> pospoints(p , vector<ll>(n));
    for(int i = 0 ;i < n ; i++) {
        for(int j = 0;j < p ;j++) {
            cin >> pospoints[j][i];
        }
    }

    vector<vector<ll>>dp(n + 1, vector<ll>(1 << p));

    
    for(int i = 1 ;i <= n ;i++) {
        ll curpers = audpoints[i - 1].second;
        ll curaud = audpoints[i - 1].first;
        for(int bt = 0; bt < (1 << p); bt++) {
            if(__builtin_popcount(bt) > i) {
                continue;   
            }
            for(int j = 0 ;j < p ;j++) {
                if(!(bt & (1 << j))) {
                    continue;
                }
                ll cur = (bt - (1 << j));
                dp[i][bt] = max(dp[i][bt], dp[i - 1][cur] + pospoints[j][curpers]);
            }
            if(__builtin_popcount(bt) == i) {
                continue;
            }
            dp[i][bt] = max(dp[i][bt] , dp[i - 1][bt]);

            ll onecount = __builtin_popcount(bt);
            if(i - onecount <= k) {
                dp[i][bt] = max(dp[i][bt], dp[i - 1][bt]  + curaud);
            }
        }
    }


    ll answer = dp[n][(1 << p) - 1];
    cout << answer << endl;
}