#include<bits/stdc++.h>
using namespace std;

int main() {
    int n ,x;
    cin >> n >> x;

    vector<int> pref_nums(n + 1);
    for(int i = 1 ;i <= n ;i++) {
        cin >> pref_nums[i];
        pref_nums[i] += pref_nums[i - 1];
    }
    

    int l = 0 , r = 0;
    int answer = 0;
    while (r <= n) {
        if(pref_nums[r] - pref_nums[l] < x) {
            r++;
        }
        else if(pref_nums[r] - pref_nums[l] > x) {
            l++; 
        }
        else {
            answer++;
            r++;
            l++;
        }
    }

    cout << answer << endl;
}