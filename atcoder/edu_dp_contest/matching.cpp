#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define mod ll(1e9 + 7)

int n;

int main(){
    cin >> n;
    vector<vector<bool>> comp(n, vector<bool>(n));
    for(int i = 0 ;i < n; i++) {
        for(int j = 0;j < n ;j++) {
            int temp;
            cin >> temp;
            comp[i][j] = temp;
        }
    }

    vector<ll> dp(1 << n);
    dp[0] = 1;
    for(int i = 0 ;i < (1 << n); i++) {
        int onecount = __builtin_popcount(i);
        
        for(int w = 0 ;w < n; w++) {
            if(i & (1 << w) || !comp[onecount][w]) {
                continue;
            }

            int cur = (i | 1 << w);
            dp[cur] += dp[i];
            dp[cur] %= mod;
        }
    }

    cout << dp[(1 << n) - 1] << endl;



}