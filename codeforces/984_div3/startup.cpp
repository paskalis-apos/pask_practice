#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void check_case() {
    int n , k;
    cin >> n >> k;

    vector<int> brandcost(k + 1);
    for(int i = 0;i < k; i++) {
        int b , c;
        cin >> b >> c;
        brandcost[b] += c;
    }
    sort(brandcost.rbegin(), brandcost.rend());
    ll ans = 0;
    for(int i = 0;i < n && i <= k; i++) {
        ans += brandcost[i];
    }

    cout << ans << endl;
}

int main() {
    int t;
    cin >>t;

    for(int i = 0; i< t;i ++) {
        check_case();
    }
}