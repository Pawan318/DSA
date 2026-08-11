class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        if (n % groupSize != 0)
            return false;

        unordered_map<int, int> freq;
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int x : hand) {
            freq[x]++;
            pq.push(x);
        }

        while (!pq.empty()) {
            // Remove values whose frequency became zero
            while (!pq.empty() && freq[pq.top()] == 0) {
                pq.pop();
            }

            if (pq.empty())
                break;

            int start = pq.top();

            // Create one consecutive group
            for (int x = start; x < start + groupSize; x++) {
                if (freq[x] == 0)
                    return false;

                freq[x]--;
            }
        }

        return true;
    }
};