        #include<bits/stdc++.h>
        using namespace std;
        using ll = long long;
        int n , q;
        vector<ll> prefsum;
        vector<ll> prefxor;
        ll l , r;
        ll maxvalue ;
         
        bool valid(ll mid) {
            l = 1, r = mid;
            while(r <= n) {
                ll cursum = prefsum[r] - prefsum[l - 1];
                ll curxor = prefxor[r] ^ prefxor[l - 1];
                ll cur = cursum - curxor;
                if(cur == maxvalue) {
                    return true;
                }
                r++;
                l++;
            }
            return false;
        }
         
        void solve() {
            cin >> n >> q;
            vector<ll>v(n);
            for(auto &x : v) {
                cin >> x;
            }
            ll trash1 , trash2;
            cin >> trash1 >> trash2;
            prefsum.assign(n + 1, 0);
            prefxor.assign(n + 1, 0);
            prefsum[0] = 0;
            prefxor[0] = 0;
            for(int i = 1; i <= n ;i++) {
                prefsum[i] = prefsum[i -1] + v[i -1];
                prefxor[i] = prefxor[i - 1] ^ v[i - 1];
            }
         
            maxvalue = prefsum[n] - prefxor[n];
            ll low = 1, high = n;
            ll ind1 = 1;
            ll ind2 = 1;
            while(low <= high) {
                int mid = (low + high) / 2;
                if(valid(mid)) {
                    high = mid - 1;
                    ind1 = l;
                    ind2 = r;
                }
                else {
                    low = mid + 1;
                }
            }
            cout << ind1<< " " << ind2 << endl;
         
         
        }
         
        int main() {
            int t;
            cin >> t;
            for(int i = 0 ;i < t ;i++) {
                solve();
            }
        }
         
        int main() {
            int t;
            cin >> t;
            for(int i = 0 ;i < t ;i++) {
                solve();
            }
        }