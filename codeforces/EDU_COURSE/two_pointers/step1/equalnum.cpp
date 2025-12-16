#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n , m;
    cin >> n >> m;
    vector<ll> v1(n), v2(m);
    for(auto &x : v1) {
        cin >> x;
    }
    for(auto &x : v2) {
        cin >> x;
    }

    ll pairs = 0;
    ll ind1 = 0;
    ll ind2 = 0;
    while(ind1 < n && ind2 < m) {
        if(v1[ind1] < v2[ind2]) {
            ind1++;
        }
        else if(v1[ind1] > v2[ind2]) {
            ind2++;
        }
        else {
            ll cur = v1[ind1];
            ll start1 = ind1;
            ll start2 = ind2;
            while(v1[ind1] == cur && ind1 < n) {
                ind1++;
            }
            while(v2[ind2] == cur && ind2 < m) {
                ind2++;
            }
            pairs += (ind1 - start1) * (ind2 - start2);
        }
    }

    cout << pairs << endl;
}