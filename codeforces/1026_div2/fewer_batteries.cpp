#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<pair<ll,ll>>> adj;
vector<ll> batrs;
ll maxbats = 0;
vector<ll> dp;
ll n , m;

bool valid(ll mid) {
    dp.assign(n, 0);
    for(int i = 0 ;i < n;i++) {
        if(dp[i] == 0 && i > 0) {
            continue;
        }
        dp[i] +=  batrs[i];
        dp[i] = min(mid, dp[i]);
        for(auto &x : adj[i]) {
            if(x.second <= dp[i]) {
                dp[x.first] = max(dp[x.first], dp[i]);
            }
        }
    }
    if(dp[n - 1] > 0) {
        return true;
    }
    return false;   
}

void solve() {
    cin >> n >> m;
    batrs.assign(n , 0);
    for(auto &x : batrs) {
        cin >> x;
    }
    adj.assign(n,{});
    for(ll i = 0; i < m; i++) {
        ll a, b , w;
        cin >> a >> b >> w;
        a--;
        b--;
        adj[a].push_back({b , w});
    }

    ll l = 0, r = 1e9 + 5;
    while(l < r) {
        ll mid = (l + r) / 2;
        if(valid(mid)) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    int ans;
    if(l == 1e9 + 5) {
        ans = -1;
    }
    else {
        ans = l;
    }

    cout << ans << endl;


}

int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t; i++) {
        solve();
    }
}