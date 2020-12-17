/*
 * Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.
Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
Example 2:

Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in non-decreasing order.
 */
class Solution {
public:
    vector<int> sortedSquares1(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            nums[i]=nums[i]*nums[i];
        }
        sort(nums.begin(),nums.end());
        return nums;
    }

    /*Two pointer with extra space O(n)*/
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size(),0);
        int l=0, r= nums.size()-1;
        int cur=r;
        while(l<=r){//take care of odd size of nums
            int lval=nums[l]*nums[l];
            int rval=nums[r]*nums[r];
            if(lval>rval){
                res[cur]=lval;
                l++;
            }else{
                res[cur]=rval;
                r--;    
            }
            cur--;
        }

        return res;
    }
};
