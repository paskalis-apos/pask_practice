#include<bits/stdc++.h>
using namespace std;

int n, k;
vector<vector<int>> grid;

bool valid(int mid) {
    vector<vector<int>> pref(n + 1, vector<int>(n + 1));
    for(int i = 1;i <= n;i++) {
        for(int j = 1; j <= n; j++) {
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j -1];
            if(grid[i][j] <= mid) {
                pref[i][j] ++;
            }
            else {
                pref[i][j]--;
            }
        }
    }

    for(int i = k;i <= n;i++) {
        for(int j = k; j <= n; j++) {
            int cur = pref[i][j] - pref[i][j - k] - pref[i - k][j] + pref[i - k][j - k];
            if(cur >= 0) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> n >> k;
    grid.assign(n + 1, vector<int>(n + 1));
    for(int i = 1; i <= n;i ++) {
        for(int j = 1;j <= n;j++) {
            cin >> grid[i][j];    
        }
    }

    int l = 0, r = 1e9;
    while(l < r) {
        int mid = (l + r) / 2;
        if(valid(mid)) {
            r = mid;
        }
        else {
            l = mid +  1;
        }
    }

    int ans = l;
    cout << ans << endl;
}