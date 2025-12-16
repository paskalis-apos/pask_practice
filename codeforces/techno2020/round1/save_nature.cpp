#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll queriesnum, ticketsnum;
vector<ll>tprices;
ll x , a , y , b;
ll k;
int lastvalid;


bool valid(ll mid) {
    ll bfare = mid / b;
    ll afare = mid / a;
    ll lcm_ab = a * b / __gcd(a , b);
    ll doublefare = mid / lcm_ab;
    afare -= doublefare;
    bfare -= doublefare;
    
    int ind = 0;
    ll sum = 0;
    while(doublefare > 0) {
        sum += (tprices[ind] / 100) * (x + y);
        ind ++;
        doublefare--;
    }
    while(afare > 0) {
        sum += (tprices[ind] / 100) * x;
        ind ++;
        afare--;
    }
    while(bfare > 0) {
        sum += (tprices[ind] / 100) * y;
        ind++;
        bfare--;
    }
    if(sum >= k) {
        return true;
    }
    return false;
}

void solve() {
    lastvalid = -1;
    cin >> ticketsnum;
    tprices.assign(ticketsnum,0);
    for(auto &x : tprices) {
        cin >> x;
    }
    sort(tprices.rbegin(), tprices.rend());
    cin >> x >> a >> y >> b;
    cin >> k;
    if(x <y) {
        swap(a , b);
        swap(x , y);
    }
    ll l = 1;
    ll r = ticketsnum + 1;
    while(l < r){ 
        int mid = (l + r) / 2;
        if(valid(mid)) {
            lastvalid = mid;
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }

    int answer = lastvalid;
    cout << answer << endl;

}

int main() {
    int queriesnum;
    cin >> queriesnum;
    for(int i = 0 ;i < queriesnum; i++) {
        solve();
    }
}