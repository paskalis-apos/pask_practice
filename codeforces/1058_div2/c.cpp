#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n;
    cin >> n;
    if(n == 0){
        cout << "YES" << endl;
        return;
    }
    vector<bool> bit(31);
    for(int i = 0;i <= 30; i++) {
        if((n | (1 << i)) == n) {
            bit[i] = true;
        }
    }
    int l = 0;
    int r = -1;
    for(int i = 30; i >= 0; i--) {
        if(bit[i]) {
            r = i;
            break;
        }
    }
    for(int i = 0;i <= 30; i++) {
        if(bit[i]) {
            l = i;
            break;
        }
    }
    while(l <= r) {
        if(bit[l] != bit[r]) {
            cout << "NO" << endl;
            return;
        }
        else if(l == r && bit[l]) {
            cout << "NO" << endl;

            return;
        }
        l++;
        r--;
    }

    cout << "YES" << endl;


}


int main(){
    int t;
    cin >> t;
    for(int i = 0;i < t ;i++) {
        solve();
    }
}