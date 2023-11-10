#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int n;

bool is_valid(double mid) {
    int     m = 0;
    int i = 1;
    for(;i < n ;i++) {
        int help = v[i] - v[i - 1];
        if(m + 1 > mid) { 
            i--;
            i--;    
            break;
        }
        else {
            m = max(m+1 , help);
            if(m > mid) {
                i--;
                break;
            }
        }
    }
    double temp = v[i] + mid * 2 ;
    for(;i < n && v[i] < temp ; i++) ;

    
    int cur = mid -1;

    for(;i < n; i++) {  
        if(v[i] - v[i - 1] > cur) {
            return false;
        }
        cur--; 
    }
    return true;


}

int main() {
    freopen("angry.in","r",stdin);
    freopen("angry.out","w",stdout);
    cin >> n;
    v.resize(n);

    for(int i = 0; i < n ;i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    double r = 10e9 + 1;
    double l = 0;

    while(r - l > 0.01) {
        double mid = (r + l) / 2;
        if (is_valid(mid)) {
            r = mid;
        }
        else {
            l = mid;
        }
    }

    printf("%.1f", r);
}