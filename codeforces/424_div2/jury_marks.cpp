#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    
    ll k , n;
    cin >> k >> n;

    vector<ll> remember;
    set<ll>values;
    vector<ll>jmarks(k);
    cin >> jmarks[0];
    for(int i = 1; i < k; i++) {
        ll temp;
        cin >> temp;
        jmarks[i] = jmarks[i-1] + temp;
    }
    for(int i = 0; i < n; i++) {
        ll temp;
        cin >> temp;
        remember.push_back(temp);
    }
    set<int> pos_starts;
    for(int i = 0 ;i < k ;i++) {
        pos_starts.insert(remember.front() - jmarks[i]);
    }

    int answer = 0;
    
    for(auto &x : pos_starts) {
        set<int> points;
        for(int i = 0 ;i < k; i++) {
            points.insert(jmarks[i] + x);
        }
        bool valid = true;
        for(int i = 0 ;i < n ;i++) {
            if(!points.count(remember[i])) {
                valid = false;
            }
        }

        answer += valid;
    }
    
    cout << answer;

}
    
    