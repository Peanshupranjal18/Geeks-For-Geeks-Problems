Implementing two stacks in the array 
1 we specify the size of the array according to the constraint mentioned in the question
2 for stack 1 we push and pop from the front and for stack 2 we push and pop from the back of the array

class twoStacks
{
    int *arr;
    int size;
    int top1, top2;

public:
    twoStacks(int n = 100)
    {
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = size;
    }

    // Function to push an integer into the stack1.
    void push1(int x)
    {
        if (top1 == size - 1)
        {
            return;
        }
        top1++;
        arr[top1] = x;
    }

    // Function to push an integer into the stack2.
    void push2(int x)
    {
        if (top2 == 0)
        {
            return;
        }
        top2--;
        arr[top2] = x;
    }

    // Function to remove an element from top of the stack1.
    int pop1()
    {
        if (top1 == -1)
        {
            return -1;
        }
        int popped = arr[top1];
        top1--;
        return popped;
    }

    // Function to remove an element from top of the stack2.
    int pop2()
    {
        if (top2 == size)
        {
            return -1;
        }
        int popped = arr[top2];
        top2++;
        return popped;
    }
};