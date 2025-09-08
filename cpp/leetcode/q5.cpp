#include <string>
#include <iostream>

class Solution {
public:

	/*
	Given a string s, return the longest palindromic substring in s.
	Example 1:
	Input: s = "babad"
	Output: "bab"
	Explanation: "aba" is also a valid answer.

	Example 2:
	Input: s = "cbbd"
	Output: "bb"
	*/
	//TODO: optimize this solution
	bool isPalindrome(int left, int right, const std::string& s)
	{
		while (left <= right)
		{
			if (s[left++] != s[right--])
				return false;
		}
		return true;
	}

	std::string longestPalindrome(std::string s) {
		std::string maxPalindrome;
		for (int i = 0; i < s.length(); i++)
		{
			int left = i, right = i;
			while (true)
			{
				if ((left - 1 >= 0) && (right + 1 < s.length()) && (s[right + 1] == s[left - 1]))
				{
					left--; right++; continue;
				}
				else if ((left - 1 >= 0) && (s[left - 1] == s[right]))
				{
					if (isPalindrome(left - 1, right, s))
					{
						left--; continue;
					}
				}
				else if ((right + 1 < s.length()) && (s[right + 1] == s[left]))
				{
					if (isPalindrome(left, right + 1, s))
					{
						right++; continue;
					}
				}
				break;
			}

			int size = right - left + 1;
			if (maxPalindrome.length() < size)
				maxPalindrome = s.substr(left, size);
		}

		return maxPalindrome;
	}



	static void test() {
		Solution sol;
		std::string odd("babad");
		std::string even("cbbd");
		std::string complex_case("aacabdkacaa");
		std::cout << sol.longestPalindrome(odd) << std::endl;
		std::cout << sol.longestPalindrome(even) << std::endl;
		std::cout << sol.longestPalindrome(complex_case) << std::endl;
	}
};