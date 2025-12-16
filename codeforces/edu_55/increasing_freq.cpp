#include<bits/stdc++.h>
using namespace std;

int main() {
    int n , c;
    cin >> n >> c;
    vector<int> v(n + 1);
    vector<vector<int>> occs(5 * 10e5 + 1);
    vector<int> prefc(n + 1);
    for(int i = 1 ;i < n + 1; i++) {
        cin >> v[i];
        prefc[i] = prefc[i - 1];
        if(v[i] == c) {
            prefc[i]++;
        }
        occs[v[i]].push_back(i);
    }   
    int maxel = 0;
    for(int i = 1; i < 5 * 10e5 + 1; i++) {
        if(i == c) {
            continue;
        }
        int fixedmax = 0;
        if(occs[i].empty()) {
            continue;
        }
        int l = 0;
        int r = 1;
        vector<int> prefi;
        prefi.push_back(1);
        while(r < occs[i].size()) {
            prefi.push_back(prefc[occs[i][l] ] - prefc[occs[i][r]]);
            prefi.push_back(1);
            r++;
            l++;
        } 

        vector<int> dp(prefi.size() + 1);
        int fixemax = 0;
        for(int i = 1; i < dp.size(); i++) {
            dp[i] = prefi[i - 1];
            dp[i] += max(0 , dp[i -1]);
            fixedmax = max(fixedmax, dp[i]);
        }
        maxel = max(fixedmax, maxel);
    }
    maxel += prefc[n];
    cout << maxel << endl;
}