#include <iostream>
#include "subset.h"


bool init(subset_node **sn) {
    *sn = nullptr;
    return true;
}

bool insert(subset_node **sn, int k) {
    if (insert_sub(sn, k) == nullptr){
        return false;
    }
    return true;
}

bool remove(subset_node **sn, int k) {
    if (*sn == nullptr){
        return false;
    }
    remove_sub(sn, k);
    return true;
}

subset_node *find(subset_node *sn, int k) {
    if (sn == nullptr || k == sn->key){
        return sn;
    }
    if (k > sn->key) {
        return find(sn->right, k);
    } else {
        return find(sn->left, k);
    }
}

unsigned int size(subset_node *sn) {
    if (sn != nullptr){
        return 1 + size(sn->left) + size(sn->right);
    }
    return 0;
}

unsigned int height(subset_node *sn) {
    if (sn == nullptr) {
        return 0;
    }
    return std::max(height(sn->right), height(sn->left)) + 1;
}

void destructor(subset_node *sn) {
    if (sn != nullptr) {
        destructor(sn->left);
        destructor(sn->right);
    }
    delete sn;
}

int *DFS(subset_node *sn) {
    int *ret = new int[size(sn)];
    int len = 0;
    DFSdepth(sn, ret, &len);
    return ret;
}

subset_node *insert_sub(subset_node **sn, int k) {
    if (*sn == nullptr) {
        *sn = new subset_node;
        (*sn)->key = k;
        return *sn;
    } else if ((*sn)->key < k) {
        (*sn)->right = insert_sub(&(*sn)->right, k);
    } else if ((*sn)->key > k) {
        (*sn)->left = insert_sub(&(*sn)->left, k);
    }
    return *sn;
}

subset_node *remove_sub(subset_node **sn, int k) {
    if (*sn == nullptr){
        return *sn;
    }
    else if ((*sn)->key < k){
        (*sn)->right = remove_sub(&(*sn)->right, k);
    }
    else if ((*sn)->key > k){
        (*sn)->left = remove_sub(&(*sn)->left, k);
    }
    else if ((*sn)->left != nullptr && (*sn)->right != nullptr){
        (*sn)->key = minimum(&(*sn)->right)->key;
        (*sn)->right = remove_sub(&(*sn)->right, (*sn)->key);
    } else {
        subset_node *del;
        del = *sn;
        if ((*sn)->left != nullptr) {
            *sn = (*sn)->left;
        } else if ((*sn)->right != nullptr) {
            *sn = (*sn)->right;
        } else *sn = nullptr;
        delete del;
    }
    return *sn;
}

subset_node *minimum(subset_node **sn) {
    if ((*sn)->left == nullptr){
        return *sn;
    }
    return minimum(&(*sn)->left);
}

void DFSdepth(subset_node *sn, int *arr, int *len) {
    if (sn != nullptr) {
        DFSdepth(sn->left, arr, len);
        arr[*len] = sn->key;
        (*len)++;
        DFSdepth(sn->right, arr, len);
    }
}
