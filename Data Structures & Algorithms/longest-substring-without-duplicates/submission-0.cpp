class Solution {
public:
    int lengthOfLongestSubstring(string s) {
            int i = 0, j = 0;
        unordered_map<char, int> freq;
        int ans = 0;

        while (j < s.size()) {

            // 1. Expand
            freq[s[j]]++;

            // 2. Shrink if window becomes invalid
            while (freq[s[j]] > 1) {
                freq[s[i]]--;
                i++;
            }

            // 3. Window is valid
            ans = max(ans, j - i + 1);

            j++;
        }
        return ans;
    }
};
