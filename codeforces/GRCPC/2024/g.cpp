#include<bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, t;
    cin >> n >> t;
    int ans = 0;
    vector<pair<int,int>> flights(n + 1);
    for(int i = 1;i <= n;i++) {
        int time , b , c;
        cin >> time >> b >> c;
        ans += c;
        flights[i].first = time;
        flights[i].second = b - c;
    }
    vector<int> dp(n + 1);
    dp[0] = 0;
    int ind = 0;
    for(int i = 1;i <= n;i++) {
        while(ind < n && flights[ind + 1].first <= flights[i].first - t) {
            ind++;
        }
        dp[i] = max(dp[i - 1], dp[ind] + flights[i].second);
    }

    ans += dp[n];
    cout << ans << endl;
}   