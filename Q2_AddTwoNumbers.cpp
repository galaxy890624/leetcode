#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* dummyHead = new ListNode(0);  // Placeholder for result list
        ListNode* current = dummyHead;  // Pointer to build the result list
        int carry = 0;  // Initialize carry to 0

        // Traverse both lists until both are exhausted
        while (l1 != nullptr || l2 != nullptr)
        {
            int x = (l1 != nullptr) ? l1 -> val : 0;  // Get l1's value (or 0 if null)
            int y = (l2 != nullptr) ? l2 -> val : 0;  // Get l2's value (or 0 if null)
            int sum = carry + x + y;  // Add both values and carry

            carry = sum / 10;  // Update carry for next step
            current -> next = new ListNode(sum % 10);  // Create new node for result digit
            current = current -> next;  // Move current pointer forward

            // Move to the next nodes in l1 and l2
            if (l1 != nullptr) l1 = l1 -> next;
            if (l2 != nullptr) l2 = l2 -> next;
        }

        // If there's a carry left, add a new node
        if (carry > 0)
        {
            current -> next = new ListNode(carry);
        }

        return dummyHead -> next;  // The result starts from dummyHead -> next
    }
};

// Function to create a linked list from an array
ListNode* createLinkedList(const vector<int>& nums)
{
    ListNode* dummyHead = new ListNode(0);
    ListNode* current = dummyHead;
    for (int num : nums)
    {
        current -> next = new ListNode(num);
        current = current -> next;
    }
    return dummyHead -> next;
}

// Function to print a linked list
void printLinkedList(ListNode* head)
{
    while (head != nullptr)
    {
        cout << head -> val;
        if (head -> next != nullptr)
        {
            cout << "  ->  ";
        }
        head = head -> next;
    }
    cout << endl;
}

int main()
{
    Solution Sol;

    // Test case 1: (2  ->  4  ->  3) + (5  ->  6  ->  4) = (7  ->  0  ->  8)
    ListNode* l1 = createLinkedList({2, 4, 3});
    ListNode* l2 = createLinkedList({5, 6, 4});

    cout << "Input List 1: ";
    printLinkedList(l1);
    cout << "Input List 2: ";
    printLinkedList(l2);

    ListNode* result = Sol.addTwoNumbers(l1, l2);

    cout << "Result List: ";
    printLinkedList(result);

    return 0;
}