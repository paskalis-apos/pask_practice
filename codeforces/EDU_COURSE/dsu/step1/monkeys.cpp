#include<bits/stdc++.h>
using namespace std;

vector<int> p(2 * 1e5 + 5);

int main() {
    int n , m;
    cin >> n >> m;
    for(int i = 1 ;i <= n;i++) {
        int l , r;
        cin >> l >> r;
        p[l] = p[i];
        p[r] = p[i];
    }

    
}