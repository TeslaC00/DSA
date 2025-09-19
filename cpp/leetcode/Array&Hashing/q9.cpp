#include<vector>
#include<iostream>
#include<algorithm>
#include<unordered_set>

class Solution {
public:
	int longestConsecutive(std::vector<int>& nums) {
		if (nums.empty())
			return 0;

		std::unordered_set<int> set(nums.begin(), nums.end());
		int maxLength = 0;
		for (const int num : set)
		{
			if (set.find(num - 1) == set.end())
			{
				int curr = num;
				int length = 1;
				while (set.find(curr + 1) != set.end())
				{
					curr++;
					length++;
				}
				maxLength = (length > maxLength) ? length : maxLength;
			}
		}
		return maxLength;
	}

	static void test() {
		Solution sol;
		std::vector<int> input1 = { 100,4,200,1,3,2 };
		std::vector<int> input2 = { 0,3,7,2,5,8,4,6,0,1 };
		std::vector<int> input3 = { 1,0,1,2 };
		std::cout << sol.longestConsecutive(input1) << std::endl;
		std::cout << sol.longestConsecutive(input2) << std::endl;
		std::cout << sol.longestConsecutive(input3) << std::endl;
	}
};