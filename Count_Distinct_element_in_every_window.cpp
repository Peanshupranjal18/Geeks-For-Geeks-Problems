// Important Concept for unordered map to store frequency and if the frequency of the element is zero we can erase it learned new concept related to maps in C++

// Code

class Solution
{
public:
    vector<int> countDistinct(int a[], int n, int k)
    {
        unordered_map<int, int> mp;

        int i = 0;

        for (; i < k; i++)
            mp[a[i]]++;

        int ans = mp.size();
        vector<int> v;
        v.push_back(ans);

        for (; i < n; i++)
        {

            mp[a[i - k]]--;

            if (mp[a[i - k]] == 0)
            {
                mp.erase(a[i - k]);
            }

            mp[a[i]]++;

            ans = mp.size();
            v.push_back(ans);
        }

        return v;
    }
};