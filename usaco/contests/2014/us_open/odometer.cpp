#include<bits/stdc++.h>
using namespace std;
using ll = long long;

string num;
ll dp[19][50][2][2];

void reset(){
    for(int i = 0;i < 19; i++) {
        for(int j = 0; j < 50; j++) {
            for(int k = 0; k < 2;k ++){
                for(int z = 0; z < 2 ;z++) {
                    dp[i][j][k][z] = -1;
                }
            }
        }
    }
}

ll solve_dp(int pos, int k, bool under, bool started, int targ, int targ2) {
    if(pos == num.size()) {
        if(!started) {
            return 0;
        }
        if(targ2 != -1) {
            if(k == 20) {
                return 1;
            }   
            else {
                return 0;
            }
        }
        if(k >= 20){
            return 1;
        }
        else {
            return 0;
        }
    }

    if(dp[pos][k][under][started] != -1) {
        return dp[pos][k][under][started];
    }

    ll ans = 0;
    for(int i = 0 ;i <= 9 ;i++) {
        int digit = num[pos] - '0';
        if(!under && digit < i) {
            break;
        }
        bool is_under = under;
        if(i < digit) {
            is_under = true;
        }

        bool is_started = started || i != 0;
        if(is_started && targ2 != -1 && i != targ && i != targ2) {
            continue;
        }
        int new_k = k;
        if(is_started) {
            if(targ == i) {
                new_k = k + 1;
            }
            else {
                new_k =  k - 1;
            }
        }
        ans += solve_dp(pos + 1, new_k, is_under, is_started, targ, targ2);
    }
    return dp[pos][k][under][started] = ans;
}

ll find_interesting(ll ubound) {
    num = to_string(ubound);
    ll ans = 0;
    ll duplicates = 0;
    for(int i = 0;i <= 9 ;i++) {
        reset();
        ans += solve_dp(0, 20, false, false, i , -1);
        for(int j = 0;j <= 9; j++) {
            reset();
            duplicates += solve_dp(0 , 20, false, false, i , j);
        }
    }


    return ans - (duplicates / 2);
}


int main () {
    freopen("odometer.in","r",stdin);
    freopen("odometer.out","w",stdout);
    ll x, y;
    cin >> x >> y;

    cout << find_interesting(y) - find_interesting(x - 1) << endl;
}