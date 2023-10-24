#include "Ejercicio02.h"

Node<int>* Ejercicio02::addTwoNumbers(Node<int>* l1, Node<int>* l2) {
    Node<int>* dummyHead = new Node<int>{ 0, nullptr };  // Nodo ficticio para simplificar el c�digo.
    Node<int>* current = dummyHead;
    int carry = 0;  // Acarreo

    while (l1 != nullptr || l2 != nullptr) {
        int sum = carry;

        if (l1 != nullptr) {
            sum += l1->value;
            l1 = l1->next;
        }

        if (l2 != nullptr) {
            sum += l2->value;
            l2 = l2->next;
        }

        carry = sum / 10; // Divide por 10 para obtener el acarreo
        current->next = new Node<int>{ sum % 10, nullptr };  // El resto al dividir por 10 da el d�gito actual
        current = current->next;
    }

    // Si a�n hay acarreo despu�s de haber recorrido ambas listas
    if (carry > 0) {
        current->next = new Node<int>{ carry, nullptr };
    }

    Node<int>* result = dummyHead->next;
    delete dummyHead;
    return result;
}

