#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll slices , maxsalty;
    cin >> slices >> maxsalty;  

    vector<ll> salt(slices);
    for(auto &x : salt) {
        cin >> x;
    }

    for(int i = 0;i < slices ; i++) {
        if(i != 0) {
            salt[i] = max(salt[i], salt[i - 1] - maxsalty);
        }
        if(i != slices -1) {
            salt[i] = max(salt[i], salt[i + 1] - maxsalty);
        }
    }

    for(int i = slices - 1; i >= 0; i--) {
        if(i != 0) {
            salt[i] = max(salt[i], salt[i - 1] - maxsalty);
        }
        if(i != slices -1) {
            salt[i] = max(salt[i], salt[i + 1] - maxsalty);
        }
    }

    for(auto &x : salt) {
        cout << x << " ";
    }
    cout << endl;




}