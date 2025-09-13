#include <iostream>
#include <string>

class Solution {
public:
	bool isAnagram(const std::string& s, const std::string& t) {
		if (s.length() != t.length()) return false;

		int sFreq[26] = { 0 };
		for (size_t i = 0; i < s.length(); i++)
		{
			sFreq[s[i] - 'a']++;
			sFreq[t[i] - 'a']--;
		}

		for (size_t i = 0; i < 26; i++)
			if (sFreq[i] != 0) return false;

		return true;
	}

	static void test() {
		Solution sol;
		std::string s("anagram"), t("nagaram");
		std::cout << sol.isAnagram(s, t) << std::endl;
		std::cout << sol.isAnagram("rat", "car") << std::endl;
	}
};