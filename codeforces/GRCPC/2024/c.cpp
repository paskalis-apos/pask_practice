#include<bits/stdc++.h>
using namespace std;

double sx ,sy, tx, ty;
double cx, cy , r;
double total;

bool left(double num) {
    double ans;
    double pi = 2 * acos(0.0);
    double mult = acos(abs(num - cx) / r);
    if(num <= cx - r) {
        ans = num * ty;
    }
    else if(num >= cx + r) {
        ans = num * ty - pi * r * r;
    }
    else {
        double circarea = mult * r * r;
        circarea -= r * r * sin(2 * mult) / 2;
        if(num <= cx) {
            ans = num * ty - circarea;
        }
        else {
            ans = num * ty - pi * r * r + circarea;
        }
    }
    double half = (tx * ty - pi * r * r) / 2;
    if(ans > half) {
        return true;
    }
    return false;
}
int main() {
    cin >> sx >> sy >> tx >> ty;
    cin >> cx >> cy >> r;
    tx -= sx;
    ty -= sy;
    cx -= sx;
    cy -= sy;
    
    double lo = 0, hi = tx;
    while(hi - lo > 0.000001) {
        double mid = (hi + lo) / 2;
        if(left(mid)) {
            hi = mid;
        }
        else {
            lo = mid;
        }
    }

    double ans = hi;
    ans += sx;
    printf("%.4f", ans);

}