#include<bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<vector<int>> v(n);  

    for(int i = 0 ;i < n ;i++) {
        int temp;
        cin >> temp;
        int l = 0 , r = n;
        while(l < r) {
            int mid = (l + r) / 2;
            if(v[mid].empty() || v[mid].back() <= temp) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }

        v[l].push_back(temp);
    }

    for(auto &x : v) {
        for(auto &y : x) {
            cout << y << " ";
        }
        cout << endl;
    }


}