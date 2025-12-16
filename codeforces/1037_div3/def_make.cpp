#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n , k;
    cin >> n >> k;
    vector<int> heights(n);
    for(auto &x : heights) {
        cin >> x;
    }
    k = heights[k - 1];
    sort(heights.begin(), heights.end());
    unique(heights.begin(), heights.end());

    int ind = 0;
    int time = 0;
    while(heights[ind] < k) {
        ind++;
    }
        while(ind < heights.size() - 1) {
        int curheight = heights[ind];
        int nextheight = heights[ind + 1];
        if(time + (nextheight - curheight) <= curheight ) {
            ind++;
            time += nextheight - curheight;
        }
        else {
            break;
        }
    }

    if(ind == heights.size() - 1) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    cout << endl;



}


int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t; i++) {
        solve();
    }
}