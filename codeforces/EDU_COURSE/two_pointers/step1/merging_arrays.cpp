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
    int ind1 = 0;
    int ind2 = 0;
    vector<int> ans;
    while(ind1 < n || ind2 < m) {
        if(ind1 == n) {
            ans.push_back(v2[ind2]);
            ind2++;
            continue;
        }
        if(ind2 == m) {
            ans.push_back(v1[ind1]) ;
            ind1++;
            continue;
        }
        if(v1[ind1] <= v2[ind2]) {
            ans.push_back(v1[ind1]) ;
            ind1++;
        }
        else {
            ans.push_back(v2[ind2]) ;
            ind2++;
        }
    }

    for(auto &x : ans) {
        cout << x << " ";
    }

    cout << endl;   
}