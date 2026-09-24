/*
 * Introduction: Create a linked list with three nodes and verify the data
 * and next pointers of each node.
 */

#include <iostream>
#include <cstddef>

struct ListNode {
    int data;
    ListNode* next;

    explicit ListNode(int val) : data(val), next(nullptr) {}
};

ListNode* head = nullptr;
ListNode* tail = nullptr;

int main() {
    ListNode* one = new ListNode(1);
    ListNode* two = new ListNode(2);
    ListNode* three = new ListNode(3);

    head = one;
    one->next = two;
    two->next = three;
    tail = three;

    // Output: 1 1 2 3 3
    std::cout << head->data << " " << one->data << " " << two->data << " "
              << three->data << " " << tail->data << "\n";

    // Output: 2 2 3 0 (nullptr printed as 0)
    std::cout << head->next->data << " " << one->next->data << " "
              << two->next->data << " " << three->next << "\n";

    /*
     * Traversing: Get the sum of all values from an integer linked list
     */
    int ans = 0;
    ListNode* curr = head;
    while (curr) {
        ans += curr->data;
        curr = curr->next;
    }
    std::cout << ans << "\n";  // Output: 6

    /*
     * Insertion: Adding element at the start of linked list
     */
    auto add_node_start = [](int val) {
        ListNode* new_node = new ListNode(val);
        new_node->next = head;
        head = new_node;
    };

    add_node_start(8);
    // Output: 8 1 2 3 0
    std::cout << head->data << " " << head->next->data << " "
              << one->next->data << " " << two->next->data << " "
              << three->next << "\n";

    /*
     * Insertion: Adding element after a node in linked list
     */
    auto add_node_after = [](ListNode* prev_node, int val) {
        ListNode* new_node = new ListNode(val);
        new_node->next = prev_node->next;
        prev_node->next = new_node;
    };

    add_node_after(two, 10);
    // Note: head was reset conceptually in the Python demo between sections;
    // here we keep the list as-is after prior inserts.
    // After start-insert of 8 and insert-after of 10: 8 -> 1 -> 2 -> 10 -> 3
    std::cout << head->data << " " << one->next->data << " "
              << two->next->data << " " << three->next << "\n";

    /*
     * Insertion: Adding element at the end of linked list
     */
    auto add_elem_end = [](int val) {
        ListNode* new_node = new ListNode(val);
        if (!head) {
            head = new_node;
            return;
        }
        ListNode* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_node;
    };

    add_elem_end(12);
    std::cout << head->data << " " << one->next->data << " "
              << two->next->data << " " << three->next->data << "\n";

    /*
     * Search: Search if element is in the linked list or not
     */
    auto search_elem = [](int val) -> bool {
        ListNode* current = head;
        while (current) {
            std::cout << current->data << "\n";
            if (current->data == val) {
                return true;
            }
            current = current->next;
        }
        return false;
    };

    std::cout << std::boolalpha << search_elem(12) << "\n";

    /*
     * Find Length of a Linked List
     */
    auto find_length_of_ll = []() -> int {
        int length = 0;
        ListNode* current = head;
        while (current) {
            length++;
            current = current->next;
        }
        return length;
    };

    std::cout << find_length_of_ll() << "\n";

    // Free allocated nodes
    while (head) {
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
    }
    tail = nullptr;

    return 0;
}
