My approach using gnu built in function __builtin_popcount

    class Solution
{
public:
    int setBits(int N)
    {
        return __builtin_popcount(N);
    }
};

Bit shifting method for the problem which emphasises on the fact that the AND operation with 1 gives 1 else it is 0 in every case

class Solution {
  public:
int setBits(int N)
{
    // Write Your Code here
    int c = 0;
    while (N)
    {
        if (N & 1)
        {
            c++;
            N = N >> 1;
        }
        else
        {
            N = N >> 1;
        }
    }
    return c;
}
}
;