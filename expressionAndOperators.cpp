class Solution {
public:
    vector<string> ans;

    void solve(string &num, int target,
               int idx,
               long long currVal,
               long long prevNum,
               string expr) {

        if (idx == num.size()) {
            if (currVal == target) {
                ans.push_back(expr);
            }
            return;
        }

        long long number = 0;

        for (int i = idx; i < num.size(); i++) {

            // Leading zero check
            if (i > idx && num[idx] == '0')
                break;

            number = number * 10 + (num[i] - '0');

            string currStr = num.substr(idx, i - idx + 1);

            // First number
            if (idx == 0) {
                solve(num, target,
                      i + 1,
                      number,
                      number,
                      currStr);
            }
            else {

                // +
                solve(num, target,
                      i + 1,
                      currVal + number,
                      number,
                      expr + "+" + currStr);

                // -
                solve(num, target,
                      i + 1,
                      currVal - number,
                      -number,
                      expr + "-" + currStr);

                // *
                solve(num, target,
                      i + 1,
                      currVal - prevNum + prevNum * number,
                      prevNum * number,
                      expr + "*" + currStr);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        solve(num, target, 0, 0, 0, "");
        return ans;
    }
};