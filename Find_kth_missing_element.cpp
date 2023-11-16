int findKthPositive(vector<int>& arr, int k) {
    int n = arr.size(); // Get the size of the array
    int low = 0; // Initialize the low index of the array
    int high = n - 1; // Initialize the high index of the array

    // Perform binary search to find the k-th missing positive integer
    while (low <= high) {
        int mid = (low + high) / 2; // Calculate the middle index
        int val = arr[mid] - (mid + 1); // Calculate the number of missing elements before index mid

        // Output the current index and calculated value for debugging purposes
        //cout << mid << " " << val << endl;

        // If the number of missing elements before index mid is less than k
        if (val < k) {
            low = mid + 1; // Adjust the search range to the right side of mid
        } 
        // If the number of missing elements before index mid is greater than or equal to k
        else {
            high = mid - 1; // Adjust the search range to the left side of mid
        }
    }

    // At this point, low points to the first index where the number of missing elements exceeds k.
    // The number of missing elements before low is less than k, so add k to it to get the k-th missing number.
    // high keeps track of the count of missing elements before it, so adding k to it and 1 more to get the k-th missing number.
    return k + high + 1; // Return the k-th missing positive integer
}
