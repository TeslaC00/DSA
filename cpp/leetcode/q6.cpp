#include <string>
#include <iostream>
#include <vector>

class Solution {
public:
	/*
	* Example 1:
	Input: s = "PAYPALISHIRING", numRows = 3
	Output: "PAHNAPLSIIGYIR"

	Example 2:
	Input: s = "PAYPALISHIRING", numRows = 4
	Output: "PINALSIGYAHRPI"
	Explanation:
	P     I    N
	A   L S  I G
	Y A   H R
	P     I

	Example 3:
	Input: s = "A", numRows = 1
	Output: "A"
	*/
	std::string convert(std::string s, int numRows) {
		if (numRows == 1 || numRows >= s.length())
			return s;

		std::vector<std::string> rows(numRows, "");
		bool goingDown = true;
		int rowIdx = 0;
		for (int i = 0; i < s.length(); i++)
		{
			rows[rowIdx] += s[i];
			if (goingDown && (rowIdx == numRows - 1))
			{
				goingDown = false;
			}
			else if (!goingDown && (rowIdx == 0))
			{
				goingDown = true;
			}
			rowIdx += goingDown ? 1 : -1;
		}

		std::string concat;
		for (std::string row : rows)
		{
			concat += row;
		}
		return concat;
	}

	static void test() {
		Solution sol;
		std::string s("PAYPALISHIRING");
		std::cout << sol.convert(s, 3) << std::endl;	// PAHNAPLSIIGYIR
		std::cout << sol.convert(s, 4) << std::endl;	// PINALSIGYAHRPI
	}
};