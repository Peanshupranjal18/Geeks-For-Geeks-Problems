Using two stacks to implement queue operations
    push : O(1)
               pop : O(n)

                         void StackQueue::push(int x)
{
    s1.push(x);
}

// Function to pop an element from the queue
int StackQueue::pop()
{
    if (s1.empty() && s2.empty())
    {
        // Both stacks are empty, the queue is empty
        return -1;
    }

    if (s2.empty())
    {
        // Transfer elements from s1 to s2 if s2 is empty
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }

    // Now, s2 has the reversed order of elements, pop from s2
    int res = s2.top();
    s2.pop();
    return res;
}
