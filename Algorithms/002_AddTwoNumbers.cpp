#include <iostream>

/**
 * Definition for singly-linked list.
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    ListNode dummy;
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l1_current = l1; 
        ListNode* l2_current = l2;
        int l1_value = 0;
        int l2_value = 0;
        dummy = ListNode();
        ListNode* tail = &dummy;
        bool shouldContinue = true;
        int carry = 0;
        int sum;
        while (1){
            sum = 0;
            if (l1_current == nullptr && l2_current == nullptr){
                if (carry == 1){
                    tail->next = new ListNode(carry);
                    tail = tail->next;
                }
                break;
            }

            (l1_current == nullptr) ? l1_value = 0 : l1_value = l1_current->val;
            (l2_current == nullptr) ? l2_value = 0 : l2_value = l2_current->val;
            
            sum = l1_value + l2_value + carry;
            carry = 0;

            if (sum >= 10){
                sum -= 10;
                carry = 1;
            }
            tail->next = new ListNode(sum);
            tail = tail->next;

            if (l1_current != nullptr) l1_current = l1_current->next;
            if (l2_current != nullptr) l2_current = l2_current->next;
            
        }
        return dummy.next;
    }
};

ListNode* makeList(std::vector<int> vals) {
    ListNode dummy;
    ListNode* tail = &dummy;

    for (int v : vals) {
        tail->next = new ListNode(v);
        tail = tail->next;
    }

    return dummy.next;
}

std::string listNodeToString(ListNode* listNode){
    ListNode current = *(listNode);
    std::string str = "[ ";
    while(1){
        str += std::to_string(current.val) + " ";
        if (current.next == nullptr){
            break;
        }
        current = *(current.next);
    }
    str += "]";
    return str;
}

int main() {
    {
        ListNode* case1a = makeList(std::vector<int>{2,4,3});
        ListNode* case1b = makeList(std::vector<int>{5,6,4});
        ListNode* case1c = Solution().addTwoNumbers(case1a, case1b);
        std::cout << listNodeToString(case1a) << " + " << listNodeToString(case1b) << " = " << listNodeToString(case1c) << "\n";
    }
    {
        ListNode* case1a = makeList(std::vector<int>{0});
        ListNode* case1b = makeList(std::vector<int>{0});
        ListNode* case1c = Solution().addTwoNumbers(case1a, case1b);
        std::cout << listNodeToString(case1a) << " + " << listNodeToString(case1b) << " = " << listNodeToString(case1c) << "\n";
    }
    {
        ListNode* case1a = makeList(std::vector<int>{9,9,9,9,9,9,9});
        ListNode* case1b = makeList(std::vector<int>{9,9,9,9});
        ListNode* case1c = Solution().addTwoNumbers(case1a, case1b);
        std::cout << listNodeToString(case1a) << " + " << listNodeToString(case1b) << " = " << listNodeToString(case1c) << "\n";
    }
    return 0;
}