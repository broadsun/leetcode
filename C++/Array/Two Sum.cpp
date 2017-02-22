class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res(2,-1); //初始值默认-1
        if (!nums.empty())
        {
            //定义一个map，key是nums的值，value是nums的索引
            unordered_map<int,int> tmp;
            for (int i = 0; i != nums.size(); ++i)
            {
                //遍历nums，如果在map里面没有找到与当前值匹配的项，则将当前值存入map，如果找到了，则success
                if (tmp.find(target-nums[i]) != tmp.end()) //从tmp里面找是否有数和当前值相加和为target
                {
                    res[0] = tmp[target-nums[i]];
                    res[1] = i;
                }
                else
                    tmp[nums[i]] = i;  //遍历nums，tmp的key是nums的值，value是nums中的下标索引
            }
        }
        return res;
    }
};