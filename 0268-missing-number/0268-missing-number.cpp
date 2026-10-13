class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i = 0;

        while (i <= nums.size()) {
            int flag = 0;

            for (int j = 0; j < nums.size(); j++) {
                if (i == nums[j]) {
                    flag = 1;
                    break;
                }
            }

            if (flag == 0) {
                return i;
            }

            i++;
        }

        return -1;
    }
};