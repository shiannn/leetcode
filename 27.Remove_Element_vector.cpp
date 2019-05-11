class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int N=nums.size();
        vector<int>::iterator it;
        for(it=nums.begin();it<nums.end();){
            if(*(it)==val){
                nums.erase(it);
                N--;
            }
            else{
                it++;
            }
        }
        return N;
    }
};
