    #include<bits/stdc++.h>
    using namespace std;
    using ll = long long;

    struct params{
        ll pos, sum, under;
    };

    ll dp[17][180][2];
    string s;

    void reset_dp() {
        for(int i = 0;i <= 16; i++) {
            for(int j = 0; j < 170; j++) {
                for(int k = 0 ; k < 2 ;k++) {
                    dp[i][j][k] = 0;
                }
            }
        }
        dp[0][0][0] = 1;
    }


    ll digitsum_untill(ll num) {
        reset_dp();
        s = to_string(num);
        queue<params> q;
        q.push({0 , 0 , 0 });
        while(!q.empty()) {
            ll pos = q.front().pos;
            ll sum = q.front().sum;
            ll under = q.front().under;
            q.pop();
            if(pos == s.length()){ 
                break;
            }
            for(int i = 0; i <= 9; i++) {
                if(i > s[pos] - '0' && under == 0) {
                    break;
                }
                ll newsum = sum + i;
                ll newunder = under;
                if(i < s[pos] - '0') {
                    newunder = 1;
                }
                ll newpos = pos + 1;
                if(dp[newpos][newsum][newunder] == 0) {
                    q.push({newpos, newsum, newunder});
                }
                dp[newpos][newsum][newunder] += dp[pos][sum][under];
            }
        }
        ll ans = 0;
        for(ll i = 1;i < 170; i++) {
            ans += (dp[s.size()][i][0] + dp[s.size()][i][1]) * i;
        }


        return ans;
    }

    void solve() {
        ll a ,b ;
        cin >> a >> b;
        cout << digitsum_untill(b) - digitsum_untill(a - 1) << endl;
    }

    int main() {
        int t;
        cin >> t;
        for(int i = 0;i < t ;i++) {
            solve();
        }


    }