#include<bits/stdc++.h>
using namespace std;

struct col
{
    int x;
    int y; 
    int time;
    int cowx;
    int cowy;

    bool operator<(const col &c) {
        return time < c.time;
    }
};

struct cow
{
    int x;
    int y;
    bool up;
    int stop = - 1;

};

int main() {
    int N;
    cin >> N;
    vector<cow> cow_info(N);
    vector<col> collisions;
    for(int i = 0 ;i < N ;i++) {
        char direction; 
        cin >> direction;
        if(direction == 'E') {
            cow_info[i].up = false;
        }
        else {
            cow_info[i].up = true;
        }
            
        cin >> cow_info[i].x >> cow_info[i].y;
    }

    for(int i = 0; i < N ;i++) {
        for(int j = 0; j < N ;j++) {
            while(j <= i) {
                j++;
            }
            if(cow_info[i].up == cow_info[j].up) {
                continue;
            }
            if((cow_info[i].up == true && cow_info[i].y > cow_info[j].y )||( cow_info[j].up == true && cow_info[j].y > cow_info[i].y)) {
                continue;
            }
            if((cow_info[i].up == false && cow_info[i].x > cow_info[j].x )||( cow_info[j].up == false && cow_info[j].x > cow_info[i].x)) {
                continue;
            }
            if(abs(cow_info[i].x - cow_info[j].x) == abs(cow_info[i].y - cow_info[j].y)) {
                continue;
            }

            col tempcol;
            tempcol.time = max(abs(cow_info[i].x - cow_info[j].x), abs(cow_info[i].y - cow_info[j].y));
            tempcol.x = max(cow_info[i].x, cow_info[j].x);
            tempcol.y = max(cow_info[i].y, cow_info[j].y);
            if(cow_info[i].up == true) {
                tempcol.cowy = i;
                tempcol.cowx = j;
            }
            else {
                tempcol.cowy = j;
                tempcol.cowx = i;
            }

            collisions.push_back(tempcol);
        }

    }
    sort(collisions.begin(), collisions.end());
    for(auto &i : collisions) {
        if((cow_info[i.cowy].stop != -1 &&cow_info[i.cowy].stop <= i.y )||( cow_info[i.cowx].stop != -1 && cow_info[i.cowx].stop <= i.x)) {
            continue;
        }
        if ((cow_info[i.cowx].y - cow_info[i.cowy].y) > (cow_info[i.cowy].x - cow_info[i.cowx].x)) {
            cow_info[i.cowy].stop = i.y;
        }
        else {
            cow_info[i.cowx].stop = i.x;
        }
    }
       

    for(int i = 0;i < N ;i++) {
        if(cow_info[i].stop == -1) {
            cout << "Infinity";
        }
        else {
            if(cow_info[i].up == true) {
                cout << cow_info[i].stop - cow_info[i].y;
            }
            else {
                cout << cow_info[i].stop - cow_info[i].x;
            }
        }
        cout << endl;
    }
}


