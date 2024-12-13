typedef struct Person {
    int age;
} Person;

int are_persons_equals(Person *p1, Person *p2) {
    return p1->age == p2->age;
}

typedef struct Book {
    int pages;
} Book;

int are_books_equals(Book *b1, Book *b2) {
    return b1->pages == b2->pages;
}

int are_equals(
    void *obj1, void *obj2,
    int (*compare_fnc)(void *, void *)) {
    return compare_fnc(obj1, obj2);
}

int is_greater(
    void *obj1, void *obj2,
    int (*compare_fnc)(void *, void *)) {
    return compare_fnc(obj1, obj2) > 0;
}

void swap(void *obj1, void *obj2, size_t size) {
    char temp[size];
    memcpy(temp, obj1, size);
    memcpy(obj1, obj2, size);
    memcpy(obj2, temp, size);
}

void sort(
    void *array,
    int nb_of_elems_in_array,
    size_t elem_size,
    int (*compare_fnc)(void *, void *),
    void (*swap_fnc)(void *, void *, size_t)) {

    char *arr = (char *)array;
    for (int i = 0; i < nb_of_elems_in_array - 1; i++) {
        for (int j = i + 1; j < nb_of_elems_in_array; j++) {
            void *elem1 = arr + i * elem_size;
            void *elem2 = arr + j * elem_size;
            if (compare_fnc(elem1, elem2) > 0) {
                swap_fnc(elem1, elem2, elem_size);
            }
        }
    }
}

int is_in_array(void *obj_to_find,
                void *array,
                int nb_of_elems_in_array,
                size_t elem_size,
                int (*compare_fnc)(void *, void *)) {
    char *arr = (char *)array;
    for (int i = 0; i < nb_of_elems_in_array; i++) {
        void *current_elem = arr + i * elem_size;
        if (compare_fnc(obj_to_find, current_elem)) {
            return 1;
        }
    }
    return 0;
}
