#include<bits/stdc++.h>
using namespace std;

int solve() {
    int m , k, a1 , ak;
    cin >> m >> k >> a1 >> ak;

    int exp_coins = m /k;
    int one_coins = m % k;
    if((a1 - one_coins) >= k) {
        exp_coins -= (a1 - one_coins) / k;
        one_coins += ((a1 - one_coins) / k) * k;
    }

    int fancy_coins = max(0 , exp_coins - ak) + max(0 , one_coins - a1);
    return fancy_coins;
}

int main() {
    int t;

    cin >> t;

    for(int i = 0 ;i < t ;i++) {
        cout << solve() << endl;
    }
}