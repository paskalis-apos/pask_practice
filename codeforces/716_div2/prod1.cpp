#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;

    vector<ll> v;
    for(int i = 1; i <= n - 1; i++) {
        if(gcd(i , n) == 1) {
            v.push_back(i);
        }
    }

    ll prod = 1;
    for(auto &x : v) {
        prod *= x;
        prod %= n;
    }
    int to_find = prod;
    int vsize = v.size()- 1;
    if(to_find == 1) {
        to_find = -1;
        vsize++;
    }

    cout << vsize << endl;
    
    for(auto &x : v) {
        if(x == to_find) {
            continue;            
        }
        cout << x << " ";
    }
    cout << endl;
}