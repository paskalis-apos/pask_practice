#include<bits/stdc++.h>
using namespace std;

void solve(){ 
    int n ,m;
    cin >> n >> m;
    vector<vector<int>> arrs(n);
    vector<int> totaloccs(m + 1);
    for(int i = 0;i < n; i++) {
        int length;
        cin >> length;
        arrs[i].resize(length);
        for(auto &x : arrs[i]) {
            cin >> x;
            totaloccs[x]++;
        }
    }
    int canskipcount = 0;
    for(int i = 1;i <= m ;i++) {
        if(totaloccs[i] == 0) {
            cout << "NO" << endl;
            return;
        }
    }
    for(auto &x : arrs) {
        bool valid = true;
        for(auto &y : x) {
            totaloccs[y]--;
            if(totaloccs[y] <= 0) {
                valid = false;
            }
        }
        for(auto &y : x) {
            totaloccs[y]++;
        }
        if(valid) {
            canskipcount++;
        }
    }

    if(canskipcount >= 2) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }


}

int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t;i++) {
        solve();
    }
}