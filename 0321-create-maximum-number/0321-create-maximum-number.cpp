class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> max_res;
        for (int i = max(0, k - n); i <= min(k, m); ++i) {
            vector<int> seq1 = maxArray(nums1, i);
            vector<int> seq2 = maxArray(nums2, k - i);
            vector<int> candidate = merge(seq1, seq2);
            if (candidate > max_res) {
                max_res = candidate;
            }
        }   
        return max_res;
    }
private:
    vector<int> maxArray(const vector<int>& nums, int k) {
        int drop = nums.size() - k; 
        vector<int> stack;        
        for (int num : nums) {
            while (drop > 0 && !stack.empty() && stack.back() < num) {
                stack.pop_back();
                drop--;
            }
            stack.push_back(num);
        }
        stack.resize(k); 
        return stack;
    }
    vector<int> merge(const vector<int>& seq1, const vector<int>& seq2) {
        vector<int> res;
        int i = 0, j = 0;
        while (i < seq1.size() || j < seq2.size()) {
            if (isGreater(seq1, i, seq2, j)) {
                res.push_back(seq1[i++]);
            } else {
                res.push_back(seq2[j++]);
            }
        }
        return res;
    }
    bool isGreater(const vector<int>& seq1, int i, const vector<int>& seq2, int j) {
        while (i < seq1.size() && j < seq2.size() && seq1[i] == seq2[j]) {
            i++;
            j++;
        }
        if (j == seq2.size()) return true;
        if (i == seq1.size()) return false;
        return seq1[i] > seq2[j];
    }
};