#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n , m , k;
    cin >> n >> m >> k;

    if(abs(m - n) > k ) {
        cout << -1 << endl;
        return;
    }
    if(max(m , n) < k) {
        cout << -1 << endl;
        return;
    }

    string ans = "";
    bool reached = false;
    int diff = 0;
    bool more1 = (m > n);
    bool onestart = false;
    bool twostart = false;
    while(n > 0 || m > 0) {
        if(reached == false){
            if(more1) {
                ans += "1";
                m--;
            }
            else {
                ans += "0";
                n--;
                
            }
            diff++;
            if(diff == k) {
                reached = true;
                if(more1) {
                    twostart = true;
                }
                else {
                    onestart = true;
                }
            }
        }
        else{
            if((onestart == true &&  m > 0) || n <= 0) {
                ans += "1";
                twostart = true;
                onestart = false;
                m--;
            }
            else {
                ans += "0";
                onestart = true;
                twostart = false;
                n--;
            }

        }   
    }

    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0 ;i < t; i++) {
        solve();
    }
}