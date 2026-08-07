class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        int totalSum = 0;
        for (int x : cardPoints)
            totalSum += x;

        // If taking all cards
        if (k == n)
            return totalSum;

        int windowSize = n - k;

        int windowSum = 0;

        // First window
        for (int i = 0; i < windowSize; i++)
            windowSum += cardPoints[i];

        int minWindowSum = windowSum;

        // Slide the window
        for (int i = windowSize; i < n; i++) {
            windowSum += cardPoints[i];
            windowSum -= cardPoints[i - windowSize];
            minWindowSum = min(minWindowSum, windowSum);
        }

        return totalSum - minWindowSum;
    }
};