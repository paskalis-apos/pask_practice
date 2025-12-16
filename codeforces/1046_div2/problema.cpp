#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int a , b , c , d;
    cin >> a >> b >> c >> d;

    if(a < b) {
        swap(a , b);
        swap(c , d);
    }

    if(2 * b + 2 < a){
        cout << "NO" << endl;
        return;
    }
    c -= a;
    d -= b;
    if(c < d){
        swap(c , d);
    }
    if(2 * d + 2 < c) {

        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
}
int main(){
    int t;
    cin >> t;
    for(int i = 0;i < t; i++) {
        solve();
    }
}