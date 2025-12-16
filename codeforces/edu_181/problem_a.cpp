#include<bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;

    string newstring = "";
    for(auto &x : s){

        if(x == 'T') {
            newstring += x;
        }
    }
    for(auto &x : s) {
        if(x != 'T') {
            newstring += x;
        }
    }

    cout << newstring << endl;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        solve();
    }
}