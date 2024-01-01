// Given a string without spaces, the task is to remove duplicates from it.

// Note: The original order of characters must be kept the same.

class Solution
{
public:
    string removeDups(string a)
    {
        unordered_map<char, int> mp;
        string ans = "";
        for (int i = 0; i < a.length(); i++)
        {
            if (mp[a[i]] == 1)
                continue;
            else
            {
                ans.push_back(a[i]);
                mp[a[i]]++;
            }
        }
        return ans;
    }
};
