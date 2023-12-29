In the question we have been given that the Nodes in two of the given linked list is sorted

My approach for the problem considering two vector to store the nodes


class Solution
{
public:
    Node *findIntersection(Node *head1, Node *head2)
    {

        vector<int> v1;
        vector<int> v2;

        for (Node *curr = head1; curr != nullptr; curr = curr->next)
            v1.push_back(curr->data);

        for (Node *curr = head2; curr != nullptr; curr = curr->next)
            v2.push_back(curr->data);

        vector<int> v3;

        set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v3));

        Node *resultHead = nullptr;
        Node *current = nullptr;

        for (int value : v3)
        {
            Node *newNode = new Node(value);

            if (resultHead == nullptr)
            {
                resultHead = newNode;
                current = newNode;
            }
            else
            {
                current->next = newNode;
                current = newNode;
            }
        }

        return resultHead;
    }
};

important derivations from the above code

    1. set_intersection concept set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v3));

2. creating a new linked list from the given vector

    Node *resultHead = nullptr;
Node *current = nullptr;

for (int value : v3)
{
    Node *newNode = new Node(value);

    if (resultHead == nullptr)
    {
        resultHead = newNode;
        current = newNode;
    }
    else
    {
        current->next = newNode;
        current = newNode;
    }
}

Required approach for the problem 

class Solution
{
public:
    Node *findIntersection(Node *head1, Node *head2)
    {
        Node *p1 = head1, *p2 = head2;
        Node *head = NULL, *tail = NULL;

        while (p1 && p2)
            if (p1->data > p2->data)
                // nodes dont match
                // moving to next node in list with smaller node
                p2 = p2->next;

            else if (p2->data > p1->data)
                // nodes dont match
                // moving to next node in list with smaller node
                p1 = p1->next;

            else
            {
                // nodes match

                if (head == NULL)
                    head = tail = new Node(p1->data);
                // creating new head for intersection list
                else
                {
                    // appending new node at the end
                    tail->next = new Node(p1->data);
                    tail = tail->next;
                }
                p1 = p1->next;
                p2 = p2->next;
                // moving to next nodes in both lists
            }

        return head;
    }
};

Using Hashmap to find Intersection points 

-> We need to increment and then check for the other Node if the value in the map is already greater than 0 then it is a common element we can use unordered map as the Nodes given are already sorted set can also be used here
#include <unordered_map>

class Node
{
public:
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

class Solution
{
public:
    static Node *findIntersection(Node *tmp1, Node *tmp2)
    {
        Node *result = new Node(0);
        Node *curr = result;

        std::unordered_map<int, int> set;

        while (tmp1 != nullptr)
        {
            set[tmp1->data] = set[tmp1->data] + 1;
            tmp1 = tmp1->next;
        }

        while (tmp2 != nullptr)
        {
            if (set.find(tmp2->data) != set.end() && set[tmp2->data] > 0)
            {
                set[tmp2->data] = set[tmp2->data] - 1;
                if (set[tmp2->data] == 0)
                {
                    set.erase(tmp2->data);
                }

                curr->next = new Node(tmp2->data);
                curr = curr->next;
            }

            tmp2 = tmp2->next;
        }

        result = result->next;
        return result;
    }
};
