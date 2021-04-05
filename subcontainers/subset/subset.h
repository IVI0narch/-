#ifndef SUBSET_SUBSET_H
#define SUBSET_SUBSET_H
struct subset_node { // ������ ������ �subset�
    int key;
    subset_node *left = nullptr;
    subset_node *right = nullptr;
    //subset_node *parent = nullptr;
}; // ������ ��������� �������������� ���� � ��������� ������ (��������, ��� BFS)
bool init(subset_node **sn); //������������� ������� ������
bool insert(subset_node **sn, int k); //���������� �������� � ������, ����� ������������
bool remove(subset_node **sn, int k); //�������� �������� �� ������
subset_node* find(subset_node *sn, int k); //����� �������� � ������
unsigned int size(subset_node *sn); //���������� ��������� � ������
unsigned int height(subset_node *sn); //������ ������
void destructor(subset_node *sn); //�������� ��� ������������ ������
int* DFS (subset_node *sn); //����� � �������, ���������� ��������� �� ������
subset_node *insert_sub(subset_node **sn, int k);
subset_node *remove_sub(subset_node** sn, int k);
subset_node *minimum(subset_node **sn);
void DFSdepth(subset_node *sn, int *arr, int* len);
#endif //SUBSET_SUBSET_H
