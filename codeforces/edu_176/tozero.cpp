#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n , k;
    cin >> n >> k;

    int answer = 0;

    if(n % 2 == 1) {
        if(k % 2 == 1) {
            if(n <= k) {
                n = 0;
            }
            else {
                n -= k;
            }
        }
        else {
            if(k - 1 >= n) {
                n = 0;
            }
            else {
                n -= k;
            }
        }
        answer++;
    }

    int smax = k - (k % 2);
    int cur = n / smax;
    answer += cur;
    n -= (cur) * smax;
    if(n != 0) {
        answer ++;
    }

    cout << answer << endl;

}

int main() {
    int t;
    cin >> t;
    for(int i = 0 ;i < t ;i++) {
        solve();
    }
}