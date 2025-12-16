#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int flips = 0;
    for(int i = n - 2 ;i >= 0 ;i-=2) {
        if(s[i] == s[i + 1]) {
            continue;
        }
        if(s[i] == 'G' && s[i+1] == 'H') {
            if(flips % 2 == 0) {
                flips++;
            }
        }
        if(s[i] == 'H' && s[i+1] == 'G') {
            if(flips % 2 == 1) {
                flips++;
            }
        }
    }
    cout << flips;
}