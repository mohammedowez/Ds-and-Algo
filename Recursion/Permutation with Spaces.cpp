Input:
S = "ABC"
Output: (A B C)(A BC)(AB C)(ABC)
Explanation:
ABC
AB C
A BC
A B C
These are the possible combination of "ABC".



class Solution{
public:
    
    void solve(string ip,string op,vector<string> &v)
    {
       
        if(ip.size()==0)
        {
            v.push_back(op);
            return;
        }
        
        string op1=op;
        string op2=op;
        op1.push_back(' ');
        op1.push_back(ip[0]);
        op2.push_back(ip[0]);
        ip.erase(ip.begin()+0);
        
        solve(ip,op1,v);
        
        solve(ip,op2,v);
        
        
        
        
    }


    vector<string> permutation(string S){
        // Code Here
         
        vector<string> v;
        string op;
        op.push_back(S[0]);
        S.erase(S.begin()+0);
        solve(S,op,v);
        //sort(v.begin(),v.end());
        return v;
    }
};
