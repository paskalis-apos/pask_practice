#include<bits/stdc++.h>
using namespace std;

int main() {
    int n , m;
    cin >> n >> m;
    vector<int> v1(n), v2(m);
    for(auto &x : v1) {
        cin >> x;
    }
    for(auto &x : v2) {
        cin >> x;
    }
    vector<int> ans(m);

    int ind1 = 0;
    int ind2 = 0;
    while(ind2 < m) {
        while(ind1 < n && v1[ind1] < v2[ind2]) {
            ind1++;
        }
        ans[ind2] = ind1;
        ind2++;
    }

    for(auto &x : ans) {
        cout << x << " ";
    }

    cout << endl;
}