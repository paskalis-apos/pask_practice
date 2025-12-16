#include<bits/stdc++.h>
using namespace std;

string s;
vector<string> answer;
int char_count[26];

void search(string curr) {
    if(curr.size() == s.size()) {
        answer.push_back(curr);
        return;
    }
    for(int i = 0; i < 26 ;i++) {
        if(char_count[i] > 0){
            char_count[i]--;
            search(curr + (char)('a' + i));
            char_count[i]++;
        }   
    }
}


int main() {
    cin >> s;
    for(auto &a : s) {
        char_count[a - 'a']++;
    }

    search("");

    cout << answer.size() << endl;

    for (auto &perm : answer) {
        cout << perm << endl;
    }
    

    

}