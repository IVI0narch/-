#include <iostream>
#include <cstring>

using namespace std;

struct Animal {
    unsigned int type_id;
    char name[100];
    struct Animal *next;
    struct Event *history;
};

struct Event {
    unsigned int timestamp;
    char description[1024];
    struct Event *next;
};

// Эту функцию нужно реализовать
// Implement this
struct Animal *merge(struct Animal *list_one, struct Animal *list_two) {
    if(list_one== nullptr && list_two== nullptr)return nullptr;
    if(list_one == nullptr)return list_two;
    Animal *i = list_one;
    while(i->next != nullptr){
        i=i->next;
    }
    i->next = list_two;
    return list_one;
}


// Init animal history record
struct Event *create_history_record(unsigned int timestamp, const char description[1024]) {
    Event *e = new struct Event;
    e->timestamp = timestamp;
    strcpy(e->description, description);
    e->next = NULL;
    return e;
}

// Append new record to the history
struct Event *insert_into_history(struct Event *history, struct Event *record) {
    if (history == NULL) {
        return record;
    }
    struct Event *e = history;
    while (e->next != NULL) {
        e = e->next;
    }
    e->next = record;
    return history;
}

// Init animal record
struct Animal *create_animal(unsigned int type_id, const char name[100]) {
    Animal *a = new struct Animal;
    a->type_id = type_id;
    strcpy(a->name, name);
    a->next = NULL;
    a->history = NULL;
    return a;
}

// Append new animal to the farm
struct Animal *add_to_farm(struct Animal *farm, struct Animal *animal) {
    if (farm == NULL) {
        return animal;
    }
    struct Animal *a = farm;
    while (a->next != NULL) {
        a = a->next;
    }
    a->next = animal;
    return farm;
}

// Prints complete farm info
void print_farm(Animal *farm) {
    struct Animal *a = farm;
    while (a != NULL) {
        cout << a->name << " (type " << a->type_id << "):" << endl;
        struct Event *e = a->history;
        while (e != NULL) {
            cout << "  " << e->timestamp << ": " << e->description << endl;
            e = e->next;
        }
        a = a->next;
    }
}

// Cleans up everything
void destroy_farm(Animal *farm) {
    struct Animal *old_a;
    struct Animal *a = farm;
    while (a != NULL) {
        struct Event *old_e;
        struct Event *e = a->history;
        while (e != NULL) {
            old_e = e;
            e = e->next;
            delete old_e;
        }
        old_a = a;
        a = a->next;
        delete old_a;
    }
}
