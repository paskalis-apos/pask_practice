#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n;
    ll sum = 0;
    cin >> n;
    vector<ll> per(n);
    for(auto &x : per) {
        cin >> x;
    }
    per.push_back(-1);
    for(int i = 0 ;i < n;i++) {
        if(per[i] > per[i + 1]) {
            sum += (i + 1) * (n - i);    
        }
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