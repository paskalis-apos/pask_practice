#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int n , k;
pair<int,int> segs;

bool valid(int mid) {   
    vector<int> smallpref(n);
    for(int i = 1 ;i <= n; i++) {
        smallpref[i] = smallpref[i -1];
        if(v[i -1] <= mid) {
            smallpref[i]++;
        }
        else {
            smallpref[i]--;
        }
    }
    int l = 0;
    int r= 0;
    while(r < l) {
        if(r - l + 1 < k) {
            r++;
            continue;
        }

    }
}

void solve() {
    cin >> n >> k;
    v.assign(n , 0);
    for(auto &x : v) {
        cin >> x;
    }
    int l = 0;
    int r = n;
    while(l < r) {
        int mid = (l + r + 1) / 2;
        if(valid(mid)) {
            l = mid;
        }
        else {
            r = mid - 1;
        }
    }


    cout << l << " " << segs.first << " " << segs.second << endl;

}

int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t ;i++) {
        solve();
    }
}