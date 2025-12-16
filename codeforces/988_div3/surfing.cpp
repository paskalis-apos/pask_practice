#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve_case() {
    ll numhurdles, numpowerups, endpos;
    cin >> numhurdles >> numpowerups >>endpos;

    vector<pair<ll,ll>> hurdles(numhurdles);
    vector<pair<ll,ll>> powerups(numpowerups);
    for(auto &x:  hurdles) {
        cin >> x.first;
        ll temp;
        cin >> temp;
        x.second = temp - x.first;
    }
    for(auto &x : powerups) {
        cin >> x.first >> x.second;
    }
    ll jump = 1;
    multiset<ll> powerpassed;
    ll pindex = 0;
    ll answer = 0;
    for(ll i = 0; i < numhurdles; i++) {
        ll need = hurdles[i].second;
        while(pindex < numpowerups && powerups[pindex].first < hurdles[i].first ) {
            powerpassed.insert(powerups[pindex].second);
            pindex++;
        }
        while(jump <= need + 1) {
            if(powerpassed.empty()) {
                cout << -1 << endl;
                return;
            }
            jump += *powerpassed.rbegin();
            answer++;
            powerpassed.erase(--powerpassed.end());
        }
    }
    cout << answer << endl;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t;i++) {
        solve_case();
    }
}