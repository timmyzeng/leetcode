/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

#include <iostream>
#include <vector>
#include <utility>  
#include <unordered_map>

using namespace std;

//时间复杂度O(n),空间复杂度O(1)
class Solution1 {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> res;
		if (nums.empty()) return res;
		res.resize(2);
		int size = nums.size();
		for (int i = 0; i < size; ++i) {
			int key = target - nums[i];
			int flag = false;
			for (int j = i + 1; j < size; ++j) {
				if (nums[j] == key) {
					res[0] = i;
					res[1] = j;
					flag = true;
					break;
				}
			}
			if (flag) break;
		}
		return res;
	}
};

class Solution2 {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> nums_count;
		nums_count.reserve(nums.size());
		for (size_t i = 0; i < nums.size(); i++)
		{
			int num = nums[i];
			auto itr = nums_count.find(num);
			if (itr != nums_count.end())
			{
				return { itr->second - 1, i};
			}
			nums_count.insert(std::make_pair(target - num, i + 1));
		}
		return {};
	}
};
static int disable_io_sync__ = []() {
	std::ios::sync_with_stdio(false); // disable synchronization between scanf/printf and cin/cout
	std::cin.tie(nullptr); // disable synchronization between std::cin and std::cout
	return 0;
}();
