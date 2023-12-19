// Backend complete function template for C++

class Solution
{
public:
    string longestCommonPrefix(string arr[], int n)
    {
        if (n == 1)
            return arr[0];

        string res = "";
        bool include;
        for (int i = 0; i < arr[0].length(); ++i)
        {
            include = true;
            for (int j = 1; j < n; ++j)
            {
                // checking if the current character arr[0][i] is eligible
                // for being included in the result or not
                if (i >= arr[j].length() || arr[0][i] != arr[j][i])
                {
                    include = false;
                    break;
                }
            }
            // if it can't be included, we need not check the further characters
            if (!include)
                break;
            // if it can be included, we include it and check ahead
            res += arr[0][i];
        }
        if (res == "")
            return "-1";
        return res;
    }
    // Contributed By: Pranay Bansal
};