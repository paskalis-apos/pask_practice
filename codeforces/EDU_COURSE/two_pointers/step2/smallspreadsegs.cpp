#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n , k;
    cin >> n >> k;

    vector<ll>v(n);
    for(auto &x : v) {
        cin >> x;
    }

    ll l = 0;
    ll r = 0;
    ll segnum = 0;
    multiset<ll> nums;
    while(r < n){ 
        nums.insert(v[r]);
        r++;
        while(!nums.empty() && *prev(nums.end()) - *nums.begin() > k) {
            nums.erase(nums.find(v[l]));
            l++;
        }
        segnum += r - l;
    }

    cout << segnum << endl;
}