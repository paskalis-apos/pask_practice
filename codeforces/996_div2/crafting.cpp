#include<bits/stdc++.h>
using namespace std;

void solve() {
    int matnum;
    cin >> matnum;

    vector<int>have(matnum);
    vector<int>want(matnum);
    for(auto &x : have) {
        cin >> x;
    }
    for(auto &x : want) {
        cin >> x;
    }
    vector<int>need(matnum);
    int maxneed= 0;
    int numneed =- 1;
    for(int i = 0 ;i < matnum;i++) {
        need[i] = want[i] - have[i];
        maxneed = max(maxneed, need[i]);
        if(maxneed == need[i]) {
            numneed = i;
        }
    }
    if(numneed == -1) {
        cout <<"YES";
    }
    else{
        bool valid = true;
        for(int i = 0 ;i < matnum ;i++) {
            if(i == numneed || -need[i] >= maxneed) {
                continue;
            }
            valid = false;
            break;

        }
        if(valid) {
            cout << "YES";
        }
        else {
            cout << "NO";
        }
    }
    cout << endl;




}

int main() {
    int t;
    cin >> t;
    for(int i = 0 ;i < t ;i++) {
        solve();
    }
}