class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>freq;
        for(auto i : strs){
            string a = i;
            sort(i.begin(),i.end());
            freq[i].push_back(a);
        }
        vector<vector<string>>ans;
        for(auto i: freq){
            ans.push_back(i.second);
        }
        return ans;
     }
};
