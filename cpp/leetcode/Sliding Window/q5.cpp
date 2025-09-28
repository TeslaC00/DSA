#include<iostream>
#include<string>

class Solution {
public:
	constexpr int getCharIndex(const char& c)
	{
		return (c < 'a') ? c - 'A' : c - 'a' + 26;
	}

	std::string minWindow(const std::string& s, const std::string& t) {
		if (t.size() > s.size()) return "";

		int need[52] = { 0 }, window[52] = { 0 };
		int needCount = 0;
		for (const char& c : t)
		{
			int index = getCharIndex(c);
			if (need[index] == 0) needCount++;
			need[index]++;
		}

		int ansLeft = 0, left = 0, ansLength = INT_MAX, elementCount = 0;

		for (size_t right = 0; right < s.size(); right++)
		{
			int index = getCharIndex(s[right]);
			window[index]++;

			if (need[index] > 0 && need[index] == window[index])
				elementCount++;

			while (elementCount == needCount)
			{
				if (right - left + 1 < ansLength)
				{
					ansLength = right - left + 1;
					ansLeft = left;
				}
				int index = getCharIndex(s[left++]);
				if (need[index] > 0 && --window[index] < need[index])
					elementCount--;
			}
		}
		return (ansLength == INT_MAX) ? "" : s.substr(ansLeft, ansLength);
	}

	static void test() {
		Solution sol;
		std::cout << sol.minWindow("aa", "aa") << std::endl;
	}
};