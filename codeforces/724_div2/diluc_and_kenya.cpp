#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;
    map<pair<int,int>, int> occs;
    int K = 0;
    int D = 0;
    for(auto &x : s) {
        if(x == 'D') {
            D++;
        }
        else {
            K++;
        }

        int curgcd = gcd(D , K);
        int newD = D / curgcd;
        int newK = K / curgcd;
        occs[{newD , newK}]++;
        
        int ans;
        ans = occs[{newD , newK}];

        cout << ans << " ";
        
    }


    cout << endl;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0 ;i < t; i++) {
        solve();
    }
}