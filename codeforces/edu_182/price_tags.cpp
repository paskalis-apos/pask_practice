#include<bits/stdc++.h>
using namespace std;
using ll = long long;   

void solve() {
    ll n ,y;
    cin >> n >> y;
    int MAXNUM = 0;
    vector<int> pricecnt(2 * 1e5 + 10);
    for(int i = 0;i < n;i++) {
        int num;
        cin >> num;
        pricecnt[num]++;
        MAXNUM = max(MAXNUM, num + 1);
    }
    vector<int> pref(MAXNUM + 10);
    for(int i = 1;i <=MAXNUM; i++) {
        pref[i] = pref[i - 1] + pricecnt[i];
    }
    ll ans = -1e18;
    for(int i = 2;i <= MAXNUM; i++) {
        ll temp = 0;
        for(int j = 1; j <= MAXNUM / i + (MAXNUM % i != 0); j++) {
            // int becomej = pref[min(MAXNUM, i * j)] - pref[min(MAXNUM, i * (j - 1))];
            int becomej = pref[min(MAXNUM, i * j)] - pref[(i * (j - 1))];
            int tagsj = pricecnt[j];
            temp += (ll)becomej * j;
            if (becomej - tagsj > 0) {
            temp -= (ll)(becomej - tagsj) * y;
        }
            
        }
        ans = max(ans, temp);
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        solve();
    }
}