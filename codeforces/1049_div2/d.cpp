#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct seg{
    int ind, l , r, sum;
    bool operator<(seg b) {
        return sum > b.sum;
    }
};

void solve() {
    ll n;
    cin >> n;
    vector<seg> segs(n);
    ll ans = 0;
    int ind = 0;
    for(auto &x : segs) {
        cin >> x.l>> x.r;
        x.sum = x.l + x.r;
        ans += x.r - x.l;
        x.ind = ind;
        ind++;
    }
    vector<int> segind(n);
    sort(segs.begin(), segs.end());
    for(int i = 0;i < n;i++) {
        segind[segs[i].ind] = i;
    }
    for(int i = 0;i< n / 2; i++) {
        ans += segs[i].r;
    }
    for(int i = n / 2;i < n; i++) {
        ans -= segs[i].l;
    }
    ll temp = ans;
    ll newans = ans;
    if(n % 2 == 1) {
        newans = 0;
        for(int i = 0;i < n;i++) {
            if(segind[i] < n / 2) {
                temp -= segs[segind[i]].r;
                temp += segs[n / 2].r;
                temp += segs[n / 2].l;
            }
            else {
                temp += segs[segind[i]].l;
            }
            newans = max(newans, temp);
            temp = ans;
        }
    }
    ans = newans;

    cout << ans << endl;
    
}

int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t; i++) {
        solve();
    }
}