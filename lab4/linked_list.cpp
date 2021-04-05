#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

struct List{
    Node* root = NULL;
};

void PushBack(List* arr, int val){
    Node* i = arr->root;
    if(i == NULL){
        Node* a = new Node;
        a->data = val;
        a->next = NULL;
        arr->root = a;
    }else{
        while(i->next != NULL){
            i = i->next;
        }
        Node* a = new Node;
        a->data = val;
        a->next = NULL;
        i->next = a;
    }
}

int PopFirst(List* arr){
    int ret = arr->root->data;
    arr->root = arr->root->next;
    return ret;
}

void PrintAll(List* arr){
    for(Node* i = arr->root; i!= NULL; i = i->next){
        cout << i->data << ' ';
    }
}

void Clear(List* arr){
    for(Node* i=arr->root; i!= NULL; i = i->next){
        delete i;
    }
    delete arr;
}

int main()
{
    List* a = new List;
    PushBack(a, 1);
    PushBack(a, 2);
    PushBack(a, 3);
    PushBack(a, 4);
    cout << PopFirst(a) << endl;
    PrintAll(a);
    Clear(a);
    return 0;
}
