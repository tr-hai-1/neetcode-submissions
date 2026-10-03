class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char ch : s) {
            if (ch == '(' || ch == '[' || ch == '{')
                st.push(ch);
            if (st.empty())
                return false;
            if (ch == ')' && st.top() != '(')
                return false;
            if (ch == ']' && st.top() != '[')
                return false;
            if (ch == '}' && st.top() != '{')
                return false;
            if (ch == ')' || ch == ']' || ch == '}')
                st.pop();
        }
        return st.empty();
    }
};
