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
