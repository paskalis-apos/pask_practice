#include<bits/stdc++.h>
using namespace std;
using ll =  long long;

vector<ll> sum(1e6 + 1);
ll h , d;

bool valid(ll mid) {
    ll parts = mid + 1; 
    ll smallparts = d / parts;
    ll bigparts = smallparts + 1;
    ll bignum = d % parts;

    ll cost =bignum * sum[bigparts];
    cost += (parts - bignum) * sum[smallparts];
    ll canuse = h + mid;
    if(canuse > cost){
        return true;
    }
    return false;
}

void solve() {
    cin >> h >> d;
    ll lo = 0;
    ll hi = 1e9;
    while(lo < hi) {
        ll mid = (lo + hi) / 2;
        if(valid(mid)) {
            hi = mid;
        }
        else {
            lo = mid + 1;
        }
    }

    ll ans = d + lo;
    cout << ans << endl;

}

int main (){
    int t;
    cin >> t;
    for(int i = 1;i <= 1e6; i++) {
        sum[i] += sum[i - 1] + i;
    }
    for(int i = 0; i < t ;i++) {
        solve();
    }
}