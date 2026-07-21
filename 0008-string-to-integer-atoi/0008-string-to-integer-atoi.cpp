class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.length();
        
        // 1️⃣ Skip whitespace
        while(i < n && s[i] == ' ')
            i++;

        // 2️⃣ Check sign
        int sign = 1;
        if(i < n && (s[i] == '+' || s[i] == '-')) {
            if(s[i] == '-') sign = -1;
            i++;
        }

        // 3️⃣ Convert digits
        long result = 0;  // use long to detect overflow safely

        while(i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            // 4️⃣ Check overflow
            if(result > INT_MAX / 10 || 
              (result == INT_MAX / 10 && digit > 7)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            i++;
        }

        return sign * result;
    }
};
