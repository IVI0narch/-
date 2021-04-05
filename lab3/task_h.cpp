Cat* get_home_for_a_cats_pride(unsigned int a){
    Cat* cats = new Cat[a];
    for (int i = 0; i < a; i++){
        cats[i].name = new char[10];
    }
    return cats;
}

void clear_home_of_a_cats_pride(Cat *cats, unsigned int a){
    for (int i = 0; i < n; i++)
        delete [] cats[i].name;
    delete [] cats;
}
