#include<bits/stdc++.h>
using namespace std;
using ll = long long;


void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    vector<vector<int>> pref(2, vector<int>(n + 1));
    vector<int> sametwo(n);
    int ind = 1;
    for(auto &x : v) {
        cin >> x;
        pref[0][ind] = pref[0][ind - 1];
        pref[1][ind] = pref[1][ind - 1];
        pref[0][ind] += (x == 0);
        pref[1][ind] += (x == 1);
        ind++;
    }

    for(int i = 1;i < n;i++) {
        sametwo[i] = sametwo[i - 1];
        if(v[i] == v[i - 1]) {
            sametwo[i]++;
        }
    }

    for(int i = 0;i < q ;i++) {
        int l, r;
        cin >> l >> r;
        int sum1 = pref[0][r] - pref[0][l - 1] ;
        int sum2 =  pref[1][r] - pref[1][l - 1] ;
        if(sum1 % 3 != 0 ||  sum2 % 3 != 0) {
            cout << -1 << endl;
            continue;
        }
        int ans = sum1 / 3 + sum2 / 3;
        if(sametwo[r - 1] - sametwo[l - 1] == 0) {
            ans++;
        }

        cout << ans << endl;
        
    }





}

int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t; i++) {
        solve();
    }
}