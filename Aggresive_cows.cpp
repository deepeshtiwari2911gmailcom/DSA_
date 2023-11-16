int maxDistance(vector<int>& arr, int m) {
    sort(arr.begin(), arr.end()); // Sort the given array in ascending order

    int low = 1; // Set the minimum possible distance
    int high = arr[arr.size() - 1] - arr[0]; // Set the maximum possible distance

    while (low <= high) {
        long long mid = (high + low) / 2; // Calculate the middle distance

        int ct = 1; // Initialize count of elements between selected distances
        int last = arr[0]; // Initialize the last selected element

        for (int i = 1; i < arr.size(); i++) {
            // Check the distance between current element and the last selected element
            if (arr[i] - last >= mid) {
                ct++; // Increment the count as the current element satisfies the distance condition
                last = arr[i]; // Update the last selected element
            }

            // Break the loop if the required count of elements is reached
            if (ct >= m) {
                break;
            }
        }

        // Adjust the search range based on the count of elements satisfying the distance condition
        if (ct < m) {
            high = mid - 1; // If the count is less than required, reduce the distance
        } else {
            low = mid + 1; // If the count is greater than or equal to required, increase the distance
        }
    }

    return high; // Return the maximum distance satisfying the condition
}
