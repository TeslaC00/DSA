#include <iostream>
#include <cstdint>

class Solution {
public:
	/*
	Example 1:
	Input: x = 123
	Output: 321

	Example 2:
	Input: x = -123
	Output: -321

	Example 3:
	Input: x = 120
	Output: 21
	*/
	int reverse(int x) {
		int result = 0;
		while (x != 0)
		{
			int pop = x % 10;
			if (result > INT32_MAX / 10 || (result == INT32_MAX / 10 && pop > 7)) return 0;
			if (result < INT32_MIN / 10 || (result == INT32_MIN / 10 && pop < -8)) return 0;
			result = result * 10 + pop;
			x /= 10;
		}
		return result;
	}

	static void test() {
		Solution sol;
		std::cout << sol.reverse(120) << std::endl;
		std::cout << sol.reverse(1534236469) << std::endl;
		std::cout << sol.reverse(-69) << std::endl;
		std::cout << sol.reverse(-2147483648) << std::endl;
		std::cout << sol.reverse(-2147483412) << std::endl;
	}
};