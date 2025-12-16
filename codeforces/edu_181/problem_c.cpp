#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll l , r;
    cin >> l >> r;

    ll totalnum = r- l;
    ll minusnum = 0;
    ll inside = 0;
    ll outside = 0;

    inside += r / 2;
    inside += r / 3 - r / 6;
    inside += r / 5 - r / 10 - r / 15 + r / 30;
    inside += r / 7 - r / 35 - r / 21 - r / 14 + r / 70 + r / 105 + r / 42 - r / 210;
    outside += (l - 1) / 2;
    outside += (l - 1) / 3 - (l - 1) / 6;
    outside += (l - 1) / 5 - (l - 1) / 10 - (l - 1) / 15 + (l - 1) / 30;
    outside += (l - 1) / 7 - (l - 1) / 35 - (l - 1) / 21 - (l - 1) / 14 + (l - 1) / 70 + (l - 1) / 105 + (l - 1) / 42 - (l - 1) / 210;
    
    ll answer = r - l + 1 -(inside - outside);
    cout << answer << endl;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        solve();
    }
}