list_element* copy_reverse(list_element* root) {
    list_element* i = root;
    list_element* t_root = NULL;
    while (i != NULL)
    {
        list_element* elem = create_list_element(i->value);
        t_root = insert_into_list(t_root, elem);
        i = i->next;
    }
    return t_root;
}
