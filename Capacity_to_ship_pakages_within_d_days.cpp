class Solution {
public:
    // Function to calculate the number of days needed for given weight capacity
    int noof_days(vector<int>& arr, int cap) {
        long long load = 0;
        int noofdays = 1;

        // Traverse through the array to calculate the number of days needed
        for (int i = 0; i < arr.size(); i++) {
            // If adding the current item exceeds the capacity
            if (load + arr[i] > cap) {
                noofdays++; // Increment the number of days
                load = arr[i]; // Reset the load for the new day
            } else {
                load += arr[i]; // Add the item to the current day's load
            }
        }
        return noofdays; // Return the total number of days needed for given capacity
    }

    // Function to find the minimum weight capacity of the ship to ship all items within given days
    int shipWithinDays(vector<int>& arr, int days) {
        int n = arr.size();

        // Set the initial range of capacity between the maximum and total sum of items
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);

        // Perform binary search to find the minimum capacity
        while (low <= high) {
            int mid = (low + high) / 2;

            int no_of_days = noof_days(arr, mid); // Calculate days needed for current capacity

            // Adjust the search range based on the number of days calculated
            if (no_of_days <= days) {
                high = mid - 1; // If within or less than given days, reduce capacity
            } else {
                low = mid + 1; // If more than given days, increase capacity
            }
        }
        return low; // Return the minimum capacity satisfying the condition
    }
};
