#include<bits/stdc++.h>
using namespace std;

int to_base_10(int b , int n) {
    return (n % 10) + (n % 100) / 10 * b + n / 100 * b * b;
}

void solve() {
    int nx, ny;
    cin >> nx >> ny;

    for(int x = 10; x <= 15000; x++) {
        int cur = to_base_10(x, nx);
        int l = 10;
        int r = 15000;
        bool valid = false;
        while(l <= r) {
            int mid = (l + r) /2 ;
            if(to_base_10(mid, ny) < cur) {
                l = mid + 1;
            }
            else if(to_base_10(mid, ny) > cur) {
                r = mid - 1;
            }
            else {
                l = mid;
                valid = true;
                break;
            }
            
        }
        if(valid) {
            cout << x << " " << l << endl;
            break;
        }
    }
}

int main() {
    freopen("whatbase.in","r",stdin);
    freopen("whatbase.out","w",stdout);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        solve();
    }
}