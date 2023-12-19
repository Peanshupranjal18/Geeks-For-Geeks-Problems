Product Except Self without using division operation

    Expected Approach :

    Intution :

    In the above approach,
    two extra arrays were created to store the prefix and suffix,
    in this solution store the prefix and suffix product in the output array(i.e.array vec) itself.Thus reducing the space required.

    Implementation :

    Create an array vec and initialize its value to 1 and a variable temp = 1. If n is equal to 1,
                                                                     then return the array vec.Traverse the array from start to end.For every index i update vec[i] as vec[i] = temp and temp = temp * nums[i],
                                                                     i.e store the product upto i - 1 index from the start of array.Initialize temp = 1 and traverse the array from last index to start.For every index i update vec[i] as vec[i] = vec[i] *temp and temp = temp * nums[i],
                                                                     i.e multiply with the product upto i + 1 index from the end of array.Return the product array.

                                                                                                            Code :

    class Solution
{
public:
    vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
    {
        // Allocate memory for product array andinitialise it by 1
        vector<long long int> vec(n, 1ll);
        if (n == 1)
        {
            return vec;
        }

        // In this loop temp will store the product of values on the left side of nums[i]
        long long temp = 1ll;
        for (int i = 0; i < n; i++)
        {
            vec[i] *= temp;
            temp *= nums[i];
        }

        // In this loop temp will store the product of values on the right side of nums[i]
        temp = 1ll;
        for (int i = n - 1; i >= 0; i--)
        {
            vec[i] *= temp;
            temp *= nums[i];
        }

        return vec; // return the expected vector
    }
};

Complexity:
Time Complexity: O(n), The original array needs to be traversed only once, so the time complexity is constant.
Space Complexity: O(n), Even though the extra arrays are removed, the space complexity remains O(n), as the product array is still needed.




Alternate Approach:

Intution:
The idea in this is to store the product of all the elements is a variable and then iterate the array and replace ith element of the array with product/current_index_value in a array. and then return this array.

Implementation:


Initialize the variables prod equal to 1 to store the product of all the elements in the array and flag equal to 0 to store the count of number of zeros in the array.
Run a loop from start to end of the array.
If the value at the index is equal to 0 increase the flag by 1 else multiply the value at the index with the prod variable.
Run a loop from start to end of the array.
If there are more than one zero elements, set the value in the nums array at that index equal to 0, since multiplying by 0 will result in 0.
If there are no zero elements, divide the total product by the current element value and assign it to the corresponding index in the result array.
If there is exactly one zero element and the current element is non-zero, set the result array element to 0 (since their would be one element that will be equal to 0).
For all other cases (when there's one zero element and the current element is zero), set the result array element to the total product(as we are not considering that element).
Return the modified nums array as that would be our answer.


Code:
class Solution {
public:
    vector<long long int>
    productExceptSelf(vector<long long int>& nums, int n)
    {
        long long prod = 1;
        long long flag = 0;

        // product of all elements
        for (int i = 0; i < n; i++) {
    // counting number of elements which have value
    // 0
    if (nums[i] == 0)
        flag++;
    else
        prod *= nums[i];
        }

        for (int i = 0; i < n; i++) {
    if (flag > 1)
        nums[i] = 0;

    else if (flag == 0)
        nums[i] = (prod / nums[i]);

    else if (flag == 1 && nums[i] != 0)
        nums[i] = 0;

    // if(flag == 1 && nums[i] == 0)
    else
        nums[i] = prod;
        }
        return nums;
}
}
;