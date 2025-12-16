#include<bits/stdc++.h>
using namespace std;

vector<int>barn1(10);
vector<int>barn2(10);
vector<int>pos_readings;
vector<int> cur1;
vector<int> cur2;

void check_case() {
    int sum1 = 0;
    for(auto &a : cur1) {
        sum1 += a;
    }
    if(find(pos_readings.begin(),pos_readings.end(), sum1) == pos_readings.end()) {
        pos_readings.push_back(sum1);
    }
}

void search(int carry) {
    if(carry == 4) {
        check_case();
        return; 
    }
    
    if(carry % 2 == 0) {
        for(int i = 0;i < cur1.size(); i++) {
            int temp = cur1[i];
            cur2.push_back(temp);
            cur1.erase(cur1.begin() + i);
            search(carry + 1);
            cur2.pop_back();
            cur1.push_back(0);
            for(int c = cur1.size() - 1; c >= i + 1; c--) {
                cur1[c] = cur1[c - 1];
            }
            cur1[i] = temp;
        }
    }
    else {
        for(int i = 0;i < cur2.size(); i++) {
            int temp = cur2[i];
            cur1.push_back(temp);
            cur2.erase(cur2.begin() + i);
            search(carry + 1);
            cur1.pop_back();
            cur2.push_back(0);
            for(int c = cur2.size() - 1; c >= i + 1; c--) {
                cur2[c] = cur2[c - 1];
            }
            cur2[i] = temp;
        }
    }

}



int main() {
    freopen("backforth.in","r",stdin);
    freopen("backforth.out","w",stdout);    
    for(auto &x : barn1) {
        cin >> x;
    }
    for(auto &x : barn2) {
        cin >> x;
    }
    cur1 = barn1;
    cur2 = barn2;

    search(0);

    cout << pos_readings.size();
    
}