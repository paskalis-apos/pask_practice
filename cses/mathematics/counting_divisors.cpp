#include<bits/stdc++.h>
using namespace std;

void solve() {
    int num;
    cin >> num;
    int divisors = 0;
    for(int i = 1; i * i <= num; i++) {
        if(num % i == 0) {
            divisors += 2;
            if(i * i == num) {
                divisors--;
            }
        }
    }

    cout << divisors << endl;
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        solve();
    }
}