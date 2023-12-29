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

Another Approach for the problem (Brian Kernighan Algorithm)

Intuition

Subtracting 1 from a decimal number flips all the bits after the rightmost set bit(which is 1) including the rightmost set bit. 

for example : 

10 in binary is 00001010 
9 in binary is 00001001 
8 in binary is 00001000 
7 in binary is 00000111 

So if we subtract a number by 1 and do it bitwise & with itself (n & (n-1)), we unset the rightmost set bit. If we do n & (n-1) in a loop and count the number of times the loop executes, we get the set bit count. 

The beauty of this solution is the number of times it loops is equal to the number of set bits in a given integer. 

This is known as Brian Kernighan’s Algorithm

Example
n =  9 (1001)

count = 0

  Since 9 > 0, subtract by 1 and do bitwise & with (9-1)
  n = 9&8  (1001 & 1000)
  n = 8
  count  = 1
Since 8 > 0, subtract by 1 and do bitwise & with (8-1)
  n = 8&7  (1000 & 0111)
  n = 0
  count = 2
Since n = 0, return count which is 2 now.

Implementation

Initialize count: = 0
Do the following while n does not becomes 0.
 Do bitwise & with (n-1) and assign the value back to n
         n: = n&(n-1)
Increment count by 1
Else return count

Complexity
Time Complexity: O(log n), we need not to iterate n times over the binary bits, instead we just keep doing bitwise and and right shift which makes the complexity logn

Auxiliary Space: O(1), no extra space needed

// Function to count the number of set bits in N
class Solution
{
public:
    int setBits(int N)
    {
        int count = 0; // initializing count variable to 0
        while (N)
        {
            N &= (N - 1); // with this operation, we remove the rightmost set bit in N and increment the count
            count++;      // incrementing the count variable by 1
        }
        return count; // returning the final count of set bits in N
    }
};

// The overall time complexity of this function is O(logN), where N is the length of the