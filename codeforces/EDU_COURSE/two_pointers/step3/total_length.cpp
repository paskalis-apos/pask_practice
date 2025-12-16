#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n , s;
    cin >> n >> s;
    vector<int> v(n);
    for(auto &x : v) {
        cin >> x;
    }
    ll totalsum = 0;
    ll cursum = 0;  

    int l = 0;
    int r = 0;
    while(r < n){
        cursum += v[r];
        r++;
        while(cursum > s) {
            cursum -= v[l];
            l++;
        }
        
        ll length = r - l;
        totalsum += length * (length + 1) / 2;
    }

    cout << totalsum << endl;
}