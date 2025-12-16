#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> v;
int n ,k;

bool valid(ll num) {
    int subnum = 1;
    ll cursum = 0;
    for(auto &x: v) {
        if(x > num) {
            return false;
        }
        if(cursum + x <= num) {
            cursum += x;
        }
        else {
            cursum = x;
            subnum++;
        }
    }

    if(subnum <= k) {
        return true;
    }
    return false;
}

int main() {
    cin >> n >> k;

    v.resize(n);
    for(auto &x : v ) {
        cin >> x;
    }

    ll l = 0; 
    ll r = 1e15;

    while(l < r) {
        ll mid = (l + r ) / 2;
        if(valid(mid)) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }

    cout << l << endl;
}