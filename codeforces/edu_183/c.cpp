#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int goaldiff = 0;
    for(auto &x : s) {
        if(x == 'a') {
            goaldiff--;
        }
        else {
            goaldiff++;
        }
    }   
    if(goaldiff == 0) {
        cout << 0 << endl;
        return;
    }
    vector<int> lastocc(2 * n + 10, -1);
    vector<int> prefdiff(n + 1);
    prefdiff[0] = n;
    lastocc[n] = 0;
    int ans = -1;
    
    for(int i = 1;i <= n;i++) {
        prefdiff[i] = prefdiff[i - 1];
        if(s[i - 1] == 'a') {
            prefdiff[i]--;
        }
        else {
            prefdiff[i]++;
        }
        if(lastocc[prefdiff[i] - goaldiff] != -1) {
            if(ans == -1) {
                ans = i - lastocc[prefdiff[i] - goaldiff];
            }
            else {
                ans = min(ans, i - lastocc[prefdiff[i] - goaldiff]);
            }
        }
        lastocc[prefdiff[i]] = i;
    }
    if(ans == n) {
        ans = -1;
    }
    cout << ans << endl;

}

int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t; i++) {
        solve();
    }
}