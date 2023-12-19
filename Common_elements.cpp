// map method

class Solution
{
public:
    // determining common elements
    vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
    {
        map<int, int> m1, m2, m3;
        for (int i = 0; i < n1; i++)
            m1[A[i]]++;
        for (int i = 0; i < n2; i++)
        {
            if (m1[B[i]])
                m2[B[i]]++;
        }
        for (int i = 0; i < n3; i++)
        {
            if (m2[C[i]])
                m3[C[i]]++;
        }
        vector<int> ans;
        for (auto pair : m3)
            ans.push_back(pair.first);
        return ans;
    }
};

//