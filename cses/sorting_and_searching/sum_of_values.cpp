#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n ,x;
    cin >> n >> x;

    vector<ll>values(n);
    for(auto &a : values) {
        cin >> a;
    }

    map<ll ,ll> value_to_index;
    for(ll i = 0 ;i < n ;i++) {
        if(value_to_index.count(x - values[i])) {
            cout << i + 1<< " " << value_to_index[x - values[i]] << endl;
            return 0;
        }        
        value_to_index[values[i]] = i + 1;
    }

    cout << "IMPOSSIBLE";
}