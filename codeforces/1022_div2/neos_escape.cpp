#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    vector<int> inp(n + 2);
    vector<bool> visited(n + 2);
    for(int i = 0;i < n; i++) {
        cin >> v[i].first;
        inp[i + 1] = v[i].first;
        v[i].second = i + 1;
    }
    sort(v.rbegin(), v.rend());
    int ans = 0;
    for(auto &x : v) {
        if(visited[x.second]) {
            continue;
        }
        visited[x.second] = true;
        int ind1 = x.second - 1;
        while(inp[ind1] == x.first) {
            visited[ind1] = true;
            ind1--;
        }
        int ind2 = x.second + 1;
        while(inp[ind2] == x.first) {
            visited[ind2] = true;
            ind2++;
        }
        if(!visited[ind1] && !visited[ind2]) {
            ans++;
        }
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