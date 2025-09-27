#include<iostream>
#include<string>

class Solution {
public:
	bool checkInclusion(const std::string& s1, const std::string& s2) {
		if (s1.size() > s2.size()) return false;
		int need[26] = { 0 }, window[26] = { 0 };
		for (const char& c : s1) need[c - 'a']++;

		int size = s1.size();
		for (size_t i = 0; i < size; i++) window[s2[i] - 'a']++;

		if (std::equal(std::begin(need), std::end(need), std::begin(window), std::end(window)))
			return true;

		for (size_t i = size; i < s2.size(); i++)
		{
			window[s2[i] - 'a']++;
			window[s2[i - size] - 'a']--;
			if (std::equal(std::begin(need), std::end(need), std::begin(window), std::end(window)))
				return true;
		}
		return false;
	}

	static void test() {
		Solution sol;
		std::cout << sol.checkInclusion("adc", "dcda") << std::endl;
		std::cout << sol.checkInclusion("ab", "eidboaoo") << std::endl;
	}
};