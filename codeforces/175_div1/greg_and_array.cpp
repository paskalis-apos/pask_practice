#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct op{
    int l , r , d;
};

int main() {
    int n , m , k;
    cin >> n >> m >> k;

    vector<int> v(n);
    for(auto &x : v) {
        cin >> x;
    }

    vector<int> times_applied(m + 1);
    vector<op> operations(m);
    for(auto &x : operations) {
        cin >> x.l >> x.r >> x.d;
        x.l--;
        x.r--;
    }
    for(int i = 0; i < k; i++) {
        int x , y;
        cin >> x >> y;
        x--;
        y--;
        times_applied[x] += 1;
        times_applied[y + 1] -= 1;
    }

    vector<ll> diffs(n + 1);
    int counter = 0;
    for(int i = 0 ;i < m ;i++) {
        counter += times_applied[i];
        int curx = operations[i].l;
        int cury = operations[i].r;
        ll curpoints = operations[i].d;
        curpoints *= counter;
        diffs[curx] += curpoints;
        diffs[cury + 1] -= curpoints;
    }

    ll extra = 0;
    for(int i = 0 ;i < n; i++) {
        extra += diffs[i];
        cout << v[i] + extra << " ";
    }
    cout << endl;
}