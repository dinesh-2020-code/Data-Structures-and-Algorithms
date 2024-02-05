/**
 * Given a sorted circular linked list of length n, the task is to insert a new node
 *  in this circular list so that it remains a sorted circular linked list.
 * 
 * Input: n = 3
 * LinkedList = 1->2->4
 * (the first and last node is connected, i.e. 4 --> 1)
 * data = 2
 * Output:1 2 2 4
 * 
 * Problem Statement: https://www.geeksforgeeks.org/problems/sorted-insert-for-circular-linked-list/1
 * 
*/

#include <iostream>

using namespace std;

struct Node {
    int data; 
    struct Node *next;

    Node(int x) {
        data = x; 
        next = NULL;
    }
};

//Function that inserts data into the circular linked list in sorted order
Node *sortedInsert(Node* head, int data)
{
     //if LL is empty
    if (head == NULL) {
        Node *NEW = new Node(data);
        NEW -> next = NEW;
        return NEW;
    }
    Node *prev = NULL, *curr = head;
    
    while (curr -> data < data) {
        prev = curr; 
        curr = curr -> next;
        
        if (curr == head) //insert as last node
         {
             break; 
         }
        
    }
    
    Node *NEW = new Node(data);
   
    if (prev == NULL) { //insert at beg
       NEW -> next = curr;
       Node *temp = head -> next;
       while (temp -> next != head) {
           temp = temp -> next;
       }
       temp -> next = NEW; 
       return NEW; 
    }
    else {
        NEW -> next = curr; 
        prev -> next = NEW;
    }
       
    return head;
      
}


void printList(struct Node *temp) 
{

    while (temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << "\n";
}

int main() {

    Node *head = new Node(1);
    head -> next = new Node(4);
    head -> next -> next = new Node(7);
    head -> next -> next -> next = new Node(9);
    int data = 0;
    cout << "Original list: \n";
    printList(head);
    head = sortedInsert(head, data);
    cout << "List after insertion: \n";
    printList(head);
}