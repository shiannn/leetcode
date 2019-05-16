class Solution {
public:
    void dfsgetString(string digits,int index,string curr,vector<string>dict,vector<string>*result){
        //digits:input numbers
        //index:current position on digits
        //curr: current result of answer
        //dict: alphabet for each number
        //result: accumulate curr [string, string, string,...]
        
        if(index==digits.size()){
            //get one string
            result->push_back(curr);
            return;
        }
        char strChar = digits[index];
        //current number
        for(int i=0;i<dict[strChar-'0'].size();i++){
            //turn char to number
            //search each alphabet of the number
            string temp=curr;
            curr+=dict[strChar-'0'][i];
            dfsgetString(digits,index+1,curr,dict,result);
            //next digit
            
            curr=temp;
            //recover curr
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits==""){
            //empty string
            return res;
        }
        vector<string> dict[10];
        //10 string vector
        dict[2]="abc";
        dict[3]="def";
        dict[4]="ghi";
        dict[5]="jkl";
        dict[6]="mno";
        dict[7]="pqrs";
        dict[8]="tuv";
        dict[9]="wxyz";

        string curr="\0";
        dfsgetString(digits,0,curr,dict,&res);
        return res;
    }
};
