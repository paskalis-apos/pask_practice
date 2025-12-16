#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    ll minimum = INT_MAX;
    bool valid = true;
    for(int i = 0 ;i < n ;i++) {
        ll num;
        cin >> num;
        if(num > minimum) {
            valid = false;
        }
        minimum = min(minimum, 2 * num - 1);
    }
    if(valid) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    cout << endl;
    return;
}

int main() {
    int t;
    cin >> t;
    for(int i =0 ;i< t ;i++) {
        solve();
    }
}