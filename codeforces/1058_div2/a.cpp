#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    vector<bool> havefound(101);
    for(auto &x : v) {
        cin >> x;
        havefound[x] = true;
    }
    for(int i = 0;i <= 100; i++) {
        if(!havefound[i]) {
            cout << i << endl;
            return;
        }
    }
}


int main(){
    int t;
    cin >> t;
    for(int i = 0;i < t ;i++) {
        solve();
    }
}