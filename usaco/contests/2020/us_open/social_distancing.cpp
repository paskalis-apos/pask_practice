#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll n , m;
vector<pair<ll,ll>> intervs;

bool valid(ll num) {
    ll cownum = 0;
    ll counter = 0;
    ll loc = -1e18;
    while(counter < m && cownum < n) {
        if((loc + num) <= intervs[counter].first) {
            loc = intervs[counter].first;
            cownum++;
        }
        else if(loc + num <= intervs[counter].second) {
            loc = loc + num;
            cownum++;
        }
        else {
            counter++;
        }
    }
    if(cownum >= n) {
        return true;
    }
    return false;
}

int main() {
    freopen("socdist.in","r",stdin);
    freopen("socdist.out","w",stdout);
    cin >> n>> m;
    intervs.resize(m);
    for(auto &x : intervs) {
        cin >> x.first >> x.second;
    }
    sort(intervs.begin(), intervs.end());
    ll l = 0;
    ll r= 1e18;

    while(l < r) {
        ll mid = (l + r + 1) / 2;
        if(valid(mid)) {
            l = mid;
        }
        else {
            r = mid - 1;
        }
    }

    ll answer = l;
    cout << answer << endl;

}