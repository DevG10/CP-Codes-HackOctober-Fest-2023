#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseLinkedList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* nextNode = nullptr;

    // Iterate through the list and reverse the pointers
    while (curr != nullptr) {
        nextNode = curr->next;  // Store the next node
        curr->next = prev;       // Reverse the current node's pointer
        prev = curr;             // Move the prev pointer forward
        curr = nextNode;         // Move the current pointer forward
    }

    return prev;  // Return the new head of the reversed list
}

ListNode* rotateRight(ListNode* head, int k) {
    if (head == nullptr || k == 0) {
        return head;
    }

    // Find the length of the linked list
    int length = 1;
    ListNode* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
        length++;
    }

    // Adjust rotation value to avoid unnecessary rotations
    k = k % length;

    // If rotation value is 0, the list remains unchanged
    if (k == 0) {
        return head;
    }

    // Find the new tail and break the list into two parts
    int newTailIndex = length - k - 1;
    ListNode* newTail = head;
    for (int i = 0; i < newTailIndex; ++i) {
        newTail = newTail->next;
    }

    // Rotate the list
    ListNode* newHead = newTail->next;
    newTail->next = nullptr;
    tail->next = head;

    // Reverse the rotated list
    newHead = reverseLinkedList(newHead);

    return newHead;
}

// Function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;

    std::cout << "Original List: ";
    printList(head);

    ListNode* rotatedHead = rotateRight(head, k);

    std::cout << "Rotated and Reversed List: ";
    printList(rotatedHead);

    return 0;
}
