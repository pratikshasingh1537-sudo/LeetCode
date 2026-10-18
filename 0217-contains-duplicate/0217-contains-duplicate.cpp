class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int num : nums) {
            // If the number is already in the set, we found a duplicate
            if (seen.count(num)) {
                return true;
            }
            // Otherwise, insert it into the set
            seen.insert(num);
        }
        return false;
    }
};