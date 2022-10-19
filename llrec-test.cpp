#include <iostream>
#include <fstream>
#include <functional>
#include "llrec.h"
using namespace std;


/**
 * Reads integers (separated by whitespace) from a file
 * into a linked list.
 *
 * @param[in] filename
 *  The name of the file containing the data to read
 * @return
 *  Pointer to the linked list (or NULL if empty or the
 *  file is invalid)
 */
Node* readList(const char* filename);

/**
 * Prints the integers in a linked list pointed to
 * by head.
 */
void print(Node* head);

/**
 * Deallocates the linked list nodes
 */
void dealloc(Node* head);


// -----------------------------------------------
//   Add any helper functions or
//   function object struct declarations
// -----------------------------------------------





int main(int argc, char* argv[])
{
    if(argc < 2) {
        cout << "Please provide an input file" << endl;
        return 1;
    }

    // -----------------------------------------------
    // Feel free to update any code below this point
    // -----------------------------------------------
    Node* head = readList(argv[1]);

    cout << "Original list: ";
    print(head);
    Node* smaller;
    Node* larger;
    llpivot(head, smaller, larger, 10);
    cout << "Larger list: ";
    print(larger);
    cout << "Smaller list: ";
    print(smaller);

    cout << "Original List : ";
    print(smaller);
    Node  *filteredData = llfilter(smaller, comparison());
    cout << "Filtered List : ";
    print(filteredData);

    dealloc(head);
    dealloc(smaller);
    dealloc(larger);
    dealloc(filteredData);
    

    

    // Test out your linked list code



    
    
    return 0;

}


Node* readList(const char* filename)
{
    Node* h = NULL;
    ifstream ifile(filename);
    int v;
    if( ! (ifile >> v) ) return h;
    h = new Node(v, NULL);
    Node *t = h;
    while ( ifile >> v ) {
        t->next = new Node(v, NULL);
        t = t->next;
    }
    return h;
}

void print(Node* head)
{
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void dealloc(Node* head)
{
    Node* temp;
    while(head) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

// int main()
// {
//   Node *head = new Node(2,NULL); 
//   Node *evens = NULL; 
//   Node *odds = NULL; 
//   append(*&head, 2); 
//   append(*&head, 3);
//   append(*&head, 7);
//   append(*&head, 13);
//   append(*&head, 12);
//   append(*&head, 17); 
//   split(*&head, *&evens, *&odds); 
//   traverse(*&evens); 
//   traverse(*&odds); 
//   head = odds; 
//   while(head != NULL){
//     Node *temp = NULL; 
//     temp = head;
//     head = head->next;  
//     delete temp; 
//   }
//   head = evens;  
//   while(head != NULL){
//     Node *temp = NULL; 
//     temp = head;
//     head = head->next;  
//     delete temp; 
//   }

//    delete head; 

//    return 0; 
// }
  
