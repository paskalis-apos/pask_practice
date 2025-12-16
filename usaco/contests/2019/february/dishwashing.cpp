#include<bits/stdc++.h>
using namespace std;

int main( ) {
    freopen("dishes.in","r",stdin);
    freopen("dishes.out","w",stdout);
    int n;
    cin >> n;
    vector<int> bases(n + 1);
    vector<stack<int>> items(n + 1);

    int placed = 0;
    int ans = 0;

    for(int i = 0 ;i < n; i++) {
        int x;
        cin >> x;

            ans = i;
        if(x < placed) {
            break;
        }

        for(int j = x; j> 0 && !bases[j]; j--) {
            bases[j] = x;
        }

        while(!items[bases[x]].empty() && items[bases[x]].top() < x) {
            placed = items[bases[x]].top();
            items[bases[x]].pop();
        }

        items[bases[x]].push(x);
    }

    cout << ans << endl;


}