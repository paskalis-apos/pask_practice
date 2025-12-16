#include<bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll n;
    cin >> n;
    vector<ll>v1(n);
    vector<ll>v2(n);
    for(auto &x : v1) {
        cin >> x;
    }
    for(auto &x : v2) {
        cin >> x;
    }

    vector<vector<ll>>pref(2e5 + 6);
    for(int i = 0 ;i <= 2e5 + 5; i++) {
        pref[i].push_back(0);
    }

    for(int i = 0 ;i < n; i++) {
        pref[v2[i]].push_back(v1[i] + pref[v2[i]].back());
    }


    ll q;
    cin >> q;
    vector<ll>exception(2e5 + 6);
    ll totaladd = 0;
    for(int i = 0 ; i< q; i++) {
        ll basic, colour , num;
        cin >> basic >> colour >> num;
        if(basic == 1) {
            totaladd += num;
            exception[colour] += num;
        }
        else {
            ll l = 0;
            ll r = pref[colour].size() - 1;
            while(l < r) {
                ll mid = (l + r + 1) / 2;
                ll add = totaladd - exception[colour];
                ll value = pref[colour][mid] + add * mid;
                if(value <= num) {
                    l = mid;
                }
                else {
                    r = mid - 1;
                }
            }
            cout << l << endl;
        }
    }
}