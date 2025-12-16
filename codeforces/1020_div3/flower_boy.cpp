#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 10;

void solve() {
    int n ,m;
    cin >> n >> m;
    vector<int> v1(n), v2(m);
    for(auto &x : v1) {
        cin >> x;
    }
    for(auto &x : v2 ){
        cin >> x;
    }

    vector<int> pref(n + 1);
    vector<int> suf(n + 2);
    int bind = 0;
    for(int i = 1;i <= n;i++) {
        pref[i] = pref[i - 1];
        if(bind < m && v1[i - 1] >= v2[bind]) {
            bind++;
            pref[i]++;
        }
    }
    bind = m - 1;
    for(int i = n;i > 0; i--) {
        suf[i] = suf[i + 1];
        if(bind >= 0 && v1[i - 1] >= v2[bind]) {
            bind--;
            suf[i]++;
        }
    }
    int ans =INF;
    for(int i = 0;i <= n; i++) {
        if(pref[i] + suf[i + 1] >= m) {
            ans = 0;
            break;
        }
        else if(pref[i] + suf[i + 1] == m - 1) {
            ans = min(ans, v2[pref[i]]);
        }
    }

    if(ans == INF) {
        ans = -1;
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t ;i++) {
        solve();
    }
}