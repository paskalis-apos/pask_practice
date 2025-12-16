#include<bits/stdc++.h>
using namespace std;

void solve(){ 
    int n;
    cin >> n;
    vector<int> occs(n + 1);
    for(int i = 0;i < n; i++) {
        int num;
        cin >> num;
        occs[num]++;
    }
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        int temp = 0;
        for(int j = 1;j <= n;j++) {
            if(occs[j] >= i) {
                temp += i;
            }
        }
        ans = max(ans, temp);
    }

    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t;i++) {
        solve();
    }
}