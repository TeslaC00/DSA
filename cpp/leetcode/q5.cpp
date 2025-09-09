#include <string>
#include <iostream>
#include <utility>

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
	std::pair<int, int> expandAroundCentre(const std::string& s, int left, int right)
	{
		while ((left - 1 >= 0) && (right + 1 < s.length()) && s[right + 1] == s[left - 1])
		{
			left--; right++;
		}
		int size = right - left + 1;
		return std::make_pair(left, size);
	}

	std::string longestPalindrome(std::string s) {
		int startIdx = 0, maxSize = 0;
		for (int i = 0; i < s.length(); i++)
		{
			std::pair<int, int> oddPair = expandAroundCentre(s, i, i);

			if (s[i] == s[i + 1])
			{
				std::pair<int, int> evenPair = expandAroundCentre(s, i, i + 1);
				if (oddPair.second < evenPair.second)
					oddPair = evenPair;
				}

			if (maxSize < oddPair.second)
					{
				startIdx = oddPair.first;
				maxSize = oddPair.second;
				}
			}

		return s.substr(startIdx, maxSize);
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