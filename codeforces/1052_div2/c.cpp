#include<bits/stdc++.h>
using namespace std;

void solve(){ 
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> fixed_pos;
    for(int i = 0;i < n;i++) {
        if(s[i] == '1') {
            fixed_pos.push_back(i);
        }
    }
    vector<int> ans(n);
    for(auto &x : fixed_pos) {
        int ind = x;
        ans[x] = x + 1;
        if(ans[x - 1] != 0) {
            continue;
        }
        ind--;
        if(ind < 0) {
            continue;
        }
        while(ind > 0 && ans[ind - 1] == 0) {
            ans[ind] = ind;
            ind--;
        }
        ans[ind] = x ;
        if(x - 1 == ind) {
            cout << "NO" << endl;
            return;
        }
    }
    int ind = n - 1;
    if(ans[ind] == 0) {
        while(ind > 0 && ans[ind - 1] == 0) {
            ans[ind] = ind;
            ind--;
        }

        if(ind >= 0) {
            ans[ind] = n;
        }
        if(n - 1 == ind) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    for(auto &x : ans){ 
        cout <<x << " ";
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