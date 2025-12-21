class Solution {
public:
    string removeKdigits(string num, int k) {
    string st;   // use string as stack

    for (char c : num) {
        while (!st.empty() && st.back() > c && k > 0) {
            st.pop_back();
            k--;
        }
        st.push_back(c);
    }

    // Remove remaining digits if k > 0
    while (!st.empty() && k > 0) {
        st.pop_back();
        k--;
    }

    // Remove leading zeros
    int i = 0;
    while (i < st.size() && st[i] == '0') i++;

    st = st.substr(i);
    return st.empty() ? "0" : st;
}

};