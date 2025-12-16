#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> ans;
    for(int i = 0;i < n;i++) {
        int num;
        cin >> num;
        ans.push_back(n - num + 1);
    }

    for(auto &x : ans){
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0;i< t; i++) {
        solve();
    }
}