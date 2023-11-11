class Solution {
public:
    // Function to find the single non-duplicate element in a sorted array
    int singleNonDuplicate(vector<int>& arr) {
        int low = 0; // Initialize the starting index
        int high = arr.size() - 1; // Initialize the ending index

        // Check if there is only one element in the array
        if (high == 0) {
            return arr[0];
        }

        // Check if the single non-duplicate element is at the beginning
        if (arr[0] != arr[1]) {
            return arr[0];
        }

        // Check if the single non-duplicate element is at the end
        if (arr[high - 1] != arr[high]) {
            return arr[high];
        }

        // Perform binary search
        while (low < high) {
            int mid = (low + high) / 2;

            // Check if the single non-duplicate element is found
            if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1]) {
                return arr[mid];
            }

            // Adjust the search range based on the parity of mid
            if (mid % 2 == 0) {
                if (arr[mid] == arr[mid - 1]) {
                    high = mid + 1;
                } else {
                    low = mid - 1;
                }
            } else {
                if (arr[mid] == arr[mid - 1]) {
                    low = mid - 1;
                } else {
                    high = mid + 1;
                }
            }
        }

        // Return -1 if no single non-duplicate element is found
        return -1;
    }
};
