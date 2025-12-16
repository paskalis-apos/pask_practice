#include<bits/stdc++.h>
using namespace std;

void solve(){ 
    int n , k;
    cin >> n >> k;
    vector<int> rain(n);
    for(auto &x : rain) {
        cin >> x;
    }

    int l = 0;
    int r = 0;
    int peaks = 0;
    while(r < n) {
        if(rain[r] == 0) {
            r++;
            if(r - l == k) {
                peaks++;
                l = r + 1;
                r = r + 1;
            }
        }
        else {
            l = r + 1;
            r = r + 1;
        }
    }

    cout << peaks << endl;
}

int main() {
    int t;
    cin >> t;
    for(int i =0 ;i < t; i++) {
        solve();
    }
}