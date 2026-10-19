class Solution {
private:
    int maxi(vector<int>& piles) {
        int maximum = INT_MIN;

        for (auto i : piles) {
            maximum = max(maximum, i);
        }

        return maximum;
    }

public:
    bool isPossible(int value, vector<int>& piles, int h) {
        long long totalHour = 0;

        for (auto i : piles) {
            totalHour += (i + value - 1LL) / value;
        }

        return totalHour <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1;
        int e = maxi(piles);
        int ans = e;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (isPossible(mid, piles, h)) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        return ans;
    }
};