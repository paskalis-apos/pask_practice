#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("maxcross.in","r",stdin);
    freopen("maxcross.out","w",stdout);
    int n ,k , b;
    cin >> n >> k >> b;
    vector<int>pref(n+1);
    map<int, bool>broken;

    for(int i = 0;i < b; i++) {
        int temp;
        cin >> temp;
        broken[temp] = true;
    }

    for(int i = 1; i <= n;i ++) {
        pref[i] = pref[i-1] + broken[i];
    }

    int answer = INT_MAX;
    for(int i = 1;i <=n -k + 1 ;i++) {
        int temp = pref[i + k - 1] - pref[i -1];
        answer = min(answer, temp);
    }   

    cout << answer <<endl;
}