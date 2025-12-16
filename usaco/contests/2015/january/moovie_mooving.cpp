#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct mv {
    ll dur, num;
    vector<ll> times;
};

ll n , length;

int main() {
    freopen("movie.in","r",stdin);
    freopen("movie.out","w",stdout);
    cin >> n >> length;
    vector<mv>movies(n);
    vector<vector<ll>> times(n);
    for(int i = 0 ;i <n ;i++) {
        cin >> movies[i].dur >> movies[i].num;
        for(int j = 0 ;j < movies[i].num; j++) {
            ll temp;
            cin >> temp;
            times[i].push_back(temp);
        }
    }

    vector<ll> dp(1 << n);
    dp[0] = 0;
    int answer = INT_MAX;

    for(int bt = 1; bt < (1 << n); bt++) {
        for(int i =0 ;i < n; i++) {
            if((bt & (1 << i)) == 0) {
                continue;
            }
            int prebt = bt - (1 << i);
            ll prevreach = dp[prebt];
            if(upper_bound(times[i].begin(), times[i].end(), prevreach) != times[i].begin()) {
                ll nowjoin;
                nowjoin = *prev(upper_bound(times[i].begin(), times[i].end(), prevreach));
                dp[bt] = max(dp[bt], nowjoin + movies[i].dur);
            }
        }
        if(dp[bt] >= length) {
            answer = min(answer , __builtin_popcount(bt)); 
        }
    }

    if(answer == INT_MAX) {
        cout << -1 << endl;
        return 0;
    }
    cout << answer << endl;
}