#include<vector>
#include<iostream>

class Solution {
public:
	bool isValidSudoku(std::vector<std::vector<char>>& board) {
		// TODO: use bit-mask to save more space
		bool rows[9][9] = { false }, cols[9][9] = { false }, boxes[9][9] = { false };
		for (int row = 0; row < board.size(); row++)
		{
			for (int col = 0; col < board[0].size(); col++) {
				char numChar = board[row][col];
				// Check for empty number
				if (numChar == '.')
					continue;
				int num = numChar - '1';

				if (rows[num][row])
					return false;
				else
					rows[num][row] = true;

				// Check for col match
				if (cols[num][col])
					return false;
				else
					cols[num][col] = true;

				// Check for box match
				int box = (row / 3) * 3 + (col / 3);
				if (boxes[num][box])
					return false;
				else
					boxes[num][box] = true;
			}
		}
		return true;
	}

	static void test() {
		Solution sol;
		std::vector<std::vector<char>> board1 = {
			{'.','.','4','.','.','.','6','3','.'},
			{'.','.','.','.','.','.','.','.','.'},
			{'5','.','.','.','.','.','.','9','.'},
			{'.','.','.','5','6','.','.','.','.'},
			{'4','.','3','.','.','.','.','.','1'},
			{'.','.','.','7','.','.','.','.','.'},
			{'.','.','.','5','.','.','.','.','.'},
			{'.','.','.','.','.','.','.','.','.'},
			{'.','.','.','.','.','.','.','.','.'}
		};
		bool result = sol.isValidSudoku(board1);
		std::cout << result << std::endl;
	}
};