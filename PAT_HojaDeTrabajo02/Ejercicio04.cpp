#include "Ejercicio04.h"
#include <iostream>

FrontMiddleBackQueue::FrontMiddleBackQueue() {}

void FrontMiddleBackQueue::pushFront(int value) {
    queue.insert(queue.begin(), value);
}

void FrontMiddleBackQueue::pushMiddle(int value) {
    int middleIndex = queue.size() / 2;
    queue.insert(queue.begin() + middleIndex, value);
}

void FrontMiddleBackQueue::pushBack(int value) {
    queue.push_back(value);
}

int FrontMiddleBackQueue::popFront() {
    if (queue.empty())
        return -1;

    int value = queue.front();
    queue.erase(queue.begin());
    return value;
}

int FrontMiddleBackQueue::popMiddle() {
    if (queue.empty())
        return -1;

    int middleIndex;
    // Si la cantidad es par, debemos quitar el elemento anterior al medio
    if (queue.size() % 2 == 0) {
        middleIndex = queue.size() / 2 - 1;
    }
    else {
        middleIndex = queue.size() / 2;
    }

    int value = queue[middleIndex];
    queue.erase(queue.begin() + middleIndex);
    return value;
}

int FrontMiddleBackQueue::popBack() {
    if (queue.empty())
        return -1;

    int value = queue.back();
    queue.pop_back();
    return value;
}
