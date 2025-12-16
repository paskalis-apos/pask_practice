#include<bits/stdc++.h>
using namespace std;

void solve_case() {
    int k;
    cin >> k;

    int gridsize = k - 2;
    vector<bool> appeared(k + 1) ;
    for(int i = 0;i < k; i++) {
        int temp;
        cin >> temp;
        appeared[temp] = true;
    }
    for(int i = 1; i<= k;i ++) {
        if(gridsize % i == 0) {
            if(appeared[i] && appeared[gridsize/i]) {
                cout << i <<" " << gridsize/i << endl;
                return;
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    for(int i = 0 ;i < t;i++) {
        solve_case();
    }
}