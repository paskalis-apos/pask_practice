#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll h , c , t;
    cin >> h >> c >> t;
    if((h + c) / 2 >= t) {
        cout << 2 << endl;
        return;
    }

    ll l = 0;
    ll r = INT32_MAX;
    ll   valid = 0;
    while(l <= r) {
        ll mid = (l + r) / 2;
        ll num = mid * (h + c) + h;
        ll allcups = 2 * mid + 1;
        if(num >= t * allcups) {
            l = mid + 1;
            valid = mid;
        }
        else {
            r = mid - 1;
        }
    }

    ll num1 = valid * (h + c) + h - t * (2 * valid + 1);
    ll num2 = t * (2 * (valid + 1) + 1) - (valid + 1) * (h + c) - h;
    ll answer;
    ll times1 = 2 * valid + 1;
    ll times2 = 2 * (valid + 1) + 1;

    if(num1 * times2 <= num2 * times1) {
        answer = times1;
    }
    else {
        answer = times2;
    }

    cout << answer << endl;
}

int main(){
    int tcases;
    cin >> tcases;
    for(int i = 0 ;i < tcases; i++) {
        solve();
    }
}