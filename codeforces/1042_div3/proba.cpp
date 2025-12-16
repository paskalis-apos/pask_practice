#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int diff = 0;
    vector<int> v1(n);
    for(auto &x : v1) {
        cin >> x;
    }
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        diff += max(0 , v1[i] - num);
    }
    diff++;
    cout << diff << endl;

}
int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t ;i++ ){
        solve();
    }
}