#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for(auto &x : v){ 
        cin >> x;
    }
    vector<int> ans(n);
    ans[0] = 1;
    int ind = 2;
    for(int i = 1;i < n ;i++) {
        int diff = v[i] - v[i - 1];
        if(diff == i + 1) {
            ans[i] = ind;
            ind++;
        }
        else {
            ans[i] = ans[i - diff];
        }
    }

    for(auto &x : ans) {
        cout << x<< " ";
    }
    cout << endl;
}


int main(){
    int t;
    cin >> t;
    for(int i = 0;i < t ;i++) {
        solve();
    }
}