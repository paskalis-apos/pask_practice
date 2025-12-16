#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n , q;
    cin >> n >> q;
    string s;
    cin >> s;

    int ca = 0;
    int ba = 0;
    int bca = 0;
    int cba = 0;
    int cb = 0;
    int bc = 0;

    for(int i = 0;i < q; i++) {
        char x, y;
        cin >> x >> y;
        if(x == 'a') {
            continue;
        }
        if(x == 'b') {
            if(y == 'a') {
                ba++;
                if(cb > cba) {
                    cba++;
                }
            }
            else if(y == 'c') {
                bc++;
            }
        }
        else {
            if(y == 'a') {
                ca++;
                if(bc > bca) {
                    bca++;
                }
            }
            else if(y == 'b') {
                cb++;
            }   
        }
    }
    string ans;
    for(auto &x : s){
        char put; 
        if(x == 'a') {
            put = 'a';
        }
        else if(x == 'b') {
            if(ba > 0) {
                put = 'a';
                ba--;
                cba = min(cba, ba);
            }
            else if(bca > 0) {
                put = 'a';
                bca--;
                ca--;
                bc--;
            }
            else {
                put = 'b';
            }
        }
        else {
            if(ca > 0) {
                put = 'a';
                ca--;
                bca = min(bca, ca);
            }
            else if(cba > 0) {
                cba--;
                cb--;
                ba--;
                put = 'a';
            }
            else if(cb > 0){
                cb--;
                cba = min(cb, cba);
                put = 'b';
            }
            else {
                put = 'c';
            }
        }
        ans += put;
    }

    cout << ans << endl;    
    
}

int main() {
    int t;
    cin >> t;
    for(int i = 0 ;i < t ;i++) {
        solve();
    }
}