#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	
	vector<string> res;
    void solve(int i , int n, string s , string ans )
	{
        if(i == n)
        {
           if(ans.length()>0)
                 res.push_back(ans) ;
           return;
        }
        else if(i<n)
        {
         solve(i+1,n,s,ans);
         ans.push_back(s[i]);
         cout<<ans<<'\n';
         solve(i+1,n,s,ans);
         return;  
        }
        
    }
		vector<string> AllPossibleStrings(string s)
		{
		    res.clear();
       int i = 0;
       int n = s.length();
       
       solve(0,n,s,"");
       sort(res.begin(),res.end());
       return res;
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	cin.ignore();
	while(tc--){
		string s;
		getline(cin,s);
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	
	}
}


class Solution{
	public:
	vector<string> v;
	void solve(string ip,string op)
	{
	    if(ip.size()==0)
	    {
	        v.push_back(op);
	        return;
	    } 
	    
	    string op1=op;
	    string op2=op;
	    op2.push_back(ip[0]);
	    ip.erase(ip.begin()+0);
	    
	    solve(ip,op1);
	    
	    solve(ip,op2);
	}
	
		vector<string> AllPossibleStrings(string s)
		{
		    // Code here
		    
		    v.clear();
		    string ip="";
		   // string op=s;
		    solve(s,ip);
		    
		    
		    sort(v.begin(),v.end());
		    
		    v.erase(v.begin()+0);
		    
		    
		    return v;
		    
		}
};
