class Solution {
public:
    int candy(vector<int>& ratings) {

        int n = ratings.size();

        if(n <= 1)
            return n;

        int result = 1;

        int up = 0;
        int down = 0;
        int peak = 0;

        for(int i = 1; i < n; i++) {

            if(ratings[i] > ratings[i - 1]) {

                up++;
                down = 0;
                peak = up;

                result += up + 1;
            }

            else if(ratings[i] < ratings[i - 1]) {

                down++;
                up = 0;

                result += down;

                if(down > peak)
                    result++;
            }

            else {

                up = 0;
                down = 0;
                peak = 0;

                result++;
            }
        }

        return result;
    }
};