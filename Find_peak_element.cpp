class Solution {
public:
    // Function to find a peak element in an array
    int findPeakElement(vector<int>& arr) {
        int n = arr.size();

        // Check if there is only one element in the array
        if (n == 1) {
            return 0;
        }

        // Check if the peak element is at the beginning
        if (arr[0] > arr[1]) {
            return 0;
        }

        // Check if the peak element is at the end
        if (arr[n - 1] > arr[n - 2]) {
            return n - 1;
        }

        // Initialize the search range
        int low = 1;
        int high = n - 2;

        // Perform binary search
        while (low <= high) {
            int mid = (low + high) / 2;

            // Check if the current element is a peak
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
                return mid;
            }
            // Adjust the search range based on the increasing slope
            else if (arr[mid] < arr[mid + 1]) {
                low = mid + 1;
            }
            // Adjust the search range based on the decreasing slope
            else if (arr[mid] < arr[mid - 1]) {
                high = mid - 1;
            }
            // If the slope is neither increasing nor decreasing, move the range to the decreasing slope
            else {
                high = mid - 1;
            }
        }

        // Return -1 if no peak element is found
        return -1;
    }
};
