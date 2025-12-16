#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n , m;
    cin >> n >> m;

    vector<ll>pnum(m);
    for(auto &x : pnum) {
        cin >> x;  
    }
    sort(pnum.begin(), pnum.end());

    ll answer = 0;

    for(int i = 1 ;i <= n / 2; i++) {
        ll help = lower_bound(pnum.begin(), pnum.end(), i) - pnum.begin();
        ll getfirst = m - help;
        help =  lower_bound(pnum.begin(), pnum.end(), n - i) - pnum.begin();
        ll getsecond = m - help;
        if(i == n / 2 && n % 2 == 0) {
            answer += (getsecond * (getfirst - 1)) / 2;
        }
        else {
        answer += getsecond * (getfirst - 1);
        }
    }
    answer *= 2;

    cout << answer << endl;

}

int main() {
    int t;
    cin >> t;
    for(int i = 0 ;i < t ;i++) {
        solve();
    }
}