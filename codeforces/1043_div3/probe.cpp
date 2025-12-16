#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n , m, q;
    cin >> n >> m >> q;
    vector<int> v1(n);
    vector<int> v2(m);
    vector<ll> pref1(n + 1);
    vector<ll> pref2(m + 1);
    for(int i = 0 ;i < n ;i++) {
        cin >> v1[i];
    }
    for(int i = 0 ;i < m; i++ ) {
        cin >> v2[i];
    }

    sort(v1.rbegin(), v1.rend()); 
    sort(v2.rbegin(), v2.rend());
    for(int i = 0 ;i < n ;i++) {
        pref1[i + 1] = pref1[i] + v1[i];
    }
    for(int i = 0 ;i < m; i++ ) {
        pref2[i + 1] = pref2[i] + v2[i];
    }
    int ind1 = 0, ind2 = 0;
    vector<pair<int,int>> best(n + m + 1);
    for(int i = 0 ;i < n + m;i++) {
        if(ind1 < n && (ind2 >= m || v1[ind1] > v2[ind2])) {
            ind1++;
        }
        else {
            ind2++;
        }
        best[i + 1] = {ind1, ind2};
    }

    for(int i = 0 ; i < q; i++) {
        int x , y , z;
        cin >> x >> y >> z;
        ind1 = best[z].first;
        ind2 = best[z].second;
        if(ind1 > x) {
            ind2 += ind1 - x;
            ind1 = x;
        }
        else if(ind2 > y) {
            ind1 += ind2 - y;
            ind2 = y;
        }
        cout << pref1[ind1] + pref2[ind2] << endl;
    }

}

int main() {
    int t;
    cin >> t;
    for(int i = 0 ;i < t;i++) {
        solve();
    }
}