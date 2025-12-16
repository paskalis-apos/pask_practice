#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    string bstr;
    cin >> bstr;
    
    int onerow = 0;
    
    vector<int> ans;
    int minnum = 1;
    int maxnum = n;
    for(int i = 0 ;i < n ;i++) {
        if(bstr[i] == '1') {
            onerow++;
        }
        else {
            onerow = 0;
        }
        if(onerow >= k) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    for(int i = 0;i < n; i++) {
        if(bstr[i] == '1') {
            ans.push_back(minnum);
            minnum++;
        }
        else {
            ans.push_back(maxnum);
            maxnum--;
        }
    }
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