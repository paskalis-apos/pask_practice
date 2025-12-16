#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v) {
        cin >> x;
    }

    sort(v.begin(), v.end());

    ll val = 0;
    for(auto &x : v) {
        if(x > val + 1) {
            break;
        }
        val += x;
    }
    val++;

    cout << val << endl;
}