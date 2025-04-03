#ifndef PQUEUE_H
#define PQUEUE_H

#include "cust.h"

class PQueue
{
private:
  class Node
  {
  private:
    Cust *cust;
    Node *next;

    int priority;

  public:
    Node(Cust *cust, Node *next, int priority)
    {
      this->cust = cust;
      this->next = next;

      this->priority = priority;
    }

    Cust *getData() { return this->cust; }

    void setData(Cust *cust) { this->cust = cust; }

    Node *getNext() { return this->next; }
    void setNext(Node *next) { this->next = next; }

    int getPriority() { return this->priority; }
    void setPriority(int priority) { this->priority = priority; }
  };

  Node *head;

  int size;

public:
  PQueue()
  {
    head = nullptr;
    size = 0;
  }

  void enqueue(Cust *cust, int priority);

  bool dequeue(Cust *&cust);

  bool isEmpty() { return this->size == 0; }

  bool getFirstPriority(int &priority);
  int getSize() { return this->size; }

  void print(ostream &os);
  // destructor
  ~PQueue();
};

#endif
