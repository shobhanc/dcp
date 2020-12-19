/*
 * Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.



Example 1:

Input: nums = [1,2,3,4,5]
Output: true
Explanation: Any triplet where i < j < k is valid.
Example 2:

Input: nums = [5,4,3,2,1]
Output: false
Explanation: No triplet exists.
Example 3:

Input: nums = [2,1,5,0,4,6]
Output: true
Explanation: The triplet (3, 4, 5) is valid because nums[3] == 0 < nums[4] == 4 < nums[5] == 6.


Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
*/

//O(N) time and O(1) space
bool increasingTriplet(vector<int> &nums){
	int first_num=INT_MAX, second_num=INT_MIN;
	for(auto a: nums){
		if(a<=first_num){//capture the first num
			first_num=a;
		}else if(a<=second_num){//capture the second num
			second_num=a;
		}else{//if its not the first or second then we have a third
			return true
		}
	}
	return false;
}

//recursive solution O(n^2) time and O(n^2) space
bool checkForIncreasingTriplet(vector<int>& nums, int l, int r){
				if(l>=r){
								return false;
				}
				int org=l;
				while(l<r){
								if(nums[l]>=nums[r]){
												break;
								}
								if((l-org)>=1){
												return true;
								}
								l++;
				}

				return checkForIncreasingTriplet(nums, l+1, r) || checkForIncreasingTriplet(nums, l, r-1);
}
bool increasingTriplet1(vector<int>& nums) {
				return checkForIncreasingTriplet(nums, 0, nums.size()-1);
}
