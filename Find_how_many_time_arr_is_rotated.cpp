// Function to find the index of the minimum element in a rotated sorted array
int findKRotation(vector<int> &arr) {
    // Initialize variables
    int low = 0; // Starting index of the array
    int high = arr.size() - 1; // Ending index of the array
    int ans = 9999999; // Variable to store the minimum value found
    int idx = -1; // Variable to store the index of the minimum value

    // Perform binary search
    while (low <= high) {
        // Calculate mid point
        int mid = (low + high) / 2;

        // Check if the left side of mid is sorted
        if (arr[mid] >= arr[low]) {
            // Update ans and idx with the minimum value on the left side
            if (arr[low] < ans) {
                ans = arr[low];
                idx = low;
            }
            // Move the search range to the right side of mid
            low = mid + 1;
        } else {
            // Update ans and idx with the minimum value on the right side
            if (arr[mid] < ans) {
                ans = arr[mid];
                idx = mid;
            }
            // Move the search range to the left side of mid
            high = mid - 1;
        }
    }

    // Return the index of the minimum value found during the search
    return idx;
}
