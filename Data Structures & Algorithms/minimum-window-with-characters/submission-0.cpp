class Solution {
public:
    string minWindow(string s, string t) {
       int i=0;
       int j=0;
       int minLen=INT_MAX;
       int minIndex=0;
       int n=s.size();
       unordered_map<char,int>freq;
       int count=t.size();
       for(auto i: t){
        freq[i]++;
       }
       while(j<n){
         if(freq[s[j]]>0){
            count--;
         }
         freq[s[j]]--;
         j++;
         while(count==0){
            if(j-i<minLen){
                minLen=j-i;
                minIndex=i;
            }
          freq[s[i]]++;
          if(freq[s[i]]>0){
            count++;
          }
          i++;
         }
         
       }
       if (minLen != INT_MAX) {
            return s.substr(minIndex, minLen);
          } else {
            return "";
         }
    }
};
