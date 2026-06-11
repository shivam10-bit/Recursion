class Solution {
public:

    void solve(vector<int>& candidates,
               int idx,
               int target,
               vector<int>& curr,
               vector<vector<int>>& ans) {

        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        if (idx == candidates.size() || target < 0)
            return;

        // Take
        curr.push_back(candidates[idx]);
        solve(candidates, idx, target - candidates[idx], curr, ans);
        curr.pop_back();

        // Skip
        solve(candidates, idx + 1, target, curr, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates,
                                       int target) {

        vector<vector<int>> ans;
        vector<int> curr;

        solve(candidates, 0, target, curr, ans);

        return ans;
    }
};