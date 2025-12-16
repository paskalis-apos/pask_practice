#include<bits/stdc++.h>
using namespace std;
using ll = long long;


void solve() {
    ll n , k;
    cin >> n >> k;
    string bstring;
    cin >> bstring;
    vector<ll> tempv;
    vector<ll> ans(n);
    vector<vector<ll>> segs;
    vector<int> freeinds;
    for(int i = 0;i < n;i++){ 
        ll num;
        cin >> num;
        ans[i] = num;
        if(bstring[i] == '0'){ 
            freeinds.push_back(i);
            segs.push_back(tempv);
            tempv.clear();
            continue;
        }
        tempv.push_back( num);
    }
    segs.push_back(tempv);
    ll maxsum = 0;
    for(auto &x : segs) {
        ll l = 0;
        ll r = 0;
        ll cursum = 0;
        while(r < x.size()) {
            cursum += x[r];
            r++;
            if(cursum < 0){ 
                l = r;
                cursum = 0;
            }
            maxsum = max(maxsum, cursum);
        }
        if(maxsum > k) {
            cout << "NO" << endl;
            return;
        }
    }   
    ll maxsuf = 0;
    ll maxpref = 0;
    ll cursum = 0;
    if(segs.size() == 1) {
        if(maxsum != k) {
            cout << "NO" << endl;
            return;
        }
    }
    else {
        for(int i = segs[0].size() - 1; i >= 0; i--) {
            cursum += segs[0][i];
            maxsuf = max(maxsuf, cursum);
        }
        cursum = 0;
        for(int i = 0; i < segs[1].size(); i++) {
            cursum += segs[1][i];
            maxpref = max(maxpref, cursum);
        }  
        ans[freeinds[0]] = k - maxpref - maxsuf;
        for(int i = 1;i < freeinds.size(); i++){ 
            ans[freeinds[i]] = -1e18;
        }
        
    }
    cout << "YES" << endl;
    for(auto &x : ans){ 
        cout << x << " ";
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    for(int i = 0;i < t; i++) {
        solve();
    }
}