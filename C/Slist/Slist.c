#include <stdio.h>
#include <stdlib.h>
#include "Slist.h"

SList* slist_create() {
    SList* list = (SList*)malloc(sizeof(SList));
    if (!list) return NULL;
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

SList* slist_destroy(SList* list, void (*free_data)(void*)) {
    if (!list) return NULL;
    SListNode* current = list->head;
    while (current) {
        SListNode* next = current->next;
        if (free_data) {
            free_data(current->data);
        }
        free(current);
        current = next;
    }
    free(list);
    return NULL;
}

int slist_push_front(SList* list, void* data) {
    if (!list) return -1;
    SListNode* new_node = (SListNode*)malloc(sizeof(SListNode));
    if (!new_node) return -1;
    new_node->data = data;
    new_node->next = list->head;
    list->head = new_node;
    if (list->size == 0) {
        list->tail = new_node;
    }
    list->size++;
    return 0;
}

int slist_push_back(SList* list, void* data) {
    if (!list) return -1;
    SListNode* new_node = (SListNode*)malloc(sizeof(SListNode));
    if (!new_node) return -1;
    new_node->data = data;
    new_node->next = NULL;
    if (list->size == 0) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
    list->size++;
    return 0;
}

void* slist_pop_front(SList* list) {
    if (!list || list->size == 0) return NULL;
    SListNode* old_head = list->head;
    void* data = old_head->data;
    list->head = old_head->next;
    free(old_head);
    list->size--;
    if (list->size == 0) {
        list->tail = NULL;
    }
    return data;
}

void* slist_pop_back(SList* list) {
    if (!list || list->size == 0) return NULL;
    SListNode* current = list->head;
    SListNode* prev = NULL;
    while (current->next) {
        prev = current;
        current = current->next;
    }
    void* data = current->data;
    if (prev) {
        prev->next = NULL;
        list->tail = prev;
    } else {
        list->head = NULL;
        list->tail = NULL;
    }
    free(current);
    list->size--;
    return data;
}
size_t slist_size(SList* list) {
    if (!list) return 0;
    return list->size;
}
int slist_is_empty(SList* list) {
    if (!list) return 1;
    return list->size == 0;
}

void slist_print(SList* list, void (*print_data)(void*)) {
    if (!list || !print_data) return;
    SListNode* current = list->head;
    while (current) {
        print_data(current->data);
        current = current->next;
    }
}

void slist_reverse(SList* list) {
    if (!list || list->size <= 1) return;
    SListNode* prev = NULL;
    SListNode* current = list->head;
    SListNode* next = NULL;
    list->tail = list->head;
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    list->head = prev;
}

int slist_remove(SList* list, void* data, int (*cmp_data)(void*, void*)) {
    if (!list || list->size == 0 || !cmp_data) return -1;
    SListNode* current = list->head;
    SListNode* prev = NULL;
    while (current) {
        if (cmp_data(current->data, data) == 0) {
            if (prev) {
                prev->next = current->next;
            } else {
                list->head = current->next;
            }
            if (current == list->tail) {
                list->tail = prev;
            }
            free(current);
            list->size--;
            return 0;
        }
        prev = current;
        current = current->next;
    }
    return -1;
}
int slist_find(SList* list, void* data, int (*cmp_data)(void*, void*)) {
    if (!list || !cmp_data) return 0;
    SListNode* current = list->head;
    while (current) {
        if (cmp_data(current->data, data) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}
int slist_insert_after(SList* list, SListNode* node, void* data) {
    if (!list || !node) return -1;
    SListNode* new_node = (SListNode*)malloc(sizeof(SListNode));
    if (!new_node) return -1;
    new_node->data = data;
    new_node->next = node->next;
    node->next = new_node;
    if (node == list->tail) {
        list->tail = new_node;
    }
    list->size++;
    return 0;
}
int slist_insert_before(SList* list, SListNode* node, void* data) {
    if (!list || !node) return -1;
    if (node == list->head) {
        return slist_push_front(list, data);
    }
    SListNode* current = list->head;
    while (current && current->next != node) {
        current = current->next;
    }
    if (!current) return -1;
    SListNode* new_node = (SListNode*)malloc(sizeof(SListNode));
    if (!new_node) return -1;
    new_node->data = data;
    new_node->next = node;
    current->next = new_node;
    list->size++;
    return 0;
}

void slist_clear(SList* list, void (*free_data)(void*)) {
    if (!list) return;
    SListNode* current = list->head;
    while (current) {
        SListNode* next = current->next;
        if (free_data) {
            free_data(current->data);
        }
        free(current);
        current = next;
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}
void slist_sort(SList* list, int (*cmp_data)(void*, void*)) {
    if (!list || list->size <= 1 || !cmp_data) return;

    int swapped;
    do {
        swapped = 0;
        SListNode* current = list->head;
        while (current && current->next) {
            if (cmp_data(current->data, current->next->data) > 0) {
                void* temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = 1;
            }
            current = current->next;
        }
    } while (swapped);
}
int main() {
    SList* my_list = slist_create();
    if (!my_list) {
        fprintf(stderr, "Failed to create list\n");
        return EXIT_FAILURE;
    }

    slist_push_back(my_list, (void*)1);
    slist_push_back(my_list, (void*)2);
    slist_push_back(my_list, (void*)3);
    slist_print(my_list, [](void* data) { printf("%d\n", (int)(intptr_t)data); });

    
    slist_destroy(my_list, NULL);

    free(my_list);
    return EXIT_SUCCESS;
}