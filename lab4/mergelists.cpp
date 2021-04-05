
Node* mergeLists(Node* first_node, Node* second_node) {
	Node* merge_list = new Node;
	// проверим, что нет пустых списков и в случае, если они есть
	// добавим непустой в конец замЄрдженного
	if (first_node == nullptr or second_node == nullptr) {
        if (first_node == nullptr && second_node == nullptr)
			return nullptr;
        if (first_node == nullptr && second_node != nullptr)
            return second_node;
        if (first_node != nullptr && second_node == nullptr)
            return first_node;
    }
    // задаЄм €чейку с значением и ссылкой на следующий от меньшего
    // элемента из оставшихс€
    else {
		if (first_node->value > second_node->value) {
			merge_list->value = second_node->value;
			merge_list->next = mergeLists(first_node, second_node->next);
		}
		if (first_node->value < second_node->value) {
			merge_list->value = first_node->value;
			merge_list->next = mergeLists(first_node->next, second_node);
		}
		if (first_node->value == second_node->value) {
			merge_list->value = first_node->value;
			merge_list->next = mergeLists(first_node->next, second_node->next);
		}
	}
	return merge_list;
}
