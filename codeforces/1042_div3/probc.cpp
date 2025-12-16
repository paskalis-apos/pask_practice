#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n , k;
    cin >> n >> k;
    bool skip = false;
    multiset<int> s;

    for(int i = 0 ;i < n; i++){ 
        int num;
        cin >> num;
        num %= k;
        s.insert(num);
    }
    for(int i =0 ;i < n; i++) {
        int num;
        cin >> num;
        num %= k;
        if(s.find(num) != s.end()) {
            s.erase(s.find(num));
        }
        else if(s.find(k - num) != s.end()) {
            s.erase(s.find(k - num));
        }
        else {
            skip = true;
        }
    }
    if(skip) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;

}
int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t ;i++ ){
        solve();
    }
}