#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    freopen("hayfeast.in","r",stdin);
    freopen("hayfeast.out","w",stdout);
    ll n , m;
    cin >> n >> m;

    vector<pair<ll,ll>> hays(n);
    for(auto &x : hays) {
        cin >>x.first >> x.second;
    }

    int l = 0;
    int r = 0;
    multiset<ll> spiciness;
    ll minspice = 1e18;
    ll flavour = 0;
    while(r < n) {
        spiciness.insert(hays[r].second);
        flavour += hays[r].first;
        while(flavour - hays[l].first >= m){
            spiciness.erase(spiciness.find(hays[l].second));
            flavour -= hays[l].first;
            l++;
        }
        if(flavour >= m) {
            minspice = min(minspice, *prev(spiciness.end()));
        } 
        r++;
    }   

    cout << minspice << endl;
}