#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> grid(n);
    for(int i = 0;i < n; i++) {
        for(int j = 0;j < n ;j++) {
            int num;
            cin >> num;
            grid[i].push_back(num);
        }
    }

    vector<int> horcost(n);
    vector<int> vercost(n);
    for(auto &x : horcost) {
        cin >> x;
    }
    for(auto &x : vercost) {
        cin >> x;
    }
}

int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t;i++) {
        solve();
    }
}