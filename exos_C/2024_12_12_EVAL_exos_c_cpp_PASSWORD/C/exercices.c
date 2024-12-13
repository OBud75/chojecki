#include <stdio.h>
#include <string.h>

typedef struct {
    int age;
} Person;

typedef struct {
    int pages;
} Book;

int are_persons_equals(void *p1, void *p2) {
    return ((Person *)p1)->age == ((Person *)p2)->age;
}

int are_books_equals(void *b1, void *b2) {
    return ((Book *)b1)->pages == ((Book *)b2)->pages;
}

void swap(void *a, void *b, size_t size) {
    char temp[size];
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
}

int is_greater(void *a, void *b) {
    return ((Person *)a)->age > ((Person *)b)->age;
}

int is_in_array(void *element, void *array, size_t num_elements, size_t element_size, int (*equals)(void *, void *)) {
    for (size_t i = 0; i < num_elements; i++) {
        if (equals(element, (char *)array + i * element_size)) {
            return 1;
        }
    }
    return 0;
}

void sort(void *array, size_t num_elements, size_t element_size, int (*compare)(void *, void *), void (*swap_func)(void *, void *, size_t)) {
    for (size_t i = 0; i < num_elements - 1; i++) {
        for (size_t j = i + 1; j < num_elements; j++) {
            void *elem_i = (char *)array + i * element_size;
            void *elem_j = (char *)array + j * element_size;
            if (compare(elem_i, elem_j)) {
                swap_func(elem_i, elem_j, element_size);
            }
        }
    }
}

void eq_function() {
    Person person1 = {50};
    Person person2 = {0};
    int same_age = are_persons_equals(&person1, &person2);
    if (same_age == 1) {
        printf("meme age.\n");
    }
}

void linear_search() {
    Person person1 = {50};
    Person people[] = {{20}, {50}};
    int found = is_in_array(
        &person1, people,
        sizeof(people) / sizeof(Person), sizeof(Person),
        are_persons_equals
    );
    if (found == 1) {
        printf("P1 est dans le tab.\n");
    }

    Book book1 = {50};
    Book books[] = {{20}, {50}};
    found = is_in_array(
        &book1, books,
        sizeof(books) / sizeof(Book), sizeof(Book),
        are_books_equals
    );
    if (found == 1) {
        printf("B1 est dans le tab.\n");
    }
}

void generic_swap() {
    Person person1 = {50};
    Person person2 = {25};
    swap(&person1, &person2, sizeof(Person));
    printf("swap personnes: person1.age = %d, person2.age = %d\n", person1.age, person2.age);

    Book b1 = {50};
    Book b2 = {25};
    swap(&b1, &b2, sizeof(Book));
    printf("Swap book: b1.pages = %d, b2.pages = %d\n", b1.pages, b2.pages);
}

int main() {


    return 0;
}
