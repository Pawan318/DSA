class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int>freq(3,0);
        int i = 0, answer = 0;
        for(int j = 0; j < s.size() ;j++){
            freq[s[j] - 'a']++;

            while(freq[0] && freq[1] && freq[2]){
                answer += s.size() - j;
                freq[s[i] - 'a']--;
                i++;
            }
        }
        return answer;
    }
};