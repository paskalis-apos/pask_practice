#include<bits/stdc++.h> 
using namespace std;

int main() {
    
    freopen("whereami.in","r",stdin);
    freopen("whereami.out","w",stdout);

    int n;
    cin >> n;

    string seq;
    cin >> seq;

    for(int i = 1 ;i < n + 1 ;i++) {
        bool valid = true;
        map<string,bool>have_seen;
        for(int j = 0;j <= n - i; j++) {
            string sub = seq.substr(j , i);
            if(have_seen[sub]) {
                valid = false;
                continue;
            }
            have_seen[sub] = true;
        }

        if(valid) {
            cout << i;
            return 0;
        }
        
    }
}