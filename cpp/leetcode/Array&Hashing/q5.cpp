#include<vector>
#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<queue>

class Solution {
public:

	/* Sorting based solution
	std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
		std::unordered_map<int, int> freqMap;
		for (int num : nums) {
			freqMap[num]++;
		}
		std::vector<std::pair<int, int>> fVPair;
		fVPair.reserve(freqMap.size());
		for (std::unordered_map<int, int>::iterator it = freqMap.begin();
				it != freqMap.end(); ++it) {
			fVPair.push_back({it->second, it->first});
		}
		std::sort(
			fVPair.begin(), fVPair.end(),
			[](const std::pair<int, int>& a, const std::pair<int, int>& b) {
				return a.first > b.first;
			});

		std::vector<int> topElements(k);
		for (int i = 0; i < k; i++) {
			topElements[i] = fVPair[i].second;
		}
		return topElements;
    }
	*/

	// Heap based solution
	struct Compare
	{
		bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) {
			return a.second > b.second;
		}
	};

	std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
		std::unordered_map<int, int> freqMap;
		for (int num : nums)
		{
			freqMap[num]++;
		}
		std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, Compare> queue;
		for (std::unordered_map<int, int>::iterator it = freqMap.begin(); it != freqMap.end(); ++it)
		{
			queue.emplace(*it);
			if (queue.size() > k)
				queue.pop();
		}
		std::vector<int> topElements(k);
		for (int i = k - 1; i >= 0; i--)
		{
			topElements[i] = queue.top().first;
			queue.pop();
		}

		return topElements;
	}

	static void test() {
		Solution sol;
		std::vector<int> input1 = { 1,1,1,2,2,3 };
		std::vector<int> input2 = { 1,2,1,2,1,2,3,1,3,2 };
		sol.topKFrequent(input1, 2);
		sol.topKFrequent(input2, 2);
		std::cout << "" << std::endl;
	}
};