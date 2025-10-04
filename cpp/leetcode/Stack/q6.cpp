#include<vector>
#include<iostream>
#include<algorithm>

class Solution {
public:
	int carFleet(int target, const std::vector<int>& position, const std::vector<int>& speed) {
		int n = position.size();
		if (n == 1) return 1;

		std::vector<std::pair<int, double>> cars;
		cars.reserve(n);

		for (size_t i = 0; i < n; i++)
			cars.emplace_back(position[i], (double)(target - position[i]) / speed[i]);

		std::sort(cars.begin(), cars.end());

		int fleets = 0;
		double currentMax = 0.0;
		for (int i = n - 1; i >= 0; i--)
		{
			double time = cars[i].second;
			if (time > currentMax)	// will not catchup
			{
				fleets++;
				currentMax = time;
			}
		}

		return fleets;
	}

	static void test() {
		Solution sol;
		std::vector<int> position = { 0,4,2 }, speed = { 2,1,3 };
		std::cout << sol.carFleet(10, position, speed) << std::endl;
		std::cout << "" << std::endl;
	}
};