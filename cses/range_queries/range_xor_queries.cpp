#include<bits/stdc++.h>
using namespace std;

int main(){ 
    int n , q;
    cin >> n >> q;

    vector<int> v(n);
    for(auto &x : v) {
        cin >> x;
    }

    vector<int>xpref(n + 1);

    for(int i = 1; i <= n; i++) {
        xpref[i] = (v[i - 1] ^ xpref[i -1]);
    }

    for(int i = 0 ;i < q; i++) {
        int l , r;
        cin >> l >> r;
        int answer = xpref[r] - xpref[l - 1];
        cout << answer << endl;
    }
}