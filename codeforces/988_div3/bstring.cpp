#include<bits/stdc++.h>
using namespace std;

void ask(int l, int r) {
    cout << "? " << l << " " << r << endl;
    cout.flush();
}

void solve_case() {
    int n;
    cin >> n;
    vector<int> ans(n);
    int zerocount = 1e6;
    int cur = -1;;
    for(int i = n; i > 1; i--) {
        if(zerocount == 0) {
            ans[i] = 1;
            continue;
        }
        ask(1 , i);
        int temp;
        cin >> temp;
        if(i == n && temp == 0) {
            cout << "! IMPOSSIBLE" << endl;
            cout.flush();
            return;
        }
        if(cur != -1) {
            if(temp == cur) {
                ans[i] = 0;
                zerocount--;
            }
            else {
                zerocount = cur - temp;
                ans[i] = 1;
            }
        }
        cur = temp;
    }
    ask(1 , 2);
    int temp;
    cin >> temp;
    if(zerocount == 2) {
        ans[0] = ans[1] = 0;
    }
    else if(zerocount == 0) {
        ans[0] = ans[1] = 1;
    }
    else {
        if(temp == 1) {
            ans[0] = 0;
            ans[1] = 1;
        }
        else {
            ans[0]= 1;
            ans[1]= 0;
        }
    }
    cout << "! " ; 
    for(auto &x : ans) {
        cout << x;
    }
    cout << endl;
    cout.flush();

}
 
int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t;i++) {
        solve_case();
    }
}