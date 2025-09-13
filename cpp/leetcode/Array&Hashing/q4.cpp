#include<vector>
#include<iostream>
#include<unordered_map>
#include<string>
#include<sstream>

class Solution {
public:
	std::string hashAnagram(const std::string& str) {
		int freq[26] = { 0 };
		for (char c : str)
			freq[c - 'a']++;

		std::stringstream keyStream;
		for (size_t i = 0; i < 26; i++)
			if (freq[i] != 0)
				keyStream << (char)('a' + i) << freq[i];

		return keyStream.str();
	}

	std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
		if (strs.size() == 1) return { {strs[0]} };

		std::unordered_map<std::string, int> map;
		std::vector<std::vector<std::string>> group;

		for (const std::string& str : strs)
		{
			std::string key = hashAnagram(str);
			if (map.find(key) != map.end())
			{
				group[map[key]].push_back(str);
			}
			else
			{
				map[key] = group.size();
				group.push_back({ str });
			}
		}

		return group;
	}

	static void test() {
		Solution sol;

		std::cout << sol.hashAnagram("bdddddddddd") << std::endl;
		std::cout << sol.hashAnagram("bbbbbbbbbbc") << std::endl;
	}
};