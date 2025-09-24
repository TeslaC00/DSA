#include<iostream>
#include<vector>

class Solution {
public:
	int maxArea(std::vector<int>& height) {
		int maxWater = 0;
		int left = 0, right = height.size() - 1;
		while (left < right)
		{
			maxWater = std::max(maxWater, (right - left) *
				std::min(height[left], height[right]));
			if (height[left] < height[right]) left++;
			else right--;
		}
		return maxWater;
	}

	static void test() {
		Solution sol;
		std::vector<int> input1 = { 1,8,6,2,5,4,8,3,7 };
		std::cout << sol.maxArea(input1) << std::endl;
	}
};