#include<bits/stdc++.h>
using namespace std;

int main() {

    freopen("outofplace.in","r",stdin);
    freopen("outofplace.out","w",stdout);
    
    int n;
    cin >> n;

    vector<int> cows(n);
    for(auto &x : cows) {
        cin >> x;
    }
    auto perfcows = cows;
    sort(perfcows.begin(),perfcows.end());
    int diff = 0;
    for(int i = 0;i < n;i++) {
        if(cows[i] != perfcows[i]) {
            diff++;
        }
    }

    
    cout << max(0,--diff) << endl;
}