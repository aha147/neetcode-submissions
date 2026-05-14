class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stack;
        std::unordered_map<char,char> pairs = {{')', '('},
            {']', '['},
            {'}', '{'}};

        for (char c : s)
        {
            if(pairs.count(c))
            {
                if(!stack.empty() && stack.top() == pairs[c])
                {
                    stack.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                stack.push(c);
            }
        }
        return stack.empty();
    }
};
