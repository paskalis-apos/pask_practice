#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> freq(1e6 + 1);

    int n;
    cin >> n;
    for(int i = 0 ;i < n; i++) {
        int num;
        cin >> num;
        freq[num]++;
    }

    for(int i = 1e6; i >= 1; i--) {
        int count = 0;
        for(int j = i;j <= 1e6; j += i) {
            count += freq[j];
        }   
        if(count >= 2) {
            cout << i << endl;
            return 0;
        }
    }
}