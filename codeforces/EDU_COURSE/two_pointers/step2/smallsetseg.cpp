#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n , k;
    cin >> n >> k;

    vector<int> v(n);
    for(auto &x : v) {
        cin >> x;
    }

    vector<int> occs(1e5 + 1);
    ll segnum = 0;
    int diffel = 0;
    int r = 0;
    int l = 0;
    while(r < n) {
        occs[v[r]]++;
        if(occs[v[r]] == 1) {
            diffel++;
        }
        r++;
        while(diffel > k) {
            occs[v[l]]--;
            if(occs[v[l]] == 0) {
                diffel--;
            }
            l++;
        }
        segnum += r - l;
    }

    cout << segnum << endl;
}