#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    ll sum=  0;
    cin >> n;
    vector<ll> v(n);
    for(auto &x : v) {
        cin >> x;
        sum += x;
    }
    sort(v.begin(), v.end());
    int length = 0;
    int prev = -1;
    vector<ll> morewin;
    for(auto &x : v) {
        if(x == prev) {
            length++;
            continue;
        }
        else if(prev % 2 == 1){
            morewin.push_back(length);
        }
        length = 1;
        prev = x;
    }
    if(prev % 2 == 1) {
        morewin.push_back(length);
    }
    sort(morewin.rbegin(), morewin.rend());
    ll diff = 0;
    for(int i = 0;i < morewin.size();i ++) {
        if(i % 2 == 0) {
            diff += morewin[i];
        }
        else {
            diff -= morewin[i];
        }
    }
    ll a = (sum + diff) / 2;
    ll b= (sum - diff) / 2;
    cout << a << " " << b << endl;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t;i++) {
        solve();
    }
}