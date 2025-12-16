#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool valid(ll num, vector<vector<ll>> &pref, ll n , ll m , ll k) {
    for(int i = 1 ;i <= n ;i++) {
        for(int j = 1; j <= m ;j++) {
            if(pref[i][j] == pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1]) {
                continue;
            }
            ll maxfirst = min(n , i + num);
            ll maxsecond = min(m , j + num);
            ll minfirst = max(ll(0), i - num - 1);
            ll minsecond = max(ll(0), j - num - 1);

            ll total = pref[maxfirst][maxsecond] - pref[maxfirst][minsecond] - pref[minfirst][maxsecond] + pref[minfirst][minsecond] - 1;
            if(total >= k) {
                return true;
            }

        }
    }
    return false;

}

void solve() {
    ll n , m , k;
    cin >> n >> m >> k;

    vector<vector<ll>>pref(n + 1,vector<ll>(m + 1));

    for(int i = 1 ;i <= n ;i++) {
        for(int j = 1 ;j <= m; j++) {
            ll temp;
            cin >> temp;
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i -1][j-1] + temp;
        }
    }

    int l = 0 , r = max(m , n);
    if (valid (r, pref, n , m , k) == false) {
        cout << - 1 << endl;
        return;
    }
    while (l < r) {
        int mid = (l + r) / 2;
        if(valid(mid, pref , n , m , k)) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    
    cout << l << endl;

}

int main() {
    int t; 
    cin >> t;
    for(int i = 0 ;i < t;i++) {
        solve();
    }
}