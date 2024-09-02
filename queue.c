#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#include <limits.h>

struct Element {
    int data;
    struct Element* link;
};

typedef struct Element Element;

Element* front = NULL;
Element* rear = NULL;
int count = 0;

bool isQueueEmpty() {
    return count == 0;
}

void enqueue(int data) {
    Element* oldRear = rear;
    rear = (Element*) malloc(sizeof(Element));
    rear->data = data;
    rear->link = NULL;
    if(isQueueEmpty()) front = rear;
    else oldRear->link = rear;
    count++;
}

int dequeue() {
    if(isQueueEmpty()) return INT_MIN;
    int data = front->data;
    Element* temp = front;
    front = front->link;
    if(isQueueEmpty()) rear = NULL;
    count--;
    free(temp);
    return data;
}

int queueSize() {
    return count;
}

void verifyQueue() {
    enqueue(3);
    enqueue(10);
    enqueue(20);
    assert(isQueueEmpty() == false);
    assert(queueSize() == 3);
    assert(dequeue() == 3);
    assert(queueSize() == 2);
    assert(dequeue() == 10);
    assert(queueSize() == 1);
    assert(dequeue() == 20);
    assert(queueSize() == 0);
    assert(isQueueEmpty());
}

int main() {
    verifyQueue();
    printf("All verifications passed successfully!\n");
    return 0;
}