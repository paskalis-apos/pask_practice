#include<bits/stdc++.h>
using namespace std;

int main() {
    int n , k , q;
    cin >> n >> k >> q;
    vector<int> diff(2e5 + 2);

    for(int i = 0 ;i < n ;i++) {
        int l , r;
        cin >> l >> r;
        diff[l]++;
        diff[r + 1]--;
    }

    vector<pair<int,int>> queries(q);
    int counter = 0;
    for(int i = 1; i <= 2e5;i++) {
        counter += diff[i];
        if(counter >= k){
            diff[i] = 1;
        }
        else {
            diff[i] = 0;
        }
        diff[i] += diff[i - 1];
    }

    for(int i = 0 ;i < q; i++) {
        int l , r;
        cin >> l >> r;
        int answer = diff[r] - diff[ l - 1];
        cout << answer << endl;
    }

}