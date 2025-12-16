#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;

    cin >> n;

    vector<int> ans;
    for(int i = 0;i < n; i++) {
        if(i % 2 == 0) {
            ans.push_back(-1);
        }
        else if(i == n -1) {
            ans.push_back(2);
        }
        else{
            ans.push_back(3);
        }
    }

    for(auto &x : ans) {
        cout << x << " ";
    }
    cout << endl;
}
int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t ;i++ ){
        solve();
    }
}