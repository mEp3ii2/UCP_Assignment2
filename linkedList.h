#ifndef LINKEDLIST_H
#define LINKEDLIST_H
typedef struct LinkedListNode
{
    void* data;
    struct LinkedListNode* next;
    struct LinkedListNode* prev;

}Node;

typedef struct LinkedList
{
    Node* HEAD;
    Node* TAIL;
}LinkedList;

LinkedList* createLinkedList();
void insertStart(void* data, LinkedList* list);
void insertEnd(void* data, LinkedList* list);
int linkedlistLength(LinkedList* list);
int isEmpty(LinkedList* list);
void deleteLastNode(LinkedList* list);
void deleteEntireList(LinkedList* list);
void printList(LinkedList* list);

#endif