#include<bits/stdc++.h>
using namespace std;

void solve() {
    int a1 , a2 , a4 ,a5;
    cin >> a1 >> a2 >> a4 >> a5;
    int a3 = a1 + a2;
    int fib = 1;
    if(a2 + a3 == a4) {
        fib++;
    }
    if(a3 + a4 == a5) {
        fib++;
    }
    int fib2 = 1;
    a3 = a4 - a2;
    if(a1 + a2 == a3) {
        fib2++;
    }
    if(a3 + a4 == a5) {
        fib2++;
    }
    cout << max(fib, fib2) << endl;

}


int main() {
    int t;
    cin >> t;
    for(int i = 0 ;i < t ;i ++) {
        solve();
    }
}