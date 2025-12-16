#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll findsum(ll a) {
    if(a == 1 || a == 0) {
        return 0;
    }
    ll digs = 16;
    ll lastdig;
    ll i;
    for(i = 1e15;i > 0 ;i /= 10) {
        if(i < a) {
            lastdig = a / i;
            break;
        }
        digs--;
    }
    ll ans = 0;
    ll temp = findsum(i);
    int j;
    for(j = 0;j < lastdig; j++) {
        ans += temp;
        ans += i * j;
        a -= i;
    }
    ans += lastdig * a;
    ans += findsum(a);
    
    return ans;

}

void solve() {
    ll k;
    cin >> k;

    ll i = 1;
    ll mult = 9;
    ll num = 0;
    ll cur = k;

    while(cur >= i * mult) {
        cur -= mult * i;
        i++;
        num += mult;
        mult *= 10;
    }
    ll ans = 0;
    num += cur / i;
    cur -= (cur / i) * i;
    ll leftnum = num + 1;
    int count = 0;
    for (ll i = 1e15; i > 0 && count < cur; i /= 10) {
        if (leftnum / i == 0) {
            continue;
        }
        int digit = (leftnum / i) % 10;
        ans += digit;
        count++;
    }

    ans += findsum(num + 1);

    cout << ans << endl;


}

int main() {
    int t;
    cin >> t;
    for(int i = 0 ;i < t;i++) {
        solve();
    }
}