#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Slist.h"

SLNode* CreateNode(int data) {
    SLNode* new_node = (SLNode*)malloc(sizeof(SLNode));
    if (!new_node) return NULL;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

SLNode* AppendNode(SLNode* head, int data) {
    SLNode* new_node = CreateNode(data);
    if (!new_node) return head;
    if (!head) return new_node;
    SLNode* current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = new_node;
    return head;
}

SLNode* PrependNode(SLNode* head, int data) {
    SLNode* new_node = CreateNode(data);
    if (!new_node) return head;
    new_node->next = head;
    return new_node;
}
SLNode* CreateListFromArray(int* arr, size_t size) {
    SLNode* head = NULL;
    for (size_t i = 0; i < size; i++) {
        head = AppendNode(head, arr[i]);
    }
    return head;
}
SLNode* DeleteList(SLNode* head) {
    SLNode* current = head;
    while (current) {
        SLNode* next = current->next;
        free(current);
        current = next;
    }
    return NULL;
}
SLNode* InsertAfter(SLNode* node, int data) {
    if (!node) return NULL;
    SLNode* new_node = CreateNode(data);
    if (!new_node) return NULL;
    new_node->next = node->next;
    node->next = new_node;
    return new_node;
}
SLNode* InsertBefore(SLNode* head, SLNode* node, int data) {
    if (!head || !node) return head;
    if (head == node) {
        return PrependNode(head, data);
    }
    SLNode* current = head;
    while (current && current->next != node) {
        current = current->next;
    }
    if (!current) return head;
    SLNode* new_node = CreateNode(data);
    if (!new_node) return head;
    new_node->next = node;
    current->next = new_node;
    return head;
}
SLNode* RemoveNode(SLNode* head, SLNode* node) {
    if (!head || !node) return head;
    if (head == node) {
        SLNode* new_head = head->next;
        free(head);
        return new_head;
    }
    SLNode* current = head;
    while (current && current->next != node) {
        current = current->next;
    }
    if (!current) return head;
    current->next = node->next;
    free(node);
    return head;
}
void PrintList(SLNode* head) {
    SLNode* current = head;
    while (current) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
void PrintListRecurssive(SLNode* head) {
    if (!head) {
        printf("NULL\n");
        return;
    }
    printf("%d -> ", head->data);
    PrintListRecurssive(head->next);
}
SLNode* FindNode(SLNode* head, int data) {
    SLNode* current = head;
    while (current) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}
SLNode* DestroyList(SLNode* head) {
    SLNode* current = head;
    while (current) {
        SLNode* next = current->next;
        free(current);
        current = next;
    }
    return NULL;
}
SLNode* ReverseList(SLNode* head) {
    SLNode* prev = NULL;
    SLNode* current = head;
    SLNode* next = NULL;
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
SLNode* MergeSortedLists(SLNode* head1, SLNode* head2) {
    if (!head1) return head2;
    if (!head2) return head1;
    SLNode* merged_head = NULL;
    if (head1->data < head2->data) {
        merged_head = head1;
        head1 = head1->next;
    } else {
        merged_head = head2;
        head2 = head2->next;
    }
    SLNode* current = merged_head;
    while (head1 && head2) {
        if (head1->data < head2->data) {
            current->next = head1;
            head1 = head1->next;
        } else {
            current->next = head2;
            head2 = head2->next;
        }
        current = current->next;
    }
    if (head1) {
        current->next = head1;
    } else {
        current->next = head2;
    }
    return merged_head;
}