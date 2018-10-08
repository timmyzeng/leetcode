/*
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order and each of their nodes contain a single digit.
Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 超级简洁的代码，厉害了
class Solution1 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int integer = 0;        //十位
        ListNode head(0), *cur = &head;
        while(l1 || l2 || integer){
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + integer;
            cur->next = new ListNode(sum % 10);
            integer = sum / 10;
            l1 ? l1 = l1->next : l1;
            l2 ? l2 = l2->next : l2;
            cur = cur->next;
        }
        return head.next;
    }
};

// 这一段代码的作用？
// 让整个代码的执行效率提高了很多
static auto x = [](){
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(NULL);
    return 0;
}();

class Solution2 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {      
        int val1 = 0, val2 = 0, sum = 0, carry = 0;
        ListNode* result = new ListNode(0);
        ListNode* prev = result;
        
        while((l1 != NULL) || (l2 != NULL))
        {
            val1 = (NULL == l1) ? 0 : l1->val;
            val2 = (NULL == l2) ? 0 : l2->val;
            sum = val1 + val2 + carry;
            carry = 0;
            if(sum >= 10)
            {
                carry = 1;
                sum = sum % 10;
            }
            
            ListNode* temp = new ListNode(sum);
            prev->next = temp;
            prev = temp;
            
            l1 = (NULL == l1) ? NULL : l1->next;
            l2 = (NULL == l2) ? NULL : l2->next;
        }
        
        if(1 == carry)
        {
            ListNode* temp = new ListNode(carry);
            prev->next = temp;
        }
        
        ListNode* head = result->next;
        delete(result);
        
        return head;
    }
};