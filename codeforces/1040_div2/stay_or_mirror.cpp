#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> perm(n);
    for(auto &x : perm) {
        cin >> x;
    }

    for(int i = 1; i <= n; i++) {
        int index = 0;
        int tosave = 0;
        int toruin = 0;
        int THEindex = 0;
        while(perm[index] != i) {
            if(perm[index] > i && perm[index] <= n) {
                tosave++;
            }
            index++;
        }
        THEindex = index;
        while(index < n) {
            if(perm[index] > i && perm[index] <= n) {
                toruin++;
            }
            index++;
        }

        if(tosave > toruin) {
            perm[THEindex] = 2 * n - i;
        }
    }
    int answer = 0;
    for(int i = 0;i < n ;i++) {
        int cur = perm[i];
        int ind = 0;
        while(ind < n) {
            if(ind < i && perm[ind] > perm[i] || ind > i && perm[ind] < perm[i]) {
                answer++;
            }
            ind++;
        }
    }
        answer /= 2;
        cout << answer << endl;
        
}

int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t ;i++) {
        solve();
    }
}