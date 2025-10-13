#include<vector>
#include<iostream>

class Solution {
public:
	int search(std::vector<int>& nums, int target) {
		int start = 0, end = nums.size() - 1;
		int middle = (end + start) / 2;
		while (start <= end)
		{
			int num = nums[middle];
			if (num == target) return middle;
			if (num < target) start = middle + 1;
			else end = middle - 1;
			middle = (end + start) / 2;
		}
		return -1;
	}

	static void test() {
		Solution sol;
		std::vector<int> input = { -1,0,3,5,9,12 };
		std::cout << sol.search(input, 9) << std::endl;
	}
};