#include<bits/stdc++.h>
using namespace std;
int n;
vector<pair<int,int>> v(n);

bool works(double t) {
    double max_left = -INT_MAX;
    double min_right = INT_MAX;
    for(int i =0 ;i < n;i ++) {
        max_left = max(max_left, v[i].first - t * v[i].second);
        min_right = min(min_right, v[i].first + t * v[i].second);
    }

    if(min_right - max_left >= 0) {
        return true;
    }
    return false;
}

int main() {

    cin >> n;

    v.resize(n);
    for(int i = 0 ;i < n;i++) {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end());

    double r = 10e9 + 1;
    double l = 0;

    while(r - l > 0.000001) {
        double t = (r + l) / 2;

        if(works(t)) {
            r = t;
        }
        else {
            l = t;
        }

        
    }

    cout << setprecision(10) << r;

}