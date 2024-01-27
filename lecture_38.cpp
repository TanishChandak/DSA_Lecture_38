#include <iostream>
#include <vector>
#include <string>
using namespace std;
// Function of letter combination of a phone number:
void solve(const string &digits, string &output, int index, vector<string> &ans, const string mapping[])
{
    // Base case: when the current index is equal to the length of the digits string
    if (index == digits.length())
    {
        ans.push_back(output);
        return;
    }

    // Find the letters corresponding to the current digit
    int digit = digits[index] - '0';
    string letters = mapping[digit];

    // Recur for each letter in the string
    for (int i = 0; i < letters.length(); i++)
    {
        output.push_back(letters[i]);
        solve(digits, output, index + 1, ans, mapping);
        output.pop_back(); // Backtrack
    }
}
// Here it will map the numbers of letters:
vector<string> letterCombinations(string digits)
{
    vector<string> ans;
    if (digits.empty())
    {
        return ans;
    }
    string output;
    int index = 0;
    string mapping[10] = {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    solve(digits, output, index, ans, mapping);
    return ans;
}
int main()
{
    // Letter combination of a phone number:
    string digits = "23";
    vector<string> ans1 = letterCombinations(digits);
    cout << "The Combination of the letter is: ";
    for (int i = 0; i < ans1.size(); i++)
    {
        cout << ans1[i] << " ";
    }
    return 0;
}