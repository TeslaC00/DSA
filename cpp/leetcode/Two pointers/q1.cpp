#include<string>
#include<iostream>
#include<cctype>

class Solution {
public:
	bool isPalindrome(const std::string& s) {
		if (s.size() == 1) return true;

		int left = 0, right = s.size() - 1;
		while (left <= right)
		{
			if (!isalnum(s[left]))
			{
				left++;
				continue;
			}
			if (!isalnum(s[right]))
			{
				right--;
				continue;
			}
			if (tolower(s[left]) != tolower(s[right])) return false;
			left++;
			right--;
		}
		return true;
	}

	static void test() {
		Solution sol;
		std::string input1("A man, a plan, a canal: Panama");
		bool result1 = sol.isPalindrome(input1);
		std::cout << result1 << std::endl;
	}
};