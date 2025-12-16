#include<bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

ll w , h , n;

bool works(ll num) {
    if((__uint128_t)(num / w) * (num / h) >= n) {
        return true; 
    }
    return false;
}

int main() {

    ios::sync_with_stdio(false);
  
    cin >> w >> h >> n; 

    ll r ;

    r = max(h , w) * n;
    ll l = 0 ;

    while(r > l + 1) {
        ll mid = (r + l)/ 2;
        if(works(mid)) {
            r = mid;
        }
        else {
            l = mid;
        }       
    }

    cout << r;
}