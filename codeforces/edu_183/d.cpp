#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    int SEGMAX = n * (n - 1) / 2 + 1;
    vector<vector<bool>> dp(n + 1, vector<bool>(SEGMAX));
    dp[0][0] = true;
    for(int i = 0; i< n; i++) {
        for(int j = 0;j < SEGMAX; j++) {
            if(!dp[i][j]) {
                continue;
            }
            for(int nb = 1; nb <= n - i; nb++) {
                int add = nb * (nb - 1) / 2;
                if(j + add >= SEGMAX){
                    break;
                }
                dp[i + nb][j + add] = true; 
            }
        }  
    }
    if(!dp[n][n * (n - 1) / 2 - k]) {
        cout << "0" << endl;
        return;
    }

    vector<int> blocks;
    blocks.push_back(n);
    int prevnum = n * (n - 1) / 2 - k;
    int prevind = n;
    for(int i = n - 1; i >= 0; i--) {
        int goal = prevnum - (prevind - i) * (prevind - i - 1) / 2;
        if(dp[i][goal]) {
            prevnum = goal;
            prevind = i;
            blocks.push_back(i);
        }   
    }
    vector<int> bsize;
    for(int i = 0;i < blocks.size() - 1; i++) {
        bsize.push_back(blocks[i] - blocks[i + 1]);
    }
    reverse(bsize.begin(), bsize.end());
    prevnum = n;
    for(auto &x : bsize) {
        prevnum -= x;
        for(int i = 1;i <= x; i++) {
            cout << prevnum + i << " ";
        }
    }
    cout << endl;


}

int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t; i++) {
        solve();
    }
}