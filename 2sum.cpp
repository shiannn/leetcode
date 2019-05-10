class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>m;
        unordered_map<int,int>n;
        for(int i=0;i<nums.size();i++){
            if(m.count(nums[i])==1){
                if(n.count(nums[i])==0){
                     n[nums[i]]=i; 
                }
            }
            else{
                 m[nums[i]]=i;
            }
        }
        vector<int> res;
        sort(nums.begin(),nums.end());
        int N=nums.size();
        int left=0,right=N-1;
        while(left<right){
            if(nums[left]+nums[right]<target){
                left++;
            }
            else if(nums[left]+nums[right]>target){
                right--;
            }
            else{
                if(nums[left]==nums[right]){
                    res.push_back(m[nums[left]]);
                    res.push_back(n[nums[right]]);
                }
                else{
                    res.push_back(m[nums[left]]);
                    res.push_back(m[nums[right]]);   
                }             
                break;
            }
        }
        return res;
    }
};
