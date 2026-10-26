
class Solution {
private:
    int pivot(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;

        while (s < e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] >= nums[0]) {
                s = mid + 1;
            } else {
                e = mid;
            }
        }

        return s;
    }

    int binarySearch(vector<int>& nums, int target, int st, int end) {
        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            if (nums[mid] > target) {
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }

        return -1;
    }

public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        if (n == 0) return -1;

        int pivotElement = pivot(nums);

        // Check whether the target is the pivot element
        if (nums[pivotElement] == target) {
            return pivotElement;
        }

        // Search the appropriate sorted half
        if (target >= nums[0]) {
            return binarySearch(nums, target, 0, pivotElement - 1);
        } else {
            return binarySearch(nums, target, pivotElement, n - 1);
        }
    }
};
