#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    vector<int> occs(n);
    for(int i = 0 ;i < n; i++) {
        int temp ;
        cin >> temp;
        temp--;
        occs[temp] =i;
    }
    int answer = 1;

    for(int i = 0 ;i < n - 1; i++) {
        if(occs[i] > occs[i + 1]) {
            answer++;
        }
    }

    cout << answer << endl;

}