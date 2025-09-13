#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
public:
	bool containsDuplicate(std::vector<int>& nums) {
		std::unordered_set<int> uniqueSet;
		for (const int num : nums)
		{
			if (uniqueSet.find(num) != uniqueSet.end())
				return true;
			else
				uniqueSet.insert(num);
		}
		return false;
	}

	static void test() {
		Solution sol;
		std::vector<int> test = { 1,1,1,3,3,4,3,2,4,2 };
		std::vector<int> uni = { 1,2,3,4 };
		std::cout << sol.containsDuplicate(test) << std::endl;
		std::cout << sol.containsDuplicate(uni) << std::endl;
	}
};

