#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n , k;

vector<pair<int,int>> prime_factorisation(int num) {
    vector<pair<int,int>> v;
    for(ll i = 2;i * i <= num; i++) {
        int divnum = 0;
        while(num % i == 0) {
            num /= i;
            divnum++;
        }
        divnum %= k;
        if(divnum != 0){
            v.push_back({i , divnum});
        }
    }
    if(num > 1) {
        v.push_back({num , 1});
    }
    return v;
}

int main() {
    cin >> n >> k;
    ll pairnum = 0;
    map<vector<pair<int,int>>, int> count;
    for(int i = 0 ;i < n; i++) {
        int num;
        cin >> num;
        vector<pair<int,int>> v = prime_factorisation(num);
        vector<pair<int,int>> tempv;
        for(auto &x : v) {
            tempv.push_back({x.first, (k - x.second)});
        }
        pairnum += count[tempv];
        count[v]++;
    }


    cout << pairnum << endl;
}