#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    n = 2* n;


    vector<int>weights(n);
    for(int i = 0 ;i < n;i++) {
        cin >> weights[i];
    }

    sort(weights.begin(),weights.end());

    int min_instability = INT_MAX;  

    for(int i = 0 ;i < n; i++) {
        for(int j = i + 1; j < n ;j++) {
            int instability = 0;
            for(int take = 0; take < n - 1; take += 2) {
                if(take == i || take == j) {
                    take--;
                    continue;
                }
                if(take + 1 == i || take + 1 == j) {
                    if(take +2 == j) {
                        instability += weights[take + 3] - weights[take];
                        take++;
                    }
                    else {
                        instability += weights[take + 2] - weights[take];
                    }
                    take++;
                }

                else {
                    instability += weights[take + 1]- weights[take];
                }
            }
            min_instability = min(instability, min_instability);
        }
        
    }

    cout << min_instability;
}