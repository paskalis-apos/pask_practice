#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> arrs(n);
    for(int i = 0;i < n;i++) {
        int length;
        cin >> length;
        arrs[i].resize(length);
        for(auto &x : arrs[i]) {
            cin >> x;
        }
    }

    set<int> not_used;
    for(int i = 0;i < n; i++) {
        not_used.insert(i);
    }
    vector<bool> valid(n, true);
    vector<int> ans;
    int ind = 0;
    while(!not_used.empty()) {
        vector<int> todelete;
        int smallest = 1e6;
        for(auto &x : not_used) {
            if(ind == arrs[x].size() - 1) {
                todelete.push_back(x);
            }
            if(!valid[x]) {
                continue;
            }
            smallest = min(smallest, arrs[x][ind]);
        }
        bool good = false;
        for(auto &x :todelete) {
            if(arrs[x][ind] == smallest && valid[x]) {
                good = true;
            }
            not_used.erase(x);
        }
        ans.push_back(smallest);
        for(auto &x : not_used) {
            if(good) {
                valid[x] = true;
            }
            else if(arrs[x][ind] > smallest) {
                valid[x] = false;
            }
        }
        ind++;
    }

    for(auto &x : ans) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t;i++) {
        solve();
    }
}