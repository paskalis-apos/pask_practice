#include<bits/stdc++.h>
using namespace std;



void solve() {
    int n;
    cin >> n;
    vector<int> bosses(n + 1);
    for(int i = 1 ;i < n + 1; i++) {
        cin >> bosses[i];
    }
    vector<int>myfirst(n + 1, 1e9);
    vector<int>mysecond(n + 1, 1e9);
    vector<int>hisfirst(n + 1, 1e9);
    vector<int>hissecond(n + 1, 1e9);

    hisfirst[1] = (bosses[1] == 1);
    for(int i = 2; i <= n ;i++) {
        myfirst[i] = min(hisfirst[i - 1], hissecond[i -1]);
        mysecond[i] = myfirst[i - 1];
        hisfirst[i] = min(myfirst[i -1], mysecond[i -1]) + (bosses[i] == 1);
        hissecond[i] = hisfirst[i -1] + (bosses[i] == 1);
    }

    int answer = min(myfirst[n], min(mysecond[n], min(hisfirst[n], hissecond[n])));

    cout << answer << endl;
    
}


int main() {
    int t;
    cin >> t;
    for(int i = 0 ;i < t;i++) {
        solve();
    }
}