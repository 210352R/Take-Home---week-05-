#include <iostream>
using namespace std;

// Node structure (create Node) ---
struct Node{
    int data;
    struct Node* next;
};

//Head pointer ---
struct Node* head = NULL;

bool isExists(int value);

//insert value to start --
void insert(int new_data) {
   struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
   new_node->data = new_data;
   if(head==NULL){
    head = new_node;
    head->next = NULL;
   }else{
       new_node->next = head;
       head = new_node;
   }

}


// Add value to a end of linked list --
void addEnd(int data){
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    if(head==nullptr){
        head = new_node;
        head->next = NULL;
    }else{
        struct Node* ptr;
        ptr = head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = new_node;

    }
}

// Pop value from begining ---
void pop(){
    if(head!=NULL){
        struct Node* ptr;
        ptr = head;
        head = ptr->next;
        free(ptr);
    }
}

// remove value from the end of the linked list ----
void removesAtEnd(){
    if(head != NULL){
        struct Node* ptr;
        ptr = head;
        while(ptr->next->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = NULL;
    }

}
// remove given value from linked list
void removes(int value){
    if(isExists(value)){
        struct Node* ptr;
        ptr = head;
        if(ptr->data == value){
            pop();
        }else{
            while(ptr != NULL && ptr->next->data != value ){
                ptr = ptr->next;
            }
            ptr->next = ptr->next->next;
        }
    }else{
        cout<<"Invalid Value"<<endl;
    }
}

// add given value to given index --
void addAt(int index,int data){
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    struct Node* ptr;
    ptr = head;
    for(int i=0;i<(index-1);i++){
        ptr = ptr->next;
    }
    new_node->next = ptr->next;
    ptr->next = new_node;
}


// display (print) linkedList --
void display() {
   struct Node* ptr;
   ptr = head;
   while (ptr != NULL) {
      cout<< ptr->data <<" ";
      ptr = ptr->next;
   }
   cout<<endl;
}

// Check whether given value exists or not  --
bool isExists(int value){
    struct Node* ptr = head;
    while(ptr != NULL  ){
        if(ptr->data == value){
            return true;
        }
        ptr = ptr->next;
    }
    return false;
}


int main(){
   insert(3);
   insert(1);
   insert(7);
   insert(2);
   insert(9);
   cout<<"The linked list is: ";
   display();
   cout<<endl;

   addEnd(50);
   addEnd(64);
   addEnd(80);

   //removesAtEnd();

   pop();
   pop();

   cout<<"The linked list is: ";
   display();
    cout<<endl;

   addAt(1,256);
   addAt(4,666);

   cout<<"The linked list is: ";
   display();
    cout<<endl;

   cout<<"Check Existance of a value : "<<isExists(10)<<endl;

   removes(7);
   removes(666);
   removesAtEnd();
   cout<<"The linked list is: ";
   display();
    return 0;
}
