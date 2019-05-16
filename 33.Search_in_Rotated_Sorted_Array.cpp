class Solution {
public:
    int search(vector<int>& nums, int target) {
        int high=nums.size()-1;
        int mid=0;
        int low=0;
        while(low<=high){
            mid=(low+high)/2;
            //middle of the vector
            if(nums[mid]==target)
                return mid;
            if(nums[low]<=nums[mid]){
                //low to mid is sorted
                if(nums[low]<=target && target<=nums[mid]){
                    high=mid-1; 
                }
                else{
                    low=mid+1;
                }
            }
            else{
                //mid to high is sorted
                if(nums[mid]<=target && target<=nums[high]){
                    low=mid+1;    
                }
                else{
                    high=mid-1;
                }
            }
        }
        return -1;
    }
};