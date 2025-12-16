#include<bits/stdc++.h>
using namespace std;
using ll = long long;


void solve() {
    int n;
    cin >> n;
    vector<bool> seen(101);
    int ans = 0;
    for(int i = 0;i < n;i++) {
        int num;
        cin >> num;
        if(!seen[num]) {
            ans += 2;
            seen[num] = true;
        }
    }

    ans--;
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t; i++) {
        solve();
    }
}