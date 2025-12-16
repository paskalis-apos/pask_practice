#include<bits/stdc++.h>
using namespace std;

int main() {
    int n , k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<vector<int>> numoccs(26);
    vector<int> dp(n + 2);
    dp[n] = 1;
    for(int i = 0;i <  n;i++) {
        numoccs[s[i] - 'a'].push_back(i);
    }
    for(int i = 0;i < k ;i++) {
        numoccs[i].push_back(n);
    }
    for(int i = n - 1;i >= 0;i --) {
        int minadd = INT_MAX;
        for(int j = 0;j < k; j++) {
            int addpos = lower_bound(numoccs[j].begin(), numoccs[j].end(), i) - numoccs[j].begin();
            int curpos = numoccs[j][addpos];
            minadd = min(minadd, dp[curpos + 1] + 1);
        }
        dp[i] = minadd;
    }

    int q;
    cin >> q;
    for(int i = 0;i < q; i++) {
        string t;
        cin >> t;
        int curpos = -1;
        for(auto &x : t) {
            int curnum = x - 'a';
            int addpos = lower_bound(numoccs[curnum].begin(), numoccs[curnum].end(), curpos) - numoccs[curnum].begin();
            curpos = numoccs[curnum][addpos] + 1;
            if(curpos == s.size() + 1) {
                break;
            }
        }
        cout << dp[curpos] << endl;
    }
}