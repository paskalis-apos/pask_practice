#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("hps.in","r",stdin);
    freopen("hps.out","w",stdout);
    int n;
    cin >> n;
    vector<int>H(n+1), P(n+1), S(n+1);

    for(int i = 1; i <= n; i++) {
        string temp;
        cin >> temp;
        H[i] = H[i-1];
        P[i] = P[i-1];
        S[i] = S[i-1];
        if(temp == "H") {
            H[i]++;
        }
        else if(temp == "P") {
            P[i]++;
        }
        else {
            S[i]++;
        }
    }
    int answer = 0;
    for(int i = 2;i <= n;i++) {
        int max_wins = max(H[i-1], max(P[i-1], S[i-1])) + max((H[n] - H[i-1]), max((P[n] - P[i-1]), (S[n] - S[i - 1])));
        answer = max(answer , max_wins);
    }

    cout << answer << endl;
}