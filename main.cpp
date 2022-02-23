/* *************************************************************
 * Building a simple linked list manually for demonstration.
 *
 * Note that this is a toy example and does not use proper file and header structure.
 * This is strictly for demonstrating the manual creation of a linked list to accompany
 * an introduction to linked list lecture.
 * **************************************************************/

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

// this is the Node "payload", i.e. it's the "data"
struct Data {
    int id;
    string data;
};

// this is the actual node with it's header (the pointers) and it's payload (Data)
struct Node{
    Node *prev;
    Node *next;
    Data data;
};

int main(){
    
    Node *head = NULL; // pointer to a Node but pointing at "nothing" for now

    // creates a Node dynamically
    Node *node1;
    node1 = new Node;

    // creates a Node dynamically
    Node *node2; 
    node2 = new Node;

    // creates a Node dynamically
    Node *node3;
    node3 = new Node;
    
    
    node1->data.id = 1; // put data in node1
    node1->data.data = "Hello"; // put data in node1

    node2->data.id = 2; // put data in node2
    node2->data.data = "World"; // put data in node2

    node3->data.id = 3; // put data in node3
    node3->data.data = "Linked Lists are awesome!"; // put data in node3
    
    // build a linked list (of size 3) out of the nodes made above
    head = node1;         // first point the head at node1
    node1->prev = NULL;   // point node1 prev to NULL because there is no previous
    node1->next = node2;  // point node1 next to node2
    node2->prev = node1;  // point node2 back to node1
    node2->next = node3;  // point node2 next to node3
    node3->prev = node2;  // point node3 back to node2
    node3->next = NULL;   // point node3 next to NULL because there is no next
    
    // prove it's a linked list, traverse it forward
    Node *current = head; // start a "tracking" pointer by pointing it head
    while(current){       // as long as we're not at the end, keep going
        cout << current->data.id << ": " << current->data.data << endl;
        current = current->next; // go to the next node
    }
    cout << endl;
    
    // prove it's a linked list, traverse it backward
    // but first you have to find the tail
    current = head; // start a "tracking" pointer by pointing it head
    bool tail = false; // we're not at the tail yet
    while(current && !tail){ // find the tail
        if (current->next){
            current = current->next;
        } else {
            tail = true; // found the tail
        }
    }
    // now traverse it backward
    while(current){
       cout << current->data.id << ": " << current->data.data << endl;
       current = current->prev;
    }

    return 0;
}
