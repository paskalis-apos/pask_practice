#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for(auto &x :v){
        cin >> x;
    }
    vector<pair<ll,ll>> comp(n);
    for(int i = 0 ;i < n ;i++) {
        comp[i].first = v[i] - i - 1;
        comp[i].second = i;
    }
    sort(comp.begin(), comp.end());
    priority_queue<ll> weights;
    for(int i = n - 1 ;i > 0; i--) {
        if(comp[i].first == comp[i - 1].first) {
            weights.push(v[comp[i].second] + v[comp[i - 1].second]);
            i--;
        }
    }

    ll sum = 0;
    while(!weights.empty() && weights.top() > 0) {
        sum += weights.top();
        weights.pop();
    }

    cout << sum << endl;
    
}

int main() {
    int t;
    cin >> t;
    for(int i = 0 ;i < t; i++) {
        solve();
    }
}