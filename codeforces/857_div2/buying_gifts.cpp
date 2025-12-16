#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int depnum;
    cin >> depnum;

    multiset<pair<int,int>> astores;
    multiset<pair<int,int>> bstores;
    vector<bool>erased(depnum + 1);
    for(int i = 0; i < depnum; i++) {
        int tempa , tempb;
        cin >> tempa >> tempb;
        astores.insert({tempa, i});
        bstores.insert({tempb, i});
    }

    ll diff = INT_MAX;
    while(true) {
        pair<ll,ll> atop = *prev(astores.end());
        pair<ll,ll> btop = *prev(bstores.end());
        if(atop.second == btop.second) {
            erased[atop.second] = true;
            if(astores.size() == 1) {
                bstores.erase(prev(bstores.end()));
            }
            else if(bstores.size() == 1) {
                astores.erase(prev(astores.end()));
            }
            else {
                pair<ll,ll> a = *prev(prev(astores.end()));
                pair<ll,ll> b = *prev(prev(bstores.end()));
                if(abs(atop.first - b.first) >= abs(btop.first - a.first)) {
                    astores.erase(prev(astores.end()));
                }
                else {
                    bstores.erase(prev(bstores.end()));
                    btop = b;
                }
            }  
        }
        else {
            diff = min(diff,abs(atop.first - btop.first));  
            if(atop.first >= btop.first) {
                if(erased[atop.second] || astores.size() == 1) {
                    break;
                }
                erased[atop.second] = true;
                astores.erase(prev(astores.end()));
                atop = *prev(astores.end());
            }
            else {
                if(erased[btop.second] || bstores.size() == 1) {
                    break;
                }
                erased[btop.second] = true;
                bstores.erase(prev(bstores.end()));
                btop = *prev(bstores.end());
            }
        }
    }

    cout << diff << endl;
    
}

int main() {
    int t;
    cin >> t;
    for(int i = 0 ;i < t; i++) {
        solve();
    }
}