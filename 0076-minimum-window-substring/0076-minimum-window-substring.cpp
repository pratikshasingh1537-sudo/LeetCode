class Solution {
public:
    string minWindow(string s, string t) {

        if (t.size() > s.size()) {
            return "";
        }

        // What characters do we need?
        vector<int> need(128, 0);

        for (char c : t) {
            need[c]++;
        }

        // What characters do we currently have in the window?
        vector<int> window(128, 0);

        int left = 0;
        int right = 0;

        // Number of characters from t that are still missing
        int required = t.size();

        int minLength = INT_MAX;
        int start = 0;

        while (right < s.size()) {

            // Expand the window
            char c = s[right];
            right++;

            // If this character is actually needed
            if (need[c] > 0) {

                // Only reduce required if this occurrence
                // helps satisfy a missing character
                if (window[c] < need[c]) {
                    required--;
                }

                window[c]++;
            }

            // Window is valid
            while (required == 0) {

                // Save the smallest valid window
                if (right - left < minLength) {
                    minLength = right - left;
                    start = left;
                }

                // Remove the leftmost character
                char d = s[left];
                left++;

                if (need[d] > 0) {

                    // If removing this character makes us
                    // short of what t requires
                    if (window[d] <= need[d]) {
                        required++;
                    }

                    window[d]--;
                }
            }
        }

        if (minLength == INT_MAX) {
            return "";
        }

        return s.substr(start, minLength);
    }
};