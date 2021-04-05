#include <iostream>

using namespace std;

struct subforwardlist {
  int data;
  subforwardlist* next;
};

bool init(subforwardlist** lst){
    if (lst != nullptr){
        *lst = nullptr;
        return true;
    }
}

bool push_back(subforwardlist** lst, int d){
    if (lst != nullptr){
        if (*lst != nullptr)
            return push_back(&(*lst)->next, d);
        *lst = new subforwardlist;
        (*lst)->data = d;
        (*lst)->next = nullptr;
        return true;
    }
}

int pop_back(subforwardlist** lst){
    if (lst != nullptr){
        if (*lst == nullptr)
            return 0;
        if ((*lst)->next != nullptr)
            return pop_back(&(*lst)->next);
        int p = (*lst)->data;
        delete *lst;
        *lst = nullptr;
        return p;
  }
}

bool push_forward(subforwardlist** lst, int d){
    if (lst != nullptr){
        subforwardlist* node = new subforwardlist;
        node->data = d;
        node->next = *lst;
        *lst = node;
        return true;
    }
}

int pop_forward(subforwardlist** lst){
    if (lst != nullptr){
        if (*lst == nullptr)
            return 0;
        int p = (*lst)->data;
        subforwardlist* place = *lst;
        *lst = (*lst)->next;
        delete place;
        return p;
    }
}

bool push_where(subforwardlist** lst, unsigned int where, int d){
    if (lst != nullptr){
        if (where > 1)
            return push_where(&(*lst)->next, where - 1, d);
        return push_forward(lst, d);
    }
}

bool erase_where(subforwardlist** lst, unsigned int where){
  if (lst != nullptr){
        if (where > 1)
            return erase_where(&(*lst)->next, where - 1);
        pop_forward(lst);
        return true;
    }
}

unsigned int size(subforwardlist** lst){
    if (lst != nullptr){
        if ((*lst) == nullptr)
            return 0;
        return (size(&(*lst)->next) + 1);
    }
}

void clear(subforwardlist** lst){
    unsigned int Size = size(lst);
    for (int i = 0; i < Size; ++i)
        pop_forward(lst);
}
