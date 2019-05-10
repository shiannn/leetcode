//#include <iostream> 
//#include <algorithm>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;//to return
        sort(nums.begin(),nums.end());//begin address end address
        if(nums.empty()||nums.back()<0||nums.front()>0)return {};
        //empty nums  or all positive or all negative
        for(int k=0;k<nums.size();k++){
            if(nums[k]>0)break;//followed are all positive
            if(k>0 && nums[k]==nums[k-1])continue;//no need to do same thing again
            int target=-nums[k];
            int i=k+1,j=nums.size()-1;
            //double pointer check in O(n)
            while(i<j){
                if(nums[i]+nums[j]==target){
                    res.push_back({nums[k],nums[i],nums[j]});
                    //add one answer(vector<int>) into res(vector<vector<int>>)
                    while(i<j&&nums[i]==nums[i+1])i++;
                    while(i<j&&nums[j]==nums[j-1])j--;
                    //move two pointers until different element appears
                    i++;
                    j--;
                    //two pointers should move instaneously
                    //or it is impossible to get the target
                }
                else if(nums[i]+nums[j]<target)i++;
                //not big enough => i move right
                else j--;
                //not small enough => j move left
            }
        }
        return res;
    }
};
//O(n^2)
