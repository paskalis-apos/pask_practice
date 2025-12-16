#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int exp(int a, int b) {
    if(b == 0) {
        return 1;
    }
    int ans = exp(a , b / 2);
    if(b % 2 == 1){
        ans *= a;
    }
    return ans;
}

bool choose(int a, int b) {
    if((a | b) > a) {                                                           
        return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v){
        cin >> x;
    }

    for(int i = 0; i < n ;i++) {
        if((!choose(n - 1, i))) {
            v[i] = 0;            
        }
    }
    for(int i = 0 ;i < n-  1;i++) {
        v[i + 1] = v[i] ^ v[i + 1];
    }
 
    cout << v[n - 1] << endl;
}