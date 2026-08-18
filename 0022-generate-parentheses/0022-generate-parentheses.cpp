class Solution {
public:

    void solve(string s, int open, int close, vector<string>& v) {

        if (open == 0 && close == 0) {
            v.push_back(s);
            return;
        }

        // Add '('
        if (open > 0) {
            solve(s + '(', open - 1, close, v);
        }

        // Add ')'
        if (close > open) {
            solve(s + ')', open, close - 1, v);
        }
    }

    vector<string> generateParenthesis(int n) {

        vector<string> v;

        solve("", n, n, v);

        return v;
    }
};