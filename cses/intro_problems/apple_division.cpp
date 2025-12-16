#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n ;
vector<ll> apples;

ll min_dif(ll sum1, ll sum2, int i) {
    if(i == n) {
        return abs(sum1- sum2);
    }
    return(min(min_dif(sum1 + apples[i], sum2, i + 1),
               min_dif(sum1, sum2 + apples[i], i + 1)));
}

int main() {
    cin >> n;
    for(int i = 0; i< n ;i++) {
        int a ;
        cin >> a;
        apples.push_back(a);
    }

    cout << min_dif (0, 0 , 0) << endl;


}