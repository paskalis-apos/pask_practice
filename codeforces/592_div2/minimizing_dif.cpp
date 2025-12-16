#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n , k;

int main() {
    cin >> n >> k;
    map<ll,ll> m;
    for(int i = 0 ;i <  n ;i++) {
        ll temp;
        cin >> temp;
        m[temp]++;
    }

    ll counter = 0;
    while(k > 0) {
        if(m.size() == 1) {
            break;
        }
        auto l = m.begin();
        auto r = prev(m.end());
        auto nextl = next(l);
        auto prevr = prev(r);
        if(l-> second <= r->second) {
            ll totalmoves = (nextl-> first - l->first) * l->second;
            if(k >= totalmoves) {
                ll newpos = nextl->first;
                ll newnum = nextl->second + l->second;
                m.erase(l);
                m[newpos] = newnum;
                k -= totalmoves;
            }
            else {
                ll canmove = k / (l->second);
                ll newpos = l->first + canmove;
                ll newnum = l->second;
                m.erase(l);
                m[newpos] = newnum;
                k = 0;
            }
        }
        else {
            ll totalmoves = (r-> first - prevr->first) * r->second;
            if(k >= totalmoves) {
                ll newpos = prevr->first;
                ll newnum = prevr->second + r->second;
                m.erase(r);
                m[newpos] = newnum;
                k -= totalmoves;
            }
            else {
                ll canmove = k / (r->second);
                ll newpos = r->first - canmove;
                ll newnum = r->second;
                m.erase(r);
                m[newpos] = newnum;
                k = 0;
            }
        }
    }

    ll l = m.begin()->first;
    ll r = prev(m.end())->first;

    ll answer = r - l;
    cout << answer << endl;

    



}