#include<bits/stdc++.h>
using namespace std;

int main() {
    int n , m;
    cin >> n >> m;
    vector<int> v(n);
    for(auto &x : v) {
        cin >> x;
    }

    set<int> no_occ;
    vector<int> occs(n);
    for(int i = 0;i <= n ;i++) {
        no_occ.insert(i);
    }

    int l = 0;
    int r = 0;
    int mex = INT_MAX;
    while(r < n) {
        occs[v[r]]++;
        if(occs[v[r]] == 1) {
            no_occ.erase(v[r]);
        }
        if(r - l + 1 > m) {
            occs[v[l]]--;
            if(occs[v[l]] == 0) {
                no_occ.insert(v[l]);
            }
            l++;
        }
        if(r - l + 1 < m) {
            r++;
            continue;
        }
        mex = min(mex, *no_occ.begin());
        r++;
    }

    cout << mex << endl;
}   