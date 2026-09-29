class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int> freq;

        for(auto x : nums){
            freq[x]++;
        }

        vector<pair<int,int>> arr;

        for(auto x : freq){
            arr.push_back({x.second, x.first});
        }

        sort(arr.begin(), arr.end());

        vector<int> ans;

        for(int i = (int)arr.size() - 1; i >= (int)arr.size() - k; i--){
            ans.push_back(arr[i].second);
        }

        return ans;
    }
};