#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    

    int maxFrequency(vector<int> &nums, int k, int numOperations) {
        int maxVal = *max_element(begin(nums), end(nums)) + k;
        vector<int> freq(maxVal + 1, 0);
        for (auto &num : nums) {
            freq[num]++;
        }
        for (int i = 1; i <= maxVal; i++) {
            freq[i] += freq[i - 1];
        }
        int answer = 0;
        for (int i = 0; i <= maxVal; i++) {
            if (freq[i] == 0) continue;
            int l = max(0, i - k);
            int r = min(i + k, maxVal);
            int elements = freq[r] - (l > 0 ? freq[l - 1] : 0);
            int exist = freq[i] - (i > 0 ? freq[i - 1] : 0);
            answer = max(answer, exist + min(numOperations, elements - exist));
        }
        return answer;
    }
};
