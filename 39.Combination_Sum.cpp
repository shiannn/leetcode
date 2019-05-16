class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>>res;
        vector<int>out;
        combinationSumDFS(candidates,target,0,out,res);
        return res;
    }
    //pass reference
    void combinationSumDFS(vector<int>&candidates,int target,int start,vector<int>&out,vector<vector<int>>&res){
        //choose candidate[i]
        //no candidate[i] but candidates[i+1]
        //no candidates[i] candidates[i+1] but candidates[i+2]
        //...
        if(target<0)return;
        if(target==0){res.push_back(out);return;}
        for(int i=start;i<candidates.size();i++){
            //no need to permutate, only check the following 
            out.push_back(candidates[i]);
            combinationSumDFS(candidates,target-candidates[i],i,out,res);
            //can choose candidates[i] repeatedly
            out.pop_back();
        }
    }
};
