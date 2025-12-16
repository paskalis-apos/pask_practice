#include<bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    int n;
    cin >> n;
    vector<int> cows(n);
    vector<int> barns(n);

    for(auto &x : cows) {
        cin >> x;
    }
    for(auto &x : barns) {
        cin >> x;
    }

    sort(cows.begin(), cows.end());
    sort(barns.begin(), barns.end());
    
    int ind1 = 0;
    int ind2 = 0;
    ll ans = 1;
    while(ind2 < n){ 
        while(ind1 < n && cows[ind1] <= barns[ind2]) {
            ind1++;
        }
        ans *= (ind1 - ind2);
        ind2++;
    }

    cout << ans << endl;

}