#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n , t;
vector<int> times;

bool can_make(ll totaltime) {
    ll products = 0;
    for(auto &x : times) {
        products += totaltime / x;
        if(products >= t) {
            break;
        }
    }
    return (products >= t);
}

int main() {
    cin >> n >> t;
    times.resize(n);
    for(auto &x : times) {
        cin >> x;
    }

    ll r = 1e18;
    ll l = 0;

    while(l < r) {
        ll mid = (l + r) / 2;
        if(can_make(mid)) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }

    cout << l << endl;


}