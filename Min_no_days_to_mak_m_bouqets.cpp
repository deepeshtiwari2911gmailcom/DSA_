class Solution {
public:
    // Function to find the minimum number of days to eat m bouquets with k flowers each
    int minDays(vector<int>& arr, int m, int k) {
        int n = arr.size();
        
        // Check if the total number of flowers is less than the required quantity
        if (n / k < m) {
            return -1; // If not possible, return -1
        }
        
        // Find the minimum and maximum bloom day
        int low = *min_element(arr.begin(), arr.end());
        int high = *max_element(arr.begin(), arr.end());
        
        // Perform binary search
        while (low <= high) {
            int mid = (low + high) / 2; // Calculate mid bloom day
            
            int ct = 0; // Initialize count of consecutive flowers in bloom
            int no_of_bq = 0; // Initialize count of bouquets formed
            
            for (int i = 0; i < n; i++) {
                if (arr[i] <= mid) {
                    ct++; // Increment count if the flower can be included in a bouquet
                }
                
                // Check if the current flower is not in bloom or it's the last flower
                if (arr[i] > mid || i == n - 1) {
                    no_of_bq += ct / k; // Calculate the number of bouquets formed
                    ct = 0; // Reset the count for the next batch of flowers
                }
            }
            
            // Determine the search range based on the number of bouquets formed
            if (no_of_bq >= m) {
                high = mid - 1; // If enough bouquets formed, reduce the bloom day
            } else {
                low = mid + 1; // If not enough bouquets formed, increase the bloom day
            }
        }
        
        return high + 1; // Return the minimum bloom day that satisfies the condition
    }
};
