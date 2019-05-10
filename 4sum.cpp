class Solution{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++){
            //reserve 3 positions for j left right
            if(i>0&&nums[i]==nums[i-1])continue;
            for(int j=i+1;j<n-2;j++){
                //reserve 2 position for left right
                if(j>i+1&&nums[j]==nums[j-1])continue;
                int left=j+1, right=n-1;
                while(left < right){
                    int sum=nums[i]+nums[j]+nums[left]+nums[right];
                    if(sum==target){
                        //out is a vector<int>
                        vector<int> out={nums[i],nums[j],nums[left],nums[right]};
                        res.push_back(out);
                        while(left<right && nums[left]==nums[left+1])left++;
                        while(left<right && nums[right]==nums[right-1])right--;
                        //no need to output same result
                        left++;right--;
                        //two pointer to change together or they will not satisfy
                        //target
                    }
                    else if(sum<target)left++;
                    else right--;
                }
            }
        }
        return res;
    }
};
