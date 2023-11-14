class Solution {
public:
    // Function to find the minimum eating speed to eat all bananas within h hours
    int minEatingSpeed(vector<int>& arr, int h) {
        int low = 1; // Initialize the minimum speed
        int high = *max_element(arr.begin(), arr.end()); // Initialize the maximum speed
        
        // Perform binary search
        while (low <= high) {
            int mid = (low + high) / 2; // Calculate mid speed
            
            long long int hrs = 0; // Initialize hours taken to eat all bananas
            
            // Calculate total hours needed to eat all bananas at the current speed
            for (int i = 0; i < arr.size(); i++) {
                // Calculate hours for each pile of bananas and sum them up
                hrs += ceil((double)arr[i] / (double)mid);
            }
            
            // Check if the total hours taken at current speed is within the given limit
            if (hrs <= h) {
                // If yes, reduce the eating speed as we might find a slower speed satisfying the condition
                high = mid - 1;
            } else {
                // If no, increase the eating speed to eat bananas in less time
                low = mid + 1;
            }
        }
        
        // Return the minimum eating speed that satisfies the time limit
        return low;
    }
};
