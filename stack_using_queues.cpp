Using two queues to implement stack operations

    void
    QueueStack ::push(int x)
{
    // Your Code
    q1.push(x);
    while (!q2.empty())
    {
        q1.push(q2.front());
        q2.pop();
    }
    swap(q1, q2);
}

// Function to pop an element from stack using two queues.
int QueueStack ::pop()
{
    // Your Code
    int y = -1;
    if (!q2.empty())
        y = q2.front();
    if (y != -1)
        q2.pop();
    return y;
}

Explanation for expected approach

// push operation


//Function to push an element into stack using two queues.
void QueueStack ::push(int num)
{

    // while first queue is not empty, we keep popping the front element
    // from first queue and storing that element in second queue.
    while (!q1.empty())
    {
        int k = q1.front();

        // popping element from first queue.
        q1.pop();

        // pushing it into second queue.
        q2.push(k);
    }

    // q1 is empty now and we push the given number into first queue.
    q1.push(num);

    // while second queue is not empty, we keep popping the front element
    // from second queue and storing that element in first queue.
    while (!q2.empty())
    {
        int k = q2.front();
        // popping element from second queue.
        q2.pop();

        // pushing it into first queue.
        q1.push(k);
    }
}
// Function to pop an element from stack using two queues.
int QueueStack ::pop()
{

    // if first queue is not empty, then we can pop an element.
    if (!q1.empty())
    {
        // we store the front element from the queue in a
        // variable and pop that element.
        int r = q1.front();
        q1.pop();

        // returning the popped element.
        return r;
    }
    // else we return -1.
    return -1;
}