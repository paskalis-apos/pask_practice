#include<bits/stdc++.h>
using namespace std;

string solve(string substr) {
    string answer;
    if(substr == "()") {
        return "NO";
    }
    cout << "YES" << endl;

    bool right_after = true;
    bool reached = false;
    int i = 0;
    for( ;i < substr.size(); i++) {
        if(reached) {
            if(substr[i] == '(') {
                right_after = false;
                break;
            }
            continue;
        }
        if(substr[i] == ')') {
            reached = true;
        } 
    }
        if(right_after) {
            for(int c = 0 ; c < substr.size() * 2; c++) {
                if(c % 2 == 0) {
                    answer.push_back('(');
                }
                else {
                    answer.push_back(')');
                }
            }
        }
        else {
            for(int c = 0; c < substr.size() * 2 ;c++) {
                if(c < substr.size()) {
                    answer.push_back('(');
                }
                else {
                    answer.push_back(')');
                }
            }
        }
        return answer;

}

int main() {
    int t;
    cin >> t;

    for(int i = 0 ;i < t; i++) {
        string substr;
        cin >> substr;

        cout << solve(substr) << endl;
    }
}