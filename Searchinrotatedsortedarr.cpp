class Solution {
public:
    int search(vector<int>& arr, int target) {
        int low = 0;
        int high = arr.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] == target) {
                return mid; // If the target is found at the current mid index, return it.
            } else {
                // Check if the left subarray is sorted.
                if (arr[low] <= arr[mid]) {
                    if (arr[low] <= target && target <= arr[mid]) {
                        high = mid - 1; // Adjust the search range to the left subarray.
                    } else {
                        low = mid + 1; // Adjust the search range to the right subarray.
                    }
                } else {
                    // The right subarray is sorted.
                    if (arr[mid] <= target && target <= arr[high]) {
                        low = mid + 1; // Adjust the search range to the right subarray.
                    } else {
                        high = mid - 1; // Adjust the search range to the left subarray.
                    }
                }
            }
        }
        return -1; // Return -1 if the target is not found in the array.
    }
};
