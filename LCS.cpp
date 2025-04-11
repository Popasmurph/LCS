// LCS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int longestCommonSubsequence(const string& text1, const string& text2) {
    int m = text1.length();
    int n = text2.length();

    // Make a table for the sub calculations
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (text1[i - 1] == text2[j - 1]) {
                // If characters match, increment LCS length by 1
                // Below are debugging lines
                //cout << "Text1 is " << text1[i - 1] << "\n";
                //cout << "Text2 is " << text2[j - 1] << "\n";
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                // If characters don't match, take the maximum LCS length from previous subproblems
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

int main() {
    string text1 = "Apple Pie";
    string text2 = "Ape Pee";
    cout << "First string is " << text1 << "\n";
    cout << "Second string is " << text2 << "\n";
    int lcsLength = longestCommonSubsequence(text1, text2);
    cout << "Length of Longest Common Subsequence: " << lcsLength << endl; // Output: 3
    return 0;
}