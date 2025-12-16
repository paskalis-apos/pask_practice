#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
vector<double >cords;
vector<double>speeds;

bool valid(double num) {
    double l  = 0, r = 1e9;
    bool good = false;
    while(l < r - 1e-7) {
        double mid = (l + r) / 2;
        bool good = true;
        for(int i = 0; i < n; i++) {
            double distance = abs(mid - cords[i]);
            if(double(distance / speeds[i]) > num ) {
                if(mid > cords[i]) {
                    r = mid;
                }
                else {
                    l = mid;
                }
                good = false;
                break;
            }
        }
        if(good) {
            return true;
        }
    }
    return false;
}


int main() {
    cin >> n;
    cords.resize(n);
    speeds.resize(n);
    for(auto &x : cords) {
        cin >> x;
    }
    for(auto &x : speeds) {
        cin >> x;
    }

    double l = 0;
    double r = 1e9;

    while(l < r - 1e-7) {
        double mid = (l + r) / 2;
        if(valid(mid)) {
            r = mid;
        }
        else {
            l = mid;
        }

    }
    double answer = l;

    printf("%f\n", answer);

}