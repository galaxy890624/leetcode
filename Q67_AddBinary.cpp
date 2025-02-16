#include <iostream>
#include <cstdlib>
#include <stack>

using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        stack<int> stack_a, stack_b, result_stack;
        string result = "";
        
        // Push all characters of 'a' and 'b' into stacks
        for (char ch : a)
        {
            stack_a.push(ch - '0');
        }
        for (char ch : b)
        {
            stack_b.push(ch - '0');
        }

        int carry = 0;

        // Process both stacks until they are empty
        while (!stack_a.empty() || !stack_b.empty() || carry) {
            int sum = carry;
            
            if (!stack_a.empty())
            {
                sum += stack_a.top();
                stack_a.pop();
            }
            
            if (!stack_b.empty())
            {
                sum += stack_b.top();
                stack_b.pop();
            }

            // Push sum % 2 to result stack (binary digit)
            result_stack.push(sum % 2);
            
            // Update carry
            carry = sum / 2;
        }

        // Pop from result stack to form the final binary sum
        while (!result_stack.empty())
        {
            result += (result_stack.top() + '0'); // Convert int to char
            result_stack.pop();
        }

        return result;
    }
};

int main()
{
    Solution Sol;
    string a = "10110";
    string b = "101";
    
    string AddBinary = Sol.addBinary(a, b);
    cout << "Sum: " << AddBinary << endl; // Expected output: "11011"
    return 0;
}