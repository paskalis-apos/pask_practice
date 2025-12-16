#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    freopen("div7.in","r",stdin);
    freopen("div7.out","w",stdout);

    int n;
    cin >> n;
    vector<int> cowsum(n + 1);
    for(int i = 1 ;i <= n ; i++) {
        int temp;
        cin >> temp;
        cowsum[i] = cowsum[i - 1] + temp;
        cowsum[i] %= 7;
    }

    int r = 1;
    int l = 0;
    int answer = 0;
    for(int i = 0;i <7; i++) {
        int appear1 = -1;
        int appear2 = -1;
        for(int j = 0; j <= n ; j++) {
            if(cowsum[j] == i) {
                if(appear1 != -1) {
                    appear2 = j; 
                }
                else {
                    appear1 = j;
                }
            }
            if(appear1 != -1 && appear2 != -1) {
                answer = max(answer, appear2 - appear1);
            }
        }
    }
    cout << answer;
}