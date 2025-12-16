#include<bits/stdc++.h>
using namespace std;
int N = 3;

struct cord{
    int x , y;
    char id;
};
vector<cord> rects(3);
vector<bool> used(3);
int len = 1;

void print_under(vector<cord> rects) {
    cout << len << endl;
    for(int c1 = 0 ; c1 < len; c1++) {
        for(int c2 = 0 ; c2 < len; c2++) {
            if(c1 < rects[1].y) {
                if(c2 < rects[1].x) {
                    cout << rects[1].id;
                }
                else {
                    cout << rects[2].id;
                }
            }
            else {
                cout << rects[0].id;
            }
        }
        cout << endl;
    }
    exit(EXIT_SUCCESS);
}

void print_straight(vector<cord> rects) {
    cout << len << endl;
    for(int c1 = 0 ;c1 < len ; c1++) {
        for(int c2 = 0; c2 < len; c2++) {
            if(c2 < rects[0].x) {
                cout << rects[0].id;
            }
            else if(c2 < rects[0].x + rects[1].x) {
                cout << rects[1].id;
            }
            else {
                cout << rects[2].id;
            }
        }
        cout << endl;
    }
    
    exit(EXIT_SUCCESS);
}

void check_under(vector<cord> rects) {
    if(rects[0].x == rects[1].x + rects[2].x) {
        if(rects[1].y == rects[2].y) {
            if(rects[0].y + rects[1].y == rects[0].x) {
                print_under(rects);
            }
        }
    }
}

void check_straight(vector<cord> rects) {
    if(rects[0].y == rects[1].y && rects[1].y == rects[2].y) {
        int xsum = rects[0].x + rects[1].x + rects[2].x;
        if(xsum == rects[0].y) {
            print_straight(rects);
        }
    }
}

void check(vector<cord> rects) {
    check_straight(rects);
    for(int count = 0; count < 3; count++) {
        check_under(rects);
        rects.push_back(rects.front());
        rects.erase(rects.begin());
    }

}


int main() {
    
    
    cin >> rects[0].x >> rects[0].y >> rects[1].x >> rects[1].y >> rects[2].x >> rects[2].y;
    
    rects[0].id = 'A';
    rects[1].id = 'B';
    rects[2].id = 'C';

    long long area = 0;
    for(auto &i : rects) {area += i.y * i.x;}
    
    while(len * len < area) { len++;}
    if(len * len > area) {
        cout << -1 ;
        return 0;
    }

    
    vector<vector<int>> square(len);
    for(int i = 0; i < len ;i ++) {
        for(int j; j < len; j++) {
            square[i].push_back(0);
        }
    }

    for(int i = 0; i < (1 << N); i++) {
        auto temprect = rects;                                        
        auto temp_square = square;
        
        for(int b = 0 ;b < 3; b++) {
            
            if(i & (1 << b)) {
                swap(temprect[b].x, temprect[b].y);
            }
        }    

        check(temprect);
    }
    cout << -1 << endl;

}