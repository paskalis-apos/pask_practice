#include<bits/stdc++.h>
using namespace std;

void solve(){ 
    int n;
    cin >> n;

    vector<int> v(2 * n);
    int cur = n - 1;
    int ind = 0;
    while(cur >= 1) {
        v[ind] = cur;
        v[ind + 2 * cur] = cur;
        ind++;
        cur--;
    }
    v[ind] = n;
    v[ind + n] = n;

    for(auto &x : v) {
        cout << x << " ";
    }
    cout << endl;
}


int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t ;i++) {
        solve();
    }
}