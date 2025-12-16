#include<bits/stdc++.h>
using namespace std;

int q;

int main() {
    cin >> q;
    vector<int> rep(5 * 1e5 + 10);
    vector<int> ans;
    for(int i = 0 ;i <= 5 * 1e5; i++) {
        rep[i] = i;
    }

    vector<int> t(q), x(q), y(q);

    for(int i = 0 ; i < q ;i ++) {
        cin >> t[i] >> x[i];
        if(t[i] == 2) {
            cin >> y[i];
        }
    }

    for(int i = q - 1; i >= 0; i--) {
        if(t[i] == 1) {
            ans.push_back(rep[x[i]]);
        }
        else {
            rep[x[i]] = rep[y[i]];
        }
    }

    reverse( ans.begin(), ans.end());

    for(auto &x : ans) {
        cout << x <<" ";
    }


}