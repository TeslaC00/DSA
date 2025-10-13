#include<vector>
#include<iostream>

class Solution {
public:
	bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
		int row = matrix.size(), col = matrix[0].size();
		int start = 0, end = (row * col) - 1;
		int middle = (end + start) / 2;
		while (start <= end)
		{
			int i = middle / col;
			int j = middle % col;
			int num = matrix[i][j];

			if (num == target) return true;
			if (num < target) start = middle + 1;
			else end = middle - 1;

			middle = (end + start) / 2;
		}
		return false;
	}

	static void test() {
		Solution sol;
		std::vector<std::vector<int>> input = {
			{1, 3, 5, 7},
			{ 10, 11, 16, 20},
			{ 23, 30, 34, 60} };
		std::cout << sol.searchMatrix(input, 3) << std::endl;
	}
};