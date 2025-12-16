#include<bits/stdc++.h>
using namespace std;

int main() {
    int n , k;
    cin >> n >> k;

    vector<int> cur(1e6 + 1);
    int l = 0;
    int r = 0;

    vector<int> values(n);
    int lind, rind;
    for(auto &x : values) {
        cin >> x;
    }
    int diff_values = 0;
    int maxdist = 0;
    while(r < n) {
        cur[values[r]]++;
        if(cur[values[r]] == 1) {
            diff_values++;
        }
        while(diff_values > k) {
            cur[values[l]]--;
            if(cur[values[l]] == 0) {
                diff_values--;
            }
            l++;
        }

        if(r - l + 1> maxdist) {
            lind = l + 1;
            rind = r + 1;
            maxdist = r - l + 1;
        }
        r++;
    }

    cout << lind <<" " << rind << endl;
}