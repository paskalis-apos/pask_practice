#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll x , y , n;

bool works(ll num) {
    ll start = min(x , y);
    ll follup = max(x ,y );
    ll time_left = num - start;

    if(num / start + time_left / follup >= n) {
        return true;
    }
    return false;



}

int main() {
    cin >> n >> x >> y;

    ll l = 0;
    ll r = n * min(x, y);

    while(r - l > 1) {
        ll mid = ll(l + r) / 2;

        if(works(mid)) {
            r = mid;
        }
        else {
            l = mid;
        }
    }

    cout << r;
    
}