#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int k , n;
    cin >> k >> n;

    ll dist = 0;
    vector<pair<int,int>> subsegs;   
    for(int i = 0 ; i < n; i++){
        char p , q;
        int s, t;
        cin >> p >> s >> q >> t;
        if(p == q) {
            dist += abs(s - t);
        }
        else {
            subsegs.push_back({p , q});
        }

    }
}