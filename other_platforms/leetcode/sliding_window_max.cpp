#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l = 0;
        int r = k - 1;  
        vector<int> answer;

        multiset<int> values;

        for(int i = 0 ;i <= r; i++) {
            values.insert(nums[i]);
        }
        answer.push_back(*prev(values.end()));

        while(r < int(nums.size()) - 1) {
            values.erase(values.find(nums[l]));
            l++;
            r++;
            values.insert(nums[r]);
            answer.push_back(*prev(values.end()));
        }

        return answer;

    }

};