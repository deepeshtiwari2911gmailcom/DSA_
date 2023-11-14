long long int power(long long int a, long long int b, int m) {
    long long int ans = 1;
    while (b > 0) {
        // Check if a * ans exceeds m, indicating overflow
        if (a * ans > m) {
            return 0; // If overflow occurs, return 0
        }
        ans = ans * a;
        b--;
    }
    // Check conditions to determine the return value
    if (ans == m) {
        return 1; // If the result equals m, return 1
    } else if (ans < m) {
        return 2; // If the result is less than m, return 2
    }
    return ans; // Return the calculated value
}

int NthRoot(int n, int m) {
    long long int low = 1, high = m;
    while (low <= high) {
        long long int mid = (low + high) / 2;
        long long int val = power(mid, n, m);
        if (val == 1) {
            return mid; // If the power function returns 1, mid is the Nth root of m
        } else if (val == 0) {
            high = mid - 1; // If the power function returns 0, reduce the search range
        } else {
            low = mid + 1; // If the power function returns 2, increase the search range
        }
    }
    return -1; // If no Nth root found within the given range, return -1
}
