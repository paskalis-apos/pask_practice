#include<bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    int childrennum , maxweight;
    cin >> childrennum >> maxweight;

    vector<int>weights(childrennum);
    for(auto &x : weights) {
        cin >> x;
    }
    sort(weights.begin(), weights.end());
    int l = 0, r = childrennum - 1;
    int answer = 0;
    while(l < r) {
        if(weights[r] + weights[l] <= maxweight) {
            r--; 
            l++;
        }
        else {
            r--;
        }
        answer++;
    }
    if(r == l) {
        answer++;
    }
    cout << answer << endl;
}