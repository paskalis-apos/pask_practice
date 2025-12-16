#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n;

bool valid(ll num) {
    ll before = 0;
    for(ll i = 1 ;i <= n ;i++) {
        before += min(n,(num / i));
    }
    if(before >= (n * n + 1) / 2) {
        return true;
    }
    return false;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    ll l = 1 , r = n * n;
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