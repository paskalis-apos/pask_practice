#include<bits/stdc++.h>
using namespace std;
double c ;

bool works(double num) {
    if(num * num + sqrt(num) >= c) {
        return true;
    }
    return false;
}

int main() {
    cin >> c;

    double l = 0 ; 
    double r = sqrt(c);

    while (r - l > 0.00000001) {
        double mid = (r + l) / 2;
        if(works(mid)) {
            r = mid;
        }
        else {
            l = mid;
        }
    }

    cout << setprecision(10) << r;
}