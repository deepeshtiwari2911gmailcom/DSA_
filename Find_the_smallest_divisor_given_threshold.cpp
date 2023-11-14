class Solution {
public:
    // Function to find the smallest divisor such that the sum of divisions <= threshold
    int smallestDivisor(vector<int>& arr, int threshold) {
        int low = 1; // Set the minimum possible divisor
        int high = *max_element(arr.begin(), arr.end()); // Set the maximum possible divisor
        
        // Perform binary search to find the smallest divisor
        while (low <= high) {
            int mid = (low + high) / 2; // Calculate mid divisor
            
            long long sum = 0; // Initialize the sum of divisions
            
            // Calculate the sum of divisions of array elements by the mid divisor
            for (int i = 0; i < arr.size(); i++) {
                sum += ceil((double)arr[i] / (double)mid); // Sum up the divisions
            }
            
            // Adjust the search range based on the sum compared to the threshold
            if (sum <= threshold) {
                high = mid - 1; // If sum is less than or equal to threshold, reduce the divisor
            } else {
                low = mid + 1; // If sum is greater than threshold, increase the divisor
            }
        }
        
        return low; // Return the smallest divisor satisfying the condition
    }
};
