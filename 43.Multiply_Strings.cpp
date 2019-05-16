class Solution {
public:
    string multiply(string num1, string num2) {
        string res="";
        int m=num1.size(),n=num2.size();
        if(num1[0]=='0'||num2[0]=='0'){
            res="0";
            return res;
        }
        vector<int>vals(m+n,0);
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int mul=(num1[i]-'0')*(num2[j]-'0');
                int tempR=i+j+1,tempL=i+j;
                vals[tempR]+=mul;
                vals[tempL]+=vals[tempR]/10;
                vals[tempR]%=10;
            }
        }
        for(int val=0;val<vals.size();val++){
            if(vals[val]==0&&val==0)continue;
            res.push_back(vals[val]+'0');
        }
        return res;
    }
};
