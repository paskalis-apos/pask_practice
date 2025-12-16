#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int prev = -1;
    bool starting = true;
    bool valid = true; 
    for(int i = 0 ;i < n; i++) {
        int num;
        cin >> num;
        if(num == 0) {
            valid = false;;
        }
        if(num != -1 && starting) {
            prev = num;
            starting = false;
            continue;
        }
        if(num != prev && num != -1 ) {
            valid = false;

        }
    }

    if(valid) {
        cout << "YES";
    }
    else {
        cout << "NO";
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