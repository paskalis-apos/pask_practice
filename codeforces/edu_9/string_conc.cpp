#include<bits/stdc++.h>
using namespace std;

bool comp(string a, string b) {
    return a + b < b + a;
}

int main() {
    int n;
    cin >> n;
    vector<string> inp(n);
    for(auto &x: inp) {
        cin >> x;
    }
    sort(inp.begin(), inp.end(), comp);

    for(auto &x : inp){
        cout << x;
    }

    cout << endl;
}