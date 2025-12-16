#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n;
    float c;
    cin >> n >> c;
    ll sum = 0;
    multiset<ll> v;
    for(int i = 0; i < n; i++) {
        ll temp;
        cin >> temp;
        v.insert(temp);
    }
    for(ll i = 1; i <= n; i++) {
        auto it = v.upper_bound(c);
        if(it == v.begin()) {
            sum += v.size();
            break;
        }
        it--;
        v.erase(it);
        c/= 2;
    }

    cout << sum << endl;


}

int main() {
    int t;
    cin >> t;
    for(int i =0 ;i< t ;i++) {
        solve();
    }
}