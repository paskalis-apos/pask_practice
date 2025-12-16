#include<bits/stdc++.h>
using namespace std;

void solve() {
    double n , d, h;
    cin >> n >> d >> h;
    vector<double> heights(n + 1);
    for(int i = 0 ;i < n; i++) {
        cin >> heights[i];
    }
    heights[n] = 1e11;

    sort(heights.begin(), heights.end());
    double sum = 0;
    double index = 0;
    double base = d;
    while(index < n) {
        double hei= (heights[index + 1] - heights[index]);
        hei = min(h , hei);
        double sbase = ((h - hei) / h) * d;
        sum += double(base + sbase) / 2 * hei;
        index++;
    }

    printf("%.7lf\n", sum);
}

int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t; i++) {
        solve();
    }
}