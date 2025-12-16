#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;

    int size = s.size();
    vector<int>count(2019);
    ll answer = 0;
    count[0] = 1;
    int num = s[size-1] - '0';
    answer += count[num];
    count[num]++;
    int tenstrength = 10;
    for(int i = size - 2; i >= 0;i--) {
        int temp =  (num + tenstrength * (s[i] - '0')) % 2019;
        answer += count[temp];
        count[temp]++;
        num = temp;
        tenstrength = (tenstrength * 10) % 2019;
    }

    cout << answer;
}