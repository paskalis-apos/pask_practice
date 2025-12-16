#include<bits/stdc++.h>
using namespace std;

int main( ){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n , m;
    cin >> n >> m;
    vector<int> v(n);
    map<int,vector<int>> ans;
    for(int i = 1;i <= n;i++){
        int num;
        cin >> num;
        int times = (num - 1) / m;
        ans[times].push_back(i);
    }


   for(auto &x : ans) {
        for(auto &y : x.second) {
            cout << y << " ";
        }
   }

   cout << endl;
}