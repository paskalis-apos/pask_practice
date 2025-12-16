#include<bits/stdc++.h>
using namespace std;
using ll = long long;


void solve() {
    int n;
    cin >> n;


    int havefound = 0;
    vector<int> prevans(2 * n + 1);
    for(int i = 2;i <= 2 * n ;i++) {
        cout << "? " << i - havefound<< " ";
        for(int j = 1; j<= i;j ++) {
            if(prevans[j] != 0) {
                continue;
            }
            cout << j << " ";
        }
        cout << endl;
        cout.flush();
        int num;
        cin >> num;
        if(num != 0) {
            prevans[i] = num;
            havefound++;
        }
    }
    havefound = 0;
    vector<int> ans(2 * n + 1);
    for(int i= 2 *n; i > 0; i--) {
        if(prevans[i] != 0) {
            continue;
        }
        cout << "? " << 2 * n - i + 1 - havefound<< " ";
        for(int j = 2 * n; j >= i;j --) {
            if(ans[j] != 0) {
                continue;
            }
            cout << j << " ";
        }
        cout << endl;
        cout.flush();
        int num;
        cin >> num;
        if(num != 0) {
            havefound++;
            ans[i] = num;
        }
    }
    for(int i = 1; i<= 2 * n; i++) {
        ans[i] = max(ans[i], prevans[i]);
    }
    
    cout << "! ";
    for(int i = 1;i <= 2* n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    cout.flush();
}


int main(){
    int t;
    cin >> t;
    for(int i = 0;i < t ;i++) {
        solve();
    }
}