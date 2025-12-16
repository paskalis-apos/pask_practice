#include<bits/stdc++.h>
using namespace std;

int N , M;
int min_cost = INT_MAX;

struct cinfo {
    int s , t , c;
};
struct ainfo {
    int a, b , p , m;
};

vector<cinfo> cows;
vector<ainfo> ac;
vector<bool> working_ac;

void valid_ac() {
    bool is_feasible = true;

    for(int i = 1 ;i <= 100; i++) {
        int cooling = 0;
        for(int j = 0; j < M; j++) {
            if(!working_ac[j]) {
                continue;
            }
            if(ac[j].a <= i && ac[j].b >= i) {
                cooling += ac[j].p;
            }

        }
        int cow_req = 0;
        for(int j = 0 ;j < N; j++) {
            if(cows[j].s <= i && cows[j].t >= i) {
                cow_req = cows[j].c;
                break;
            }
        }

        if (cooling < cow_req) {
            is_feasible = false;
            break;
        }
    }  
    if(is_feasible) {
        int cost = 0; 
        for(int i = 0 ;i < M ;i++) {
            if(working_ac[i]) {
                cost += ac[i].m;
            }
        }
        min_cost = min(min_cost, cost);
    }


}

void search_ac(int i) {
    if(i == 10) {
        valid_ac();
        return;
    } 

    search_ac(i + 1);
    working_ac[i] = true;
    search_ac(i + 1);
    working_ac[i] = false;   
}



int main() {
    cin >> N >> M;
    working_ac.resize(M, false);
    for(int i = 0 ;i < N; i++) {
        cinfo temp;
        cin >> temp.s >> temp.t >> temp.c;
        cows.push_back(temp);
    }
    for(int i = 0; i < M ;i++) {
        ainfo temp;
        cin >> temp.a >> temp.b >> temp.p >> temp.m;
        ac.push_back(temp);
    }
    search_ac(0);
    cout << min_cost << endl;


}