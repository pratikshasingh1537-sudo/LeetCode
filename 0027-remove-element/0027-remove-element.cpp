class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k=0, a=0;
       // char c='_'
        for (int b=0; b < nums.size(); b++) {
            if(nums[b]!= val){ 
                swap(nums[k], nums[b]);
                k++;
                //a++;
            }
         //   text.replace(val, 1, "_");
        } return k;
    }
};