#include<bits/stdc++.h>
using namespace std;

void solve_case()  {
    int stnum, topnum;
    cin >> stnum >> topnum;

    vector<int> students(stnum);
    for(auto &x : students) {
        cin >> x;
    }

    sort(students.begin(), students.end());
    vector<int>topics(topnum + 1);
    int know_topics = 0;

    int l = 0;
    int r = -1; 
    int mindiff = INT_MAX;
    bool can_do = false;
    while(r < stnum) {

        if(know_topics < topnum) {
            r++;
            int counter = 1;
            while(counter * counter <= students[r]) {
                if(students[r] % counter == 0) {
                    if(counter <= topnum) {
                        topics[counter] ++;
                    }
                    if(students[r] / counter <= topnum && counter * counter != students[r]) {
                        topics[students[r] / counter]++;
                    }
                    if(counter <= topnum && topics[counter] == 1) {
                        know_topics++;
                    }
                    if(students[r] / counter <= topnum && topics[students[r] / counter] == 1 && counter * counter != students[r])  {
                        know_topics++;
                    }
                }
                counter++;

            }

        }
        else {
            can_do = true;
            mindiff = min(mindiff, students[r] - students[l]);
            int counter =1;
            while(counter * counter <= students[l]) {
                if(students[l] % counter == 0) {
                    if(counter <= topnum) {
                        topics[counter] --;
                    }
                    if(students[l] / counter <= topnum  && counter * counter != students[l]) {
                        topics[students[l] / counter]--;
                    }
                    if(counter <= topnum && topics[counter] == 0) {
                        know_topics--;
                    }
                    if(students[l] / counter <= topnum && topics[students[l] / counter] == 0 && counter * counter != students[l])  {
                        know_topics--;
                    }
                }
                counter++;
            }
            l++;
        }
    }
    if(!can_do) {
        cout << -1 << endl;
        return;
    }
    cout << mindiff << endl;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0 ;i < t; i++ ) {
        solve_case();
    }
}