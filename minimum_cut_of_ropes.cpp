// priority_queue_concept

Example:
Input: arr[] = {4,3,2,6} , N = 4

Output: 29

Explanation:

First, connect ropes of lengths 2 and 3. Now we have three ropes of lengths 4, 6, and 5. 
Now connect ropes of lengths 4 and 5. Now we have two ropes of lengths 6 and 9. 
Finally connect the two ropes and all ropes have connected.

 
Final output = 5+9+15 = 29

Expected Approach:


Intuition


If we observe the above problem closely, we can notice that the lengths of the ropes which are picked first are included more than once in the total cost. Therefore, the idea is to connect the smallest two ropes first and then for the remaining ropes. This approach is similar to Huffman Coding. We put the smallest ropes down the tree so that they can be repeated multiple times rather than the longer ropes. We can achieve this by using the min-heap priority_queue.

Implementation


Create a min-heap priority_queue and insert all lengths into the priority_queue.
Do the following while the size of priority_queue is greater than one. 
Extract the minimum and second minimum from priority_queue which is present at the top of priority_queue.
Add the above two extracted values and insert the added value to the min-heap.
Maintain a variable answer for total cost and keep incrementing it by the sum of extracted values.
Return the value of the answer at the end.


Complexity

Time Complexity: O(N log N), Because heap operations like insert and extract take O(Logn) time in priority_queue and for all n elements it takes n*logn.
Auxiliary Complexity: O(n), The space required to store the values in priority_queue.


class Solution
{
public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n)
    {
        // implementing MinHeap using priority queue.
        priority_queue<long long, vector<long long>, greater<long long>> pq(
            arr, arr + n);

        long long res = 0;

        // using a loop while there is more than one element in priority queue.
        while (pq.size() > 1)
        {
            // storing the first and second numbers from priority queue.
            long long first = pq.top();
            pq.pop();
            long long second = pq.top();
            pq.pop();

            // adding their sum in result.
            res += first + second;

            // pushing the sum of first and second numbers in priority queue.
            pq.push(first + second);
        }
        // returning the result.
        return res;
    }
};

Alternate Approach

Intuition

If we observe the above problem closely, we can notice that the lengths of the ropes which are picked first are included more than once in the total cost. we can achieve this by maintaining the set(multiset because it may be possible that more than one rope has the same size) of all-size ropes

Implementation


Create a multiset and insert all lengths into the multiset since more than one rope may have same size.
Do the following while the size of the multiset is greater than one. 
Extract the minimum and second minimum from the multiset which is present at the beginning of the multiset as we need to minimise the cost so we will first start adding the small lengths.
Add the above two extracted values and insert the added value to the multiset.
Maintain a variable answer for total cost and keep incrementing it by the sum of extracted values.
Return the value of the answer at the end.


Code:
class Solution
{
public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n)
    {
        // Your code here
        multiset<long long> ms;
        for (int i = 0; i < n; i++)
        {
            ms.insert(arr[i]);
        }
        long long ans = 0;
        while (ms.size() > 1)
        {
            auto it = ms.begin();
            long long cost = *it;
            ms.erase(it);
            it = ms.begin();
            cost += *it;
            ms.erase(it);
            ms.insert(cost);
            ans += cost;
        }
        return ans;
    }
};

Complexity
    Time Complexity : O(N logN),
                      Note that multiset operations like insert and erase take O(Logn) time in multiset and for all n elements it takes n*logn.
Auxiliary Complexity: O(N), The space required to store the values in the multiset.