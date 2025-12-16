#include<bits/stdc++.h>
using namespace std;
using ll = long long;


void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> v(n);
    vector<bool> letgo(n);
    for(int i = 0;i < n;i++) {
        int num;
        int keep ;
        cin >> num;
        keep = num;
        int moves = 0;
        while(num > 1){
            int temp = num / 2 ;
            moves++;
            if(temp == 1) {
                break;
            }
            num = temp + 1;
        }
        v[i] = moves;
        if(keep == (1 << moves) + 1) {
            letgo[i] = true;
        }
    }

    vector<int> preflet(n + 1);
    vector<int> prefval(n + 1);
    for(int i = 1; i <= n;i++) {
        preflet[i] = preflet[i - 1] + letgo[i - 1];
        prefval[i] = prefval[i - 1] + v[i - 1];
    }

    for(int i = 0;i < q; i++) {
        int l, r;
        cin >> l >> r;
        int ans = prefval[r] - prefval[l - 1];
        ans += (preflet[r] - preflet[l - 1]) / 2;
        cout << ans << endl;
    }


}

int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t; i++) {
        solve();
    }
}