// Function to find the lower bound of 'target' in 'nums' array
int lowerbound(vector<int>& nums, int hight, int target) {
    int low = 0;
    int high = hight;
    int first = -1; // Initialize the first occurrence to -1
    while (low <= high) {
        int mid = (low + high) / 2;
        if (nums[mid] == target) {
            first = mid; // Update the first occurrence if found
            high = mid - 1; // Move the search to the left half
        } else if (nums[mid] < target) {
            low = mid + 1; // Target is in the right half
        } else {
            high = mid - 1; // Target is in the left half
        }
    }
    return first; // Return the index of the lower bound
}

// Function to find the upper bound of 'target' in 'nums' array
int upperbound(vector<int>& nums, int hight, int target) {
    int low = 0;
    int high = hight;
    int first = -1; // Initialize the first occurrence to -1
    while (low <= high) {
        int mid = (low + high) / 2;
        if (nums[mid] == target) {
            first = mid; // Update the first occurrence if found
            low = mid + 1; // Move the search to the right half
        } else if (nums[mid] > target) {
            high = mid - 1; // Target is in the left half
        } else {
            low = mid + 1; // Target is in the right half
        }
    }
    return first; // Return the index of the upper bound
}

// Function to count occurrences of 'x' in 'arr'
int count(vector<int>& arr, int n, int x) {
    int k = lowerbound(arr, n - 1, x);
    if (k == -1)
        return 0; // Target not found, return 0.
    else {
        int kl = upperbound(arr, n - 1, x);
        return kl - k + 1; // Return the count of occurrences of 'x' in the array.
    }
}
