class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index=nums.size()-1;
        while(index>0&&nums[index]<=nums[index-1]){
            //index-1 to index would be increase
            index--;
        }
        if(index==0){
            //the whole array is decreasing
            sort(nums.begin(),nums.end());
            return;
        }
        //the smallest number which is larger than index-1
        int second=INT_MAX,secondIndex=INT_MAX;
        for(int i=nums.size()-1;i>=index;i--){
            if(nums[i]>nums[index-1]){
                if(nums[i]<second){
                    second=nums[i];
                    secondIndex=i;
                }
            }
        }
        //swap nums[index-1] and nums[secondIndex]
        int temp=nums[index-1];
        nums[index-1]=nums[secondIndex];
        nums[secondIndex]=temp;
        
        //the nums[index~end] should be ascending
        sort(nums.begin()+index,nums.end());
    }
};
