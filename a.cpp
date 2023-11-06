class Solution {
public:
    // Function to find the lower bound of the target in the 'nums' array
    int lowerbound(vector<int>& nums, int high, int target) {
        int low = 0;
        int high = high;
        int first = -1; // Initialize the first occurrence to -1
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) {
                first = mid; // Update the first occurrence if found
                high = mid - 1; // Move the search to the left half
            } else if (nums[mid] < target) {
                low = mid + 1; // Target is in the right half
            } else {
                high = mid - 1; // Target is in the left half
            }
        }
        return first; // Return the index of the lower bound
    }

    // Function to find the upper bound of the target in the 'nums' array
    int upperbound(vector<int>& nums, int high, int target) {
        int low = 0;
        int high = high;
        int first = -1; // Initialize the first occurrence to -1
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) {
                first = mid; // Update the first occurrence if found
                low = mid + 1; // Move the search to the right half
            } else if (nums[mid] > target) {
                high = mid - 1; // Target is in the left half
            } else {
                low = mid + 1; // Target is in the right half
            }
        }
        return first; // Return the index of the upper bound
    }

    // Main function to search for the range of target in 'nums'
    vector<int> searchRange(vector<int>& nums, int target) {
        int lower = lowerbound(nums, nums.size() - 1, target);
        vector<int> result;
        result.push_back(lower); // Push the lower bound to the result vector

        if (lower == -1) {
            result.push_back(-1); // If lower bound is not found, push -1
            return result;
        } else {
            int upper = upperbound(nums, nums.size() - 1, target);
            result.push_back(upper); // Push the upper bound to the result vector
            return result;
        }
    }
};
