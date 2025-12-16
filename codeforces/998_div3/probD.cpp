#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int>numbers(n);
    for(auto &x : numbers) {
        cin >> x;
    }

    for(int i = 0 ;i < n -1 ;i ++) {
        int tmin = min(numbers[i], numbers[i + 1]) ;
        numbers[i] -= tmin;
        numbers[i + 1] -= tmin;
    }

    bool valid = true;
    for(int i = 0 ;i < n -1 ; i++ ) {
        if(numbers[i + 1] < numbers[i]) {
            valid = false;
            break;
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
    for(int i = 0; i < t; i++ ){
        solve();
    }
}