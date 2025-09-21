#include<iostream>
#include<vector>
#include<algorithm>

class Solution {
public:
	std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
		std::sort(nums.begin(), nums.end());
		std::vector<std::vector<int>> result;

		for (size_t i = 0; i < nums.size() - 2; i++)
		{
			if (nums[i] > 0) break;
			if (i > 0 && nums[i - 1] == nums[i]) continue;

			int left = i + 1, right = nums.size() - 1;
			while (left < right)
			{
				int sum = nums[i] + nums[left] + nums[right];
				if (sum > 0) right--;
				else if (sum < 0) left++;
				else
				{
					result.push_back({ nums[i] , nums[left] , nums[right] });
					left++; right--;
					while (left < right && nums[left] == nums[left - 1]) left++;
					while (left < right && nums[right] == nums[right + 1]) right--;
				}
			}
		}
		return result;
	}

	static void print(std::vector<std::vector<int>>& nums)
	{
		for (const std::vector<int>& arr : nums)
		{
			for (const int& num : arr)
			{
				std::cout << num << ", ";
			}
			std::cout << std::endl;
		}
	}

	static void test() {
		Solution sol;
		//std::vector<int> input1 = { -100,-70,-60,110,120,130,160 };
		std::vector<int> input1 = { 2,-3,0,-2,-5,-5,-4,1,2,-2,2,0,2,-4,5,5,-10 };
		std::vector<std::vector<int>> result1 = sol.threeSum(input1);
		print(result1);
	}
};