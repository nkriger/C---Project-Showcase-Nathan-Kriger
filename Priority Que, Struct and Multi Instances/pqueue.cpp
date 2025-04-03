
#include <iostream>
#include "cust.h"
#include "pqueue.h"

using namespace std;

void PQueue::enqueue(Cust* cust, int priority) {
  Node* new_node = new Node(cust, nullptr, priority);
  
  if (head == nullptr || priority < head->getPriority()) {
    new_node->setNext(head);
    head = new_node;
  } else {
    
    Node* current = head;
    while (current->getNext() != nullptr && priority >= current->getNext()->getPriority()) {
      current = current->getNext();
    }
    new_node->setNext(current->getNext());
    current->setNext(new_node);
  }
  ++size;
}

bool PQueue::dequeue(Cust* &cust_out) {
  if (size == 0) {
    return false;
  }
  
  Node* temp = head;
  cust_out = temp->getData();
  head = head->getNext();

  delete temp;
  
  --size;
  return true;
}

bool PQueue::getFirstPriority(int &priority_out) {
  if (size == 0) {
    return false;
  }
  priority_out = head->getPriority();
  return true;
}

void PQueue::print(ostream &os) {
  Node* current = head;
  while (current != nullptr) {
    current->getData()->print(os);
    current = current->getNext();
  }
}

PQueue::~PQueue() {
  while (head != nullptr) {
    Node* temp = head;
    head = head->getNext();
    delete temp->getData();
    delete temp;
  }
}