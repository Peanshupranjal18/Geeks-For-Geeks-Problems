Given an array of size n and a range [a, b]. The task is to partition the array around the range such that array is divided into three parts.
1) All elements smaller than a come first.
2) All elements in range a to b come next.
3) All elements greater than b appear in the end.
The individual elements of three sets can appear in any order. You are required to return the modified array.

Note: The generated output is 1 if you modify the given array successfully.


//Back-end complete function Template for C

class Solution
{
public:
    // Function to partition the array around the range such
    // that array is divided into three parts.
    void threeWayPartition(vector<int> &array, int a, int b)
    {
        int n = array.size();
        // Using two pointers which help in finding the index with which
        // the elements need to be swapped if they are not in correct position.
        int start = 0, end = n - 1;

        for (int i = 0; i <= end;)
        {
            // If current element is smaller than lower range, we swap
            // it with value on next available smallest position.
            if (array[i] < a)
                swap(array[i++], array[start++]);

            // If current element is greater than higher range, we swap
            // it with value on next available greatest position.
            else if (array[i] > b)
                swap(array[i], array[end--]);

            // Else we just move ahead in the array.
            else
                i++;
        }
    }
};