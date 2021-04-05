
Node* mergeLists(Node* first_node, Node* second_node) {
	Node* merge_list = new Node;
	// ��������, ��� ��� ������ ������� � � ������, ���� ��� ����
	// ������� �������� � ����� ������������
	if (first_node == nullptr or second_node == nullptr) {
        if (first_node == nullptr && second_node == nullptr)
			return nullptr;
        if (first_node == nullptr && second_node != nullptr)
            return second_node;
        if (first_node != nullptr && second_node == nullptr)
            return first_node;
    }
    // ����� ������ � ��������� � ������� �� ��������� �� ��������
    // �������� �� ����������
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
