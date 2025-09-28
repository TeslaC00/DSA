#include<iostream>
#include<string>
#include<vector>
#include<stack>

class Solution {
public:
	int evalRPN(std::vector<std::string>& tokens) {
		std::stack<int> stack;

		for (const std::string& str : tokens)
		{
			if (str.size() == 1)
			{
				char c = str[0];
				if (c == '+' || c == '-' || c == '*' || c == '/')
				{
					int num2 = stack.top(); stack.pop();
					int num1 = stack.top(); stack.pop();
					switch (c)
					{
					case '+': stack.push(num1 + num2); break;
					case '-': stack.push(num1 - num2); break;
					case '*': stack.push(num1 * num2); break;
					case '/': stack.push(num1 / num2); break;
					default:
						break;
					}
				}
				else
					stack.push(c - '0');
			}
			else
				stack.push(std::stoi(str));
		}
		return stack.top();
	}

	static void test() {
		Solution sol;
		std::vector<std::string> input1 = { "10","6","9","3","+","-11","*","/","*","17","+","5","+" };
		std::cout << sol.evalRPN(input1) << std::endl;
	}
};