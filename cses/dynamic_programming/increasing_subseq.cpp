#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int>v(n);
    for(auto &x : v) {
        cin >> x;
    }

    vector<int>d(n + 1, 1e9);
    d[0] = -1e9;

    for(int i = 0 ; i < n ;i++) {
        int l = upper_bound(d.begin(), d.end(), v[i]) - d.begin();
        if(d[l - 1] < v[i] && v[i] < d[l]) {
            d[l] = v[i];
        }
    }

    for(int i = n; i > 0; i--) {
        if(d[i] != 1e9) {
            cout << i << endl;
            break;
        }
    }
}