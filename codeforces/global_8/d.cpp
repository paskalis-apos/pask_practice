#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main( ){
    int n;
    cin >> n; 
    vector<int> v(n);
    for(auto &x : v) {
        cin >> x;
    }

    vector<int> bitocc(21);
    for(auto &x : v) {
        for(int i = 0; i <= 20; i++) {
            if((x | (1 << i)) == x) {
                bitocc[i]++;
            }
        }
    }

    ll ans = 0;
    while(true) {   
        ll temp = 0;
        for(int i = 0;i <= 20; i++) {
            if(bitocc[i] == 0) {
                continue;
            }
            bitocc[i]--;
            temp += (1 << i);
        }
        temp *= temp;
        ans += temp;
        if(temp == 0) {
            break;
        }
    }

    cout << ans << endl;
}