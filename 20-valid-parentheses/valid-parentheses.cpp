class Solution {
public:
    // Function to check whether the given parentheses string is valid.
    bool isValid(string s) {

        // Stack is used to keep track of opening brackets.
        stack<char> st;

        // Traverse each character in the string.
        for (int i = 0; i < s.length(); i++) {

            // If the current character is an opening bracket,
            // push it onto the stack.
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            }
            else {

                // A closing bracket is valid only if:
                // 1. The stack is not empty.
                // 2. The top of the stack contains its matching opening bracket.
                if (st.empty() ||
                    (s[i] == ')' && st.top() != '(') ||
                    (s[i] == '}' && st.top() != '{') ||
                    (s[i] == ']' && st.top() != '[')) {

                    // Invalid parentheses sequence.
                    return false;
                }

                // Matching opening bracket found, remove it.
                st.pop();
            }
        }

        // The string is valid only if no unmatched opening brackets remain.
        return st.empty();
    }
};