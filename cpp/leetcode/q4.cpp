#include <stack>
#include <Vector>

class Solution {
public:
	double findMedianSortedArrays(const std::vector<int>& nums1, const std::vector<int>& nums2) {
		int totalSize = nums1.size() + nums2.size();
		int ptr1 = 0, ptr2 = 0;
		// take median index by taking (total size arr + 1)*0.5
		int medianIdx = totalSize * 0.5;
		// at end if the number was if (even) -> (median+[median_idx - 1])*0.5
		std::stack<int> merged;
		for (int i = 0; i <= medianIdx; i++) {
			if (ptr1 < nums1.size() && ptr2 < nums2.size()) {
				if (nums1[ptr1] <= nums2[ptr2])
					merged.push(nums1[ptr1++]);
				else
					merged.push(nums2[ptr2++]);
			}
			else {
				if (ptr1 < nums1.size())
					merged.push(nums1[ptr1++]);
				if (ptr2 < nums2.size())
					merged.push(nums2[ptr2++]);
			}
		}

		double median = merged.top();
		merged.pop();
		if (totalSize % 2 == 0) median = (median + merged.top()) * 0.5;

		return median;
	}
};