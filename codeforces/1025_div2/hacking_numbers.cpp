#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n;

void mult(int num) {
    cout << "mul " << num << endl;
    cout.flush();
    int trash;
    cin >> trash;
}

void digit() {
    cout << "digit" << endl;
    cout.flush();
    int trash;
    cin >> trash;
}

void add(int num) {
    cout << "add " << num << endl;
    cout.flush();
    int ans;
    cin >> ans;
}

void solve() {
    cin >> n;
    mult(9);
    digit();
    digit();
    add(n - 9);
    cout << "!" << endl;
    int trash;
    cin >> trash;
    cout.flush();
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t;i++) {
        solve();
    }
}