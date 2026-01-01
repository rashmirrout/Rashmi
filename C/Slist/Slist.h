#include <stdio.h>
#include <stdlib.h>

#ifndef SLIST_H
#define SLIST_H
typedef struct SListNode {
    void* data;
    struct SListNode* next;
} SListNode;

typedef struct SList {
    SListNode* head;
    SListNode* tail;
    size_t size;
} SList;

SList* slist_create();
void slist_destroy(SList* list, void (*free_data)(void*));
int slist_push_front(SList* list, void* data);
int slist_push_back(SList* list, void* data);
void* slist_pop_front(SList* list);
void* slist_pop_back(SList* list);
size_t slist_size(SList* list);
int slist_is_empty(SList* list);
void slist_print(SList* list, void (*print_data)(void*));
void slist_reverse(SList* list);
int slist_remove(SList* list, void* data, int (*cmp_data)(void*, void*));
int slist_find(SList* list, void* data, int (*cmp_data)(void*, void*));
int slist_insert_after(SList* list, SListNode* node, void* data);
int slist_insert_before(SList* list, SListNode* node, void* data);
void slist_clear(SList* list, void (*free_data)(void*));
void slist_sort(SList* list, int (*cmp_data)(void*, void*));









typedef struct _node {
    int data;
    struct _node* next;
} SLNode;

SLNode* CreateNode(int data);
SLNode* AppendNode(SLNode* head, int data);
SLNode* PrependNode(SLNode* head, int data);
SLNode* CreateListFromArray(int* arr, size_t size);
SLNode* DeleteList(SLNode* head);
SLNode* InsertAfter(SLNode* node, int data);
SLNode* InsertBefore(SLNode* head, SLNode* node, int data);
SLNode* RemoveNode(SLNode* head, SLNode* node);
void PrintList(SLNode* head);
SLNode* FindNode(SLNode* head, int data);
SLNode* DestroyList(SLNode* head);
SLNode* ReverseList(SLNode* head);
SLNode* MergeSortedLists(SLNode* head1, SLNode* head2);
SLNode* GetMiddleNode(SLNode* head);
SLNode* SortList(SLNode* head);
SLNode* RemoveDuplicates(SLNode* head);
SLNode* GetKthFromEnd(SLNode* head, int k);
SLNode* DetectCycle(SLNode* head);
SLNode* GetCycleStartNode(SLNode* head);
SLNode* RemoveCycle(SLNode* head);
SLNode* IntersectionNode(SLNode* head1, SLNode* head2);
SLNode* ReverseInGroups(SLNode* head, int k);
SLNode* RotateList(SLNode* head, int k);
SLNode* AddTwoNumbers(SLNode* l1, SLNode* l2);
SLNode* CopyListWithRandomPointer(SLNode* head);
SLNode* PartitionList(SLNode* head, int x);
SLNode* FlattenList(SLNode* head);
SLNode* DeleteNodeGivenOnlyAccess(SLNode* node);
SLNode* OddEvenList(SLNode* head);
SLNode* SwapPairs(SLNode* head);
SLNode* ReverseBetween(SLNode* head, int m, int n);
SLNode* RemoveNthFromEnd(SLNode* head, int n);
SLNode* RotateRight(SLNode* head, int k);
SLNode* MergeKSortedLists(SLNode** lists, int listsSize);
SLNode* DeleteDuplicatesFromSortedList(SLNode* head);
SLNode* DeleteDuplicatesFromSortedListII(SLNode* head);
SLNode* InsertionSortList(SLNode* head);
SLNode* SortListUsingMergeSort(SLNode* head);
SLNode* ReverseListRecursively(SLNode* head);
SLNode* RemoveElements(SLNode* head, int val);
SLNode* AddTwoNumbersII(SLNode* l1, SLNode* l2);
SLNode* RotateLeft(SLNode* head, int k);
SLNode* ReverseKGroup(SLNode* head, int k);
SLNode* MergeSortedListsRecursively(SLNode* l1, SLNode* l2);

void PrintListReverse(SLNode* head);
void FreeList(SLNode* head);
void CountNodes(SLNode* head, int* count);

int ListLength(SLNode* head);
int IsPalindrome(SLNode* head);
int HasCycle(SLNode* head);
int GetCycleLength(SLNode* head);
int GetCycleEntryIndex(SLNode* head);
int GetIntersectionNodeIndex(SLNode* head1, SLNode* head2);
int GetDecimalValue(SLNode* head);
int CompareLists(SLNode* head1, SLNode* head2);
int GetMiddleNodeIndex(SLNode* head);
int GetKthFromEndIndex(SLNode* head, int k);
int GetListSum(SLNode* head);
int GetMaxValue(SLNode* head);
int GetMinValue(SLNode* head);
int CountOccurrences(SLNode* head, int value);
int GetNodeIndex(SLNode* head, int value);


bool AreListsEqual(SLNode* head1, SLNode* head2);
bool IsListSorted(SLNode* head);
bool IsListCircular(SLNode* head);
bool IsListEmpty(SLNode* head);
bool ContainsValue(SLNode* head, int value);
bool IsListReversed(SLNode* head1, SLNode* head2);
bool HasDuplicates(SLNode* head);
bool IsListPalindrome(SLNode* head);
bool IsListPartitioned(SLNode* head, int x);
bool IsListRotated(SLNode* head, SLNode* rotatedHead);
bool IsListMerged(SLNode* head1, SLNode* head2, SLNode* mergedHead);
bool IsListFlattened(SLNode* head);
bool IsListCopiedCorrectly(SLNode* originalHead, SLNode* copiedHead);
bool IsListReversedInGroups(SLNode* head, int k, SLNode* reversedHead);
bool IsListSortedUsingMergeSort(SLNode* head, SLNode* sortedHead);
bool IsListRotatedRight(SLNode* head, int k, SLNode* rotatedHead);
bool IsListRotatedLeft(SLNode* head, int k, SLNode* rotatedHead);
bool IsListReversedBetween(SLNode* head, int m, int n, SLNode* reversedHead);
bool IsListMergedKSorted(SLNode** lists, int listsSize, SLNode* mergedHead);
bool IsListInsertionSorted(SLNode* head, SLNode* sortedHead);
bool IsListDeleteDuplicatesCorrect(SLNode* head, SLNode* expectedHead);
bool IsListDeleteDuplicatesIICorrect(SLNode* head, SLNode* expectedHead);
bool IsListAddTwoNumbersCorrect(SLNode* l1, SLNode* l2, SLNode* sumHead);
bool IsListAddTwoNumbersIICorrect(SLNode* l1, SLNode* l2, SLNode* sumHead);
bool IsListReverseKGroupCorrect(SLNode* head, int k, SLNode* reversedHead);


#endif // SLIST_H