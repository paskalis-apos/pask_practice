#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> divcount(2 * 1e5 + 10);
    int maxdivcount = 0;
    int prevmax = n;
    for(int i = 0;i < n;i++){ 
        int num;    
        cin >> num;
        int newmax = 0;
        for(int j = 1; j * j <= num; j++) {
            if(num % j == 0) {
                divcount[j]++;
                if(j != 1) {
                    if(divcount[j] == i + 1) {
                        newmax++;
                    }
                    else {
                        maxdivcount = max(maxdivcount, divcount[j]);
                    }
                }
                if(j * j == num) {
                    continue;
                }
                divcount[num / j]++;
                if(divcount[num / j] == i + 1) {
                    newmax++;
                }
                else{
                    maxdivcount = max(maxdivcount, divcount[num / j]);
                }
            }
        }
        if(newmax < prevmax) {
            maxdivcount = i;
        }
        prevmax = newmax;
        cout << maxdivcount << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t ;i++) {
        solve();
    }
}