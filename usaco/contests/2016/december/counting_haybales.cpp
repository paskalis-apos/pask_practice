#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("haybales.in","r",stdin);
    freopen("haybales.out","w",stdout);
    int n , q;
    cin >> n >> q;

    vector<int>numbers(n);
    map<int,int>pref;  
    for(auto &x : numbers) {
        cin >> x;
    }
    sort(numbers.begin(),numbers.end());
    pref[0] = 0;


    for(auto &x : numbers) {
        auto i = prev(pref.end());
        pref[x] = i->second + 1;
    }

    for(int i =0 ;i < q ;i++) {
        int a, b;
        cin >> a >> b;

        auto r = prev(pref.upper_bound(b));
        auto l = prev(pref.lower_bound(a));

        int ans = r->second - l->second ;
        cout << ans << endl;
    }





}