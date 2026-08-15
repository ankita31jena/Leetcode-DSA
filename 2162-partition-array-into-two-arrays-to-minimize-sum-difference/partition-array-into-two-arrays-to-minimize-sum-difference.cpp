class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);

        int half = n / 2;

        vector<vector<int>> left(half + 1);
        vector<vector<int>> right(half + 1);

        // Generate all subset sums of left and right halves
        for (int mask = 0; mask < (1 << half); mask++) {
            int cnt = 0;
            int sumL = 0;
            int sumR = 0;

            for (int i = 0; i < half; i++) {
                if (mask & (1 << i)) {
                    cnt++;
                    sumL += nums[i];
                    sumR += nums[i + half];
                }
            }

            left[cnt].push_back(sumL);
            right[cnt].push_back(sumR);
        }

        // Sort right subset sums
        for (int i = 0; i <= half; i++) {
            sort(right[i].begin(), right[i].end());
        }

        int ans = INT_MAX;

        // Choose cnt elements from left
        // Then choose half-cnt elements from right
        for (int cnt = 0; cnt <= half; cnt++) {

            int need = half - cnt;

            for (int sumL : left[cnt]) {

                // We want:
                // |total - 2 * (sumL + sumR)|
                //
                // Ideally:
                // sumL + sumR ≈ total / 2

                int target = total / 2 - sumL;

                auto it = lower_bound(
                    right[need].begin(),
                    right[need].end(),
                    target
                );

                // Check element >= target
                if (it != right[need].end()) {
                    int sum = sumL + *it;
                    ans = min(ans, abs(total - 2 * sum));
                }

                // Check element just before target
                if (it != right[need].begin()) {
                    --it;

                    int sum = sumL + *it;
                    ans = min(ans, abs(total - 2 * sum));
                }
            }
        }

        return ans;
    }
};