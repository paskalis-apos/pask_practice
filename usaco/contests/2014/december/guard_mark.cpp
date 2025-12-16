#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct cow {
    ll h , w , s;
};

ll n , minheight;

int main() {
    freopen("guard.in","r",stdin);
    freopen("guard.out","w",stdout);
    cin >> n >> minheight;

    vector<cow> v(n);
    for(auto &x : v) {
        cin >> x.h >> x.w >> x.s;
    }

    vector<ll> dpheight(1 << n);
    vector<ll> dpsafe(1 << n, -1);
    dpsafe[0] = 1e14;
    ll maxsafety = -1e14;

    for(int bt = 1;bt < (1 << n); bt++) {
        for(int i = 0 ;i < n; i++) {
            if(!(bt & (1 << i))) {
                continue;
            }
            ll prev = bt - (1 << i);
            dpheight[bt] = dpheight[prev] + v[i].h;
            ll safechange = min(dpsafe[prev] - v[i].w, v[i].s);
            dpsafe[bt] = max(dpsafe[bt], safechange); 
        }
        if(dpheight[bt] >= minheight) {
            maxsafety = max(maxsafety, dpsafe[bt]);
        }
    }

    if(maxsafety < 0) {
        cout << "Mark is too tall" << endl;
        return 0 ;
    }
    cout << maxsafety << endl;
}