#include <stdlib.h>
#include <stdio.h>

/* NAME: Node
 * PURPOSE: struct for the node of a linkedlist
 * IMPORTS: void pointer to generic data to be stored
 * ASSERTIONS: Linked list has been created 
 */
typedef struct LinkedListNode
{
    void* data;
    struct LinkedListNode* next;
    struct LinkedListNode* prev; 

} Node;

/* NAME: LinkedList
 * PURPOSE: create a linkedlist data structure
 */
typedef struct LinkedList
{
    Node* HEAD;
    Node* TAIL;

}LinkedList;

/* NAME: createLinkedList
 * PURPOSE: initalise the linkedlist 
 * IMPORTS: NONE
 * EXPORTS: list
 * ASSERTIONS: linkedlist is currently not initalised
 */
LinkedList* createLinkedList(){
    LinkedList* list;
    list = (LinkedList*)malloc(sizeof(LinkedList));
    list->HEAD= NULL;
    return list;
}

/* NAME: insertStart
 * PURPOSE:inserts an element at the start of the linkedlist
 * IMPORTS: data generic data to be stored in the node, list linkedlist to store the created node
 * EXPORTS: NONE
 * ASSERTIONS: list has been initalised
 */
void insertStart(void* data,LinkedList* list){
    Node* newNode;
    newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = list->HEAD;
    newNode->prev = NULL;
    if(list->HEAD!= NULL)
    {
        list->HEAD->prev = newNode;
    }
    else
    {
        list->TAIL = newNode;
    }

    list->HEAD = newNode;
}

/* NAME: insertEnd
 * PURPOSE: inserts an element at the end of the linkedlist
 * IMPORTS: data generic data to be stored in the node, list linkedlist to store the created node
 * EXPORTS: NONE
 * ASSERTIONS: list has been initalised
 */
void insertEnd(void* data,LinkedList* list){
    Node* newNode;
    newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = list->TAIL;
    newNode->next = NULL;
    if(list->TAIL != NULL)
    {
        list->TAIL->next = newNode;
    }
    else
    {
        list->HEAD = newNode;
    }
    
    list->TAIL = newNode;
}

/* NAME: linkedlistLength
 * PURPOSE: gets the length of the linkedlist
 * IMPORTS: list the linkedlist
 * EXPORTS: lenght an int for the length of the linkedlist
 * ASSERTIONS: list has been initalised
 * ! Not used
 */
int linkedlistLength(LinkedList* list){
    int length = 0;
    Node* current = list->HEAD;

    while (current != NULL)
    {
        length++;
        current = current->next;
    }
    return length;
}

/* NAME: isEmpty
 * PURPOSE: checks if the linkedlist is empty
 * IMPORTS: list the linkedlist
 * EXPORTS: 1 or 0
 * ASSERTIONS: list has been initalised
 * I dont think this really works that well
 */
int isEmpty(LinkedList* list){
    return(list == NULL || (list->HEAD == NULL && list->TAIL == NULL));
}

/* NAME: deleteLastNode
 * PURPOSE: remove last node of the linkedlist
 * IMPORTS: list the linkedlist
 * EXPORTS: NONE
 * ASSERTIONS: list has been initalised and is not empty
 */
void deleteLastNode(LinkedList* list){
    if(isEmpty(list)== 0){
        Node* temp;
        temp = list->TAIL;    
        if(temp->prev != NULL){
            list->TAIL = temp->prev;
            list->TAIL->next = NULL;
        }else{
            list->HEAD =NULL;
            list->TAIL = NULL;
        }
        if(temp->data != NULL){
            free(temp->data);
        }
        free(temp);
    } 
}

/* NAME: deleteEntireList
 * PURPOSE: calls the deletaLastNode func until the list is empty
 * IMPORTS: list the linkedlist
 * EXPORTS: NONE
 * ASSERTIONS: list has been initalised
 */
void deleteEntireList(LinkedList* list){
    while (isEmpty(list)==0)
    {
        deleteLastNode(list);
    }
    free(list);
    
}

/* NAME: printList
 * PURPOSE: prints the linkedlist contents
 * IMPORTS: list the linkedlist
 * EXPORTS: NONE
 * ASSERTIONS: the list has been initalised and is not empty
 */
void printList(LinkedList* list){
    Node* current = list->HEAD;
    while (current != NULL) {
        int* retrievedData = (int*)current->data;
        printf("Data: %d %d %d\n", retrievedData[0], retrievedData[1], retrievedData[2]);
        current = current->next;
    }
}
