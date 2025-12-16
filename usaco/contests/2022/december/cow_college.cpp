#include<bits/stdc++.h>
using namespace std;

int n;

int main()  {
    cin >> n;
    vector<long long> tuition(n);
    for(int i = 0 ;i < n; i++) {
        cin >> tuition[i];
    }
    sort(tuition.begin(), tuition.end());
    long long max_money = 0;
    long long tuit = 0;
    for(int i = 0;i < n; i++) {
        long long money;
        money = (n - i) * tuition[i];
        if(money > max_money) {
            max_money = money;
            tuit = tuition[i];
        }
    }

    cout << max_money<< " " << tuit;

}