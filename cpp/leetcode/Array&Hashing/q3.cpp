#include<vector>
#include<iostream>
#include<unordered_map>

class Solution {
public:
	/*
	* Example 1:
	Input: nums = [2,7,11,15], target = 9
	Output: [0,1]
	Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
	*/
	std::vector<int> twoSum(std::vector<int>& nums, int target) {
		std::unordered_map<int, int> seen;
		for (int i = 0; i < nums.size(); i++)
		{
			int needed = target - nums[i];
			if (seen.find(needed) != seen.end())
			{
				return { seen[needed], i };
			}

			seen[nums[i]] = i;
		}

		return {};
	}

	static void test() {
		Solution sol;
		std::vector<int> num1 = { 2,7,11,15 };
		std::vector<int> num2 = { 3,2,4 };
		std::vector<int> pair1 = sol.twoSum(num1, 9);
		std::vector<int> pair2 = sol.twoSum(num2, 6);

		std::cout << pair1[0] << ", " << pair1[1] << std::endl;
		std::cout << pair2[0] << ", " << pair2[1] << std::endl;
	}
};