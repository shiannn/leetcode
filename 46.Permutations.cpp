class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        int len=nums.size(); 
        vector<int> vis(len,0);
        vector<int>path;
        dfs(nums,0,vis,res,path);
        return res;
    }
    void dfs(vector<int>& nums, int pos, vector<int>& visited, vector<vector<int>>& res, vector<int>& path){
        int N=nums.size();
        if(pos==N){
            res.push_back(path);
            return;
        }
        for(int i=0;i<N;i++){
            if(!visited[i]){
                visited[i]=1;
                path.push_back(nums[i]);
                dfs(nums,pos+1,visited,res,path);
                //go back to the last layer
                path.pop_back();
                visited[i]=0;
            }
        }
    }
};
