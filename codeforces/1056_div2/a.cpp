#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int ans = 0;
    ans += n - 1;
    ans += n - 2;
    ans++;
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t ;i++) {
        solve();
    }
}