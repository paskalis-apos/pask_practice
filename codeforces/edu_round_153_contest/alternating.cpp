#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    string s ;
    cin >> s;

    vector<int> together;
    together.resize(s.size(), 0);


    int previous = s[0];
    int counter =0;
    int total = 0;
    for(int i = 1; i < s.size(); i++) {
        if(s[i] == previous) {
            together[counter]++;
            total++;
        }
        else {
            previous = s[i];
            if(together[counter] > 0) {
                counter++;
            }

               
        }
    }
    ll answer =1;
    int help = total;
    while (total > 0) {
        answer*= total;
        answer %= 998244353;
        total--;
    }
    for(int i = 0 ;i <+ together.size(); i++) {
        if(together[i] == 0) {
            break;
        }
        answer *= together[i] + 1;
        answer%= 998244353;
    }
    cout << help << ' ';
    return answer;

}

int main() {
    int t;
    cin >> t;

    for(int i= 0 ;i < t ;i++) {
        cout << solve() << endl;
    }

    
}