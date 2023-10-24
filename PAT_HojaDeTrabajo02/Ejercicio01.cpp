#include "Ejercicio01.h"

template<typename T>
int getLength(Node<T>* head) {
    int length = 0;
    while (head) {
        length++;
        head = head->next;
    }
    return length;
}

Node<char>* Ejercicio01::rotateRight(Node<char>* head, int k) {
    if (!head || k <= 0) return head;

    int length = getLength(head);
    k %= length;

    if (k == 0) return head;  // No rotations to be made

    Node<char>* fast = head;
    Node<char>* slow = head;

    for (int i = 0; i < k; i++) {
        fast = fast->next;
    }

    while (fast->next) {
        fast = fast->next;
        slow = slow->next;
    }

    Node<char>* newHead = slow->next;
    slow->next = nullptr;
    fast->next = head;

    return newHead;
}
