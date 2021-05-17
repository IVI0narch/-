#include <iostream>
#include <fstream>

using namespace std;
struct Step {
    unsigned int x, y;
    Step *next;
};

struct Irbis {
    unsigned int id;
    char desciption[25];
    Step *route;
    char name[15];
};

int main() {
    char *name = "file.txt";
    int n = 2;
    Irbis family[2]= {1, "lalala", nullptr, "Lilia", 2, "blabla", nullptr, "Victor"};
    ofstream s(name);
    char *byteheap = (char *) family; //здесь family это массив структур Irbis из n элементов
    for (int i = 0; i < sizeof(Irbis) * n; i++) {
        s << byteheap[i];
    }
    s.close();
    ifstream d(name);
    if(d.is_open()) cout<<"AAA";
    char a[100];
    d>>a;
    for (int i = 0; i < n; ++i) {
        //d>>a;
        cout<<a;
    }
    d.close();
    return 0;
}
