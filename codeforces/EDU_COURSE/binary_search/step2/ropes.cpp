#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n , k;
    cin >> n >> k;
    ll totlength = 0;

    vector<int> ropes(n) ;
    for(int i = 0 ;i < n;i++) {
        cin >> ropes[i];
        totlength += ropes[i];
    }

    double l = 0;
    double r = (totlength / k) + 1;

    while (r - l > 1e-7) {
        double mid = (r + l) / 2;
        ll pieces = 0;

        for(int i = 0 ;i < n ;i++) {
            pieces += ropes[i] / mid;   
        }
        if(pieces >= k) {
            l = mid;
        }
        else { 
            r = mid;
        }
    }

    cout << setprecision(10) << l << endl;

    

}