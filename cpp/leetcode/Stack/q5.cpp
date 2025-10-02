#include<vector>
#include<iostream>

class Solution {
public:

	// monotonic stack (stack like priority queue)
	std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
		int n = temperatures.size();
		std::vector<int> stack;
		stack.reserve(n);
		std::vector<int> result(n, 0);

		for (int i = n - 1; i >= 0; i--)
		{
			while (!stack.empty() && temperatures[i] >= temperatures[stack.back()])
				stack.pop_back();
			if (!stack.empty())
				result[i] = stack.back() - i;
			stack.push_back(i);
		}
		return result;
	}

	static void test() {
		Solution sol;
		std::vector<int> input1 = { 89,62,70,58,47,47,46,76,100,70 };
		for (const int& i : sol.dailyTemperatures(input1))
		{
			std::cout << i << std::end(" ");
		}
		std::cout << "" << std::endl;
	}
};