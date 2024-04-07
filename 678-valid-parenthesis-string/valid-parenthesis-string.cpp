class Solution {
public:
    bool checkValidString(string s) {
    int openCount = 0; // Count of open parentheses '('
    int asteriskCount = 0; // Count of asterisks '*'
    int n = s.length();

    // Traverse through the string from left to right
    for(int i = 0; i < n; i++) {
        if(s[i] == '(') {
            openCount++; // Increment count of open parentheses
        } else if(s[i] == ')') {
            // If there are open parentheses, close one
            if(openCount > 0) {
                openCount--; // Match '(' with ')'
            } else if(asteriskCount > 0) {
                asteriskCount--; // Use '*' to match with ')'
            } else {
                // No matching '(' or '*' found
                return false;
            }
        } else if(s[i] == '*') {
            // Increment count of asterisks
            asteriskCount++;
        }
    }

    // After traversing the string from left to right, check if any unmatched open parentheses
    int closeCount = 0; // Count of close parentheses ')'
    asteriskCount = 0; // Reset asterisk count
    // Traverse through the string from right to left
    for(int i = n - 1; i >= 0; i--) {
        if(s[i] == ')') {
            closeCount++; // Increment count of close parentheses
        } else if(s[i] == '(') {
            // If there are unmatched close parentheses, try to match
            if(closeCount > 0) {
                closeCount--; // Match ')' with '('
            } else if(asteriskCount > 0) {
                asteriskCount--; // Use '*' to match with '('
            } else {
                // No matching ')' or '*' found
                return false;
            }
        } else if(s[i] == '*') {
            // Increment count of asterisks
            asteriskCount++;
        }
    }

    return true; // All parentheses matched correctly
}

};