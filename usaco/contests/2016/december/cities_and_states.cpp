#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {

    freopen("citystate.in","r",stdin);
    freopen("citystate.out","w",stdout);
    
    int n;
    cin >> n;

    vector<pair<string,string>>pairs(n);
    for(int i = 0 ;i < n; i++) {
        string city;
        string state;
        cin >> city >> state;
        city = city.substr(0 ,2);
        pairs[i] = {{city},{state}};
    }

    map<string,int> haveseen;
    ll total = 0;
    for(auto &x : pairs) {
        string to_search = x.second + x.first;
        if(x.first != x.second) {total += haveseen[to_search];}
        haveseen[x.first + x.second]++;
    }

    cout << total;
}