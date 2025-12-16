#include<bits/stdc++.h>
using namespace std;

int main() {
    int n , q;
    cin >> n >> q;

    vector<int> numbers(n);
    for(int i = 0 ;i < n ;i++) {
        cin >> numbers[i];
    }

    vector<int> first_appearance(200001, -1);
    vector<int> test_segments(200001);
    for(int i = 0; i < n; i++) {
        if(first_appearance[numbers[i]] == -1) {
            first_appearance[numbers[i]] = i;
        }
        else {
            test_segments[first_appearance[numbers[i]]] = i;
        }
    }
    vector<pair<int,int>> segments;
    segments.push_back({0 , test_segments[0]});
    int j = 0;
    for(int i = 1;i <= 200000; i++) {
        if(test_segments[i]) {
            if(i < segments[j].second) {
                segments[j].second = max(segments[j].second, test_segments[i]);
            }
            else {
                j++;
                segments.push_back({i , test_segments[i]});
            }
        }
    }
    int need_change = 0;
    vector<int> count(200001);
    for(auto &x : segments) {
        int best_num;
        int max_appearances = 0;
        for(int i = x.first; i <= x.second; i++) {
            count[numbers[i]]++;
            if(count[numbers[i]] > max_appearances) {
                best_num = numbers[i];
                max_appearances = count[numbers[i]];
            }
        }

        for(int i = x.first; i <= x.second; i++) {
            if(numbers[i] != best_num) {
                need_change++;
            }
        }
        for(int i = x.first; i <= x.second; i++) {
            count[numbers[i]]--;
        }
    }

    cout << need_change << endl;
}