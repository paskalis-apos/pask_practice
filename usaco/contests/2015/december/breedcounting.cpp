#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("bcount.in","r",stdin);
    freopen("bcount.out","w",stdout);
    int n , q;
    cin >> n >> q;

    vector<int> ones(n + 1), twos(n + 1), threes(n + 1);

    for(int i = 1 ;i <= n; i++) {
        ones[i] = ones[i -1];
        twos[i] = twos[i -1];
        threes[i] = threes[i - 1];
        int help;
        cin >> help;
        if(help == 1) {
            ones[i]++;
        }
        else if(help == 2) {
            twos[i]++;
        }
        else {
            threes[i]++;
        }
    }

    for(int i = 0;i < q ;i++) {
        int l , r;
        cin >> l >> r;
        l--;

        int a1 , a2 , a3;

        a1 = ones[r]- ones[l];
        a2 = twos[r] - twos[l];
        a3 = threes[r] - threes[l];

        cout << a1 << " " << a2 << " "<< a3 << endl;
    }
}