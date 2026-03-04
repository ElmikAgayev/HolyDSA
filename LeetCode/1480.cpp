#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> runningSum(vector<int>& nums) {
    	for(unsigned int i = 1; i < nums.size(); i++)
				nums[i] += nums[i - 1];
		return nums;
    }
};

int main() {
	Solution problem;
	vector<int> in = {1,2,3,4,5,6,7,8};
    	auto print = [](const int& n) { cout << n << ' '; };

	for_each(in.cbegin(), in.cend(), print); cout << endl;
	problem.runningSum(in);
	for_each(in.cbegin(), in.cend(), print);

	return 0;
}
