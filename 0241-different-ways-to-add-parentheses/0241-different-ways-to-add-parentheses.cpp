class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        int n = expression.size();
        vector<int> res;
        for (int i = 0; i < n; i++) {
            char opr = expression[i];
            if (opr == '+' || opr == '-' || opr == '*') {
                vector<int> s1 = diffWaysToCompute(expression.substr(0, i));
                vector<int> s2 = diffWaysToCompute(expression.substr(i + 1));
                for (int a : s1) {
                    for (int b : s2) {
                        if (opr == '+')
                            res.push_back(a + b);
                        else if (opr == '-')
                            res.push_back(a - b);
                        else if (opr == '*')
                            res.push_back(a * b);
                    }
                }
            }
        }
        if (res.empty())
            res.push_back(stoi(expression));
        return res;
    }
};