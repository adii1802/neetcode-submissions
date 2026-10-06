class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLen=0;
        int maxFreq=0;
        int i=0;
        unordered_map<char,int>freq;
        for(int j=0;j<s.size();j++){
          freq[s[j]]++;
          maxFreq=max(maxFreq,freq[s[j]]);

          while((j-i+1)-maxFreq>k){
            freq[s[i]]--;
            i++;
          }
          maxLen=max(maxLen,j-i+1);
        }
        return maxLen;
    }
};
