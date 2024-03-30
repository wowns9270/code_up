class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        vector<int> sum;
        sum.resize(nums.size());

        sum[0] = nums[0];
        for(int i=1; i<nums.size(); i++)
        {
            sum[i] = sum[i-1] + nums[i];
        }
        int ret = -1;
        for(int i=0; i< nums.size(); i++)
        {
            if(i == 0)
            {
                if(0 == sum[nums.size()-1] - sum[0])
                {
                    ret = 0;
                    break;
                }
            }
            else
            {
                if(sum[i-1] == sum[nums.size()-1] - sum[i])
                {
                    ret = i;
                    break;
                }
            }
        }

        return ret;
    }
};