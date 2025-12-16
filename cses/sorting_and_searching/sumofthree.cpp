#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n ,x;
    cin >> n >> x;

    vector<pair<ll,ll>> v(n + 1);
    for(int i = 1 ;i <= n; i++) {
        cin >> v[i].first;
        v[i].second = i;
    }

    sort(v.begin(), v.end());
    for(int i = 1 ;i <= n ;i++) {
        ll sum = x - v[i].first;
        ll l = 1;
        ll r = n ;
        while(l < r) {
            if (l == i) {
                l++;
                continue;
            }
            if(r == i) {
                r--;
                continue;
            }
            if(v[r].first + v[l].first < sum) {
                l++;
            }

            else if(v[r].first + v[l].first > sum) {
                r--;
            }
            else {
                cout << v[l].second<< ' ' << v[r].second<<" " << v[i].second;
                return 0;
            }
            
        }
    }
    cout << "IMPOSSIBLE" << endl;
}