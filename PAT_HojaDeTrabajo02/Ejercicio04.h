#pragma once
#include <vector>

class FrontMiddleBackQueue {
private:
    std::vector<int> queue;

public:
    FrontMiddleBackQueue();

    void pushFront(int value);

    void pushMiddle(int value);

    void pushBack(int value);

    int popFront();

    int popMiddle();

    int popBack();
};
