int* my_slightly_dumb_reallocation(int* source, unsigned int n_old, unsigned int n_new){
    int* arr = new int[n_new];
    if (source == nullptr and n_new == 0) {
        delete[] arr;
        return nullptr;
    } else if (source == nullptr and n_new != 0) {
        return arr;
    }
    else {
        if (n_new == 0) {
            delete[] source;
            delete[] arr;
            return nullptr;
        }
        if (n_old > n_new) {
            for (int i = 0; i < n_new; i++) {
                arr[i] = source[i];
            }
        }
        else {
            for (int i = 0; i < n_old; i++) {
                arr[i] = source[i];
            }
        }
    delete[] source;
    return arr;
    }
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << do_some_awesome_work(&a, &b) << endl;
    return 0;
}
