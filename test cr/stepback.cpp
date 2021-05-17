int find_prev_value(list_element* root, int value){
    list_element* elem = root;
    while (elem->value != value) {
        elem = elem->next;
    }
    return elem->prev->value;
    return 0;
}
