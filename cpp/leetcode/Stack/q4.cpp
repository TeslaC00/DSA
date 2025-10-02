#include<string>
#include<vector>
#include<stack>
#include<iostream>

class Solution {
public:
	void generate(int n, int open, int close, std::string& str, std::vector<std::string>& results) {
		if (str.size() == 2 * n)
		{
			results.push_back(str);
			return;
		}

		if (open < n)
		{
			str.push_back('(');
			generate(n, open + 1, close, str, results);
			str.pop_back();
		}
		if (close < open)
		{
			str.push_back(')');
			generate(n, open, close + 1, str, results);
			str.pop_back();
		}
	}

	std::vector<std::string> generateParenthesis(int n) {
		if (n == 1) return { "()" };
		if (n == 2) return { "(())", "()()" };

		size_t sizes[8] = { 1,2,5,14,42,132,429,1430 };
		std::vector<std::string> result;
		result.reserve(sizes[n - 1]);
		std::string str;
		str.reserve(2 * n);

		generate(n, 0, 0, str, result);
		return result;
	}

	static void test() {
		Solution sol;
		std::vector<std::string> result3 = sol.generateParenthesis(3);
		for (const std::string& str : result3)
		{
			std::cout << str << std::endl;
		}
		std::vector<std::string> result4 = sol.generateParenthesis(4);
		for (const std::string& str : result4)
		{
			std::cout << str << std::endl;
		}
		std::cout << "" << std::endl;
	}
};