#include<bits/stdc++.h>
using namespace std; 

int N;
vector<pair<int,int>> cowpairs;
vector<int> used_cow(8);
vector<int> cur;
vector<string> cows(8);


void analyze() {
    vector<pair<int,int>> testpairs;
    for(int j = 0;j < 7;j++) {
        pair<int,int> temp;
        temp.first = cur[j];
        temp.second = cur[j + 1];
        testpairs.push_back(temp);
        temp.first = cur[j + 1];
        temp.second = cur[j];
        testpairs.push_back(temp);
    }
    bool valid = true;

    for(int c = 0; c < N; c++) {
        bool help = false;
        for(int j = 0 ;j < testpairs.size();j++) {
            if(testpairs[j] == cowpairs[c]) {
                help = true;
                break;
            }
        }
        if (help == false) {
            valid = false;
            break;
        }
    }

    if(valid) {
        for(auto &x : cur) {
            cout << (string)(cows[x]) << endl;
        }
        exit(EXIT_SUCCESS);
    }
}

void check_pos() {

    if(cur.size() == 8) {
        analyze();
        return;
    }

    for(int i = 0 ;i < 8 ;i++) {
        if(used_cow[i]) {
            continue;
        }

        used_cow[i] = true;
        cur.push_back(i);
        check_pos();
        used_cow[i] = false;
        cur.pop_back();
    }
}


int main() {
    freopen("lineup.in","r",stdin);
    freopen("lineup.out","w",stdout);
    cows[0] = "Bessie";
    cows[1] = "Buttercup";
    cows[2] = "Belinda";
    cows[3] = "Beatrice";
    cows[4] = "Bella";
    cows[5] = "Blue";
    cows[6] = "Betsy";
    cows[7] = "Sue";

    sort(cows.begin(), cows.end());

    cin >> N;
    map<string,int> cowname;
    for(int i = 0; i < 8 ;i++) {
        cowname[cows[i]] = i;
    }
    for(int i = 0 ;i < N ;i++) {
        pair<int,int> toput;
        string temp;
        string useless;
        cin >> temp;
        toput.first = cowname[temp];
        cin >> useless >> useless >> useless >> useless >> temp;
        toput.second = cowname[temp];
        cowpairs.push_back(toput);


    }

    check_pos();
    
}