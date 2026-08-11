class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hash;
        for (int num: nums) {
            if(hash.count(num)>0)
                return true;
            hash.insert(num);
        }
        return false;
    }
};