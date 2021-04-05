#ifndef SUBSET_SUBSET_H
#define SUBSET_SUBSET_H
struct subset_node { // дерево поиска УsubsetФ
    int key;
    subset_node *left = nullptr;
    subset_node *right = nullptr;
    //subset_node *parent = nullptr;
}; // можете добавл€ть дополнительные пол€ и структуры данных (например, дл€ BFS)
bool init(subset_node **sn); //инициализаци€ пустого дерева
bool insert(subset_node **sn, int k); //добавление элемента в дерево, дубли игнорировать
bool remove(subset_node **sn, int k); //удаление элемента из дерева
subset_node* find(subset_node *sn, int k); //поиск элемента в дереве
unsigned int size(subset_node *sn); //количество элементов в дереве
unsigned int height(subset_node *sn); //высота дерева
void destructor(subset_node *sn); //очистить всю используемую пам€ть
int* DFS (subset_node *sn); //обход в глубину, возвращает указатель на массив
subset_node *insert_sub(subset_node **sn, int k);
subset_node *remove_sub(subset_node** sn, int k);
subset_node *minimum(subset_node **sn);
void DFSdepth(subset_node *sn, int *arr, int* len);
#endif //SUBSET_SUBSET_H
