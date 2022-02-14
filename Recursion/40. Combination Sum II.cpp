Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]

class Solution {
public:
    vector<vector<int>>ans;
    vector<int>ds;
    
    void helper(int index, int target, vector<int>&candidates){
        //base case
        //when the combination ds is carrying is a valid one add it into th ans
        if(target == 0){
            ans.push_back(ds);
            return;
        }
        for(int i = index; i< candidates.size(); i++){
            if(candidates[i] > target) break; // no point of it to add it to the ans if the  candidate at ith element exceeds the target no picking up hence break 
            if(i  > index && candidates[i] == candidates[i-1])
                continue;
                //to avoid picking up the same elements and thus avoiding duplicates (no picking of element)
            ds.push_back(candidates[i]);
            helper(i+1, target- candidates[i], candidates); //call for next  index element
            ds.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());//sort the given candidates vector 
        ans.clear();
        helper(0, target, candidates);
        return ans;
    }
};
