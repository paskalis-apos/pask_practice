#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n , k;
    cin >> n >> k;

    int dist_values = 0;
    ll numsubs = 0;
    map<int, int> occs;
    queue<int> q;

    for(int i = 0 ;i < n; i++) {
        int value;
        cin >> value;
        q.push(value);
        if(occs[value] == 0) {
            dist_values++;
        }
        occs[value]++;
        while(dist_values > k) {
            value = q.front();
            q.pop();
            occs[value]--;
            if(occs[value] == 0) {
                dist_values--;
            }
        }

        numsubs += ll(q.size());
    }

    cout << numsubs << endl;
}