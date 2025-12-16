#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n , s;
    cin >> n >> s;

    vector<int> v(n);
    int totalsum = 0;
    for(auto &x : v) {
        cin >> x;
        totalsum += x;
    }

    if(totalsum > s) {
        for(auto &x : v) {
            cout << x << " ";
        }
        cout << endl;
    }
    else if(totalsum <= s - 2 || totalsum == s) {
        cout << -1 << endl;
    }
    else {
        vector<int> answer;
        for(auto &x : v){
            if(x == 0) {
                answer.push_back(0);
            }
        }
        for(auto &x : v) {
            if(x == 2) {
                answer.push_back(2);
            }
        }
        for(auto &x : v){
            if(x == 1) {
                answer.push_back(1);
            }
        }
        for(auto &x : answer) {
            cout << x << " ";
        }
        cout << endl;
    }

}

int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t; i++) {
        solve();
    }
}