
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int maxLength = 0;
        unordered_set<char> window;

        for (int right = 0; right < s.size(); right++) {
            // Remove characters until the duplicate is gone
            while (window.count(s[right])) {
                window.erase(s[left]);
                left++;
            }
            // Add the new character
            window.insert(s[right]);
            // Update the maximum window length
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};
