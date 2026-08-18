class Solution1 {
public:
    bool lemonadeChange(vector<int>& bills) {

        vector<int> freq(3, 0);

        for (int bill : bills) {
            if (bill == 5) {
                freq[0]++;
            }
            else if (bill == 10) {
                if (freq[0] == 0)
                    return false;
                freq[0]--;
                freq[1]++;
            }
            else { // bill == 20

                if (freq[1] > 0 && freq[0] > 0) {
                    freq[1]--;
                    freq[0]--;
                }
                else if (freq[0] >= 3) {
                    freq[0] -= 3;
                }
                else {
                    return false;
                }

                freq[2]++;
            }
        }
        return true;
    }
};

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        for(int bill : bills){
            if(bill == 5){
                five++;
            }
            else if(bill == 10){
                if(five == 0) return false;
                ten++;
                five--;
            }
            else{
                if(five > 0 && ten > 0){
                    ten--;
                    five--;
                }
                else if(five >= 3){
                    five -= 3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};