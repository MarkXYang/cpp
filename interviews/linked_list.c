#include <stdio.h>

struct node {
    int data;
    struct node* next;
};

struct node* create_node(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int get_length(struct node* head) {
    int len = 0;

    while( head != NULL) {
        len++;
        head = head->next;
    }

    return len;
}

struct node* get_nth(struct node* head, int n)
{
    if (n < 0) {
        return NULL;
    }
    int index = 0;
    while(head != NULL && index < n) {
        index++;
        head = head->next;
    }

    return head;
}

void append_data(struct node** headRef, int data) {
    /* 1. Allocate memory for a node*/
    /* 2. Add the node to list*/
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if (*headRef == NULL) {
        *headRef = new_node;
        return;
    }

    struct node* last = *headRef;
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
}

int pop(struct node* headRef) {
    assert(headRef != NULL);

    if(*headRef != NULL) {
        printf("Freeing: %d", (*headRef)->data);
        struct node* next = (*headRef)->next;

        int data = (*headRef)->data;
        (*headRef)->next = NULL;
        free(*headRef);

        *headRef = next;
        return data;
    }
}

void delete_list(struct node** headRef) {
    assert(headRef != NULL);

    struct node* head = *headRef;
    struct node* next = NULL;

    while(head != NULL) {
        printf("Freeing: %d", head->data);
        next = head->next;
        head->next = NULL;
        free(head);

        head = next;
    }
}

void insert_nth(struct node** headRef, int data, int n) {
    assert(headRef != NULL);
    assert(n >= 0);

    /* Case n == 0 or *headRef == NULL*/
    if(n == 0 || *headRef == NULL) {
        struct node* headNode = create_node(data);
        headNode->next = *headRef;
        *headRef = headNode;
        return;
    }

    int index = 0;
    struct node* head = *headRef;
    struct node* prev = *headRef;

    /* Traverse to nth */
    while(head != NULL && index < n) {
        prev = head;
        head = head->next;
        index++;
    }

    if(prev != NULL) {
        prev->next = create_node(data);
        prev->next->next = head;
    }
}

void sorted_insert(struct node** headRef, int data) {
    assert(headRef != NULL);

    struct node* new_node = create_node(data);
    struct node* current = *headRef;
    struct node* prev = NULL;

    // If the list is empty or the new node should be inserted at the beginning
    if (*headRef == NULL || data < (*headRef)->data) {
        new_node->next = *headRef;
        *headRef = new_node;
        return;
    }

    // Traverse the list to find the correct position
    while (current != NULL && current->data <= data) {
        prev = current;
        current = current->next;
    }

    // Insert the new node
    new_node->next = current;
    prev->next = new_node;
}

void append_second_list(struct node** list_a, struct node** list_b) {
    assert(list_a != NULL && list_b != NULL);

    // If the first list is empty, just point it to the second list
    if (*list_a == NULL) {
        *list_a = *list_b;
        *list_b = NULL;
        return;
    }

    // Traverse to the end of the first list
    struct node* current = *list_a;
    while (current->next != NULL) {
        current = current->next;
    }

    // Append the second list to the end of the first list
    current->next = *list_b;

    // Set the second list's head to NULL
    *list_b = NULL;
}

void front_back_split(struct node* source, struct node** frontRef, struct node** backRef) {
    assert(source != NULL && frontRef != NULL && backRef != NULL);

    // If the list has less than 2 elements, put all in front
    if (source == NULL || source->next == NULL) {
        *frontRef = source;
        *backRef = NULL;
        return;
    }

    struct node* slow = source;
    struct node* fast = source->next;

    // Move 'fast' two nodes ahead, 'slow' one node ahead
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    // 'slow' is before the midpoint, split the list there
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

struct node* reverse(struct node* list) {
    struct node* newlist = NULL;
    struct node* current = list;
    struct node* next = NULL;

    while (current != NULL) {
        next = current->next; // Store next node
        current->next = newlist; // Reverse current node's pointer
        newlist = current;       // Move pointers one position ahead
        current = next;
    }

    return newlist;
}

struct node* sorted_merge(struct node* a, struct node* b) {
    struct node* result = NULL;

    // Base cases
    if (a == NULL)
        return b;
    else if (b == NULL)
        return a;

    // Pick either a or b, and recur
    if (a->data <= b->data) {
        result = a;
        result->next = sorted_merge(a->next, b);
    } else {
        result = b;
        result->next = sorted_merge(a, b->next);
    }

    return result;
}

void move_node(struct node** sourceRef, struct node** desRef) {
    assert(sourceRef != NULL && destRef != NULL);
    if (*sourceRef == NULL) {
        return;
    }

    struct node* cur_src = *sourceRef;
    *sourceRef = cur_src->next;
    cur_src->next = *desRef;
    *desRef = cur_src;
}

void remove_duplicates(struct node* source) {
    if(source == NULL || source->next == NULL) {
        return;
    }

    struct node* curr = source;
    struct node* next_node = source->next;

    while(next != NULL) {
        if(next_node->data == curr->data) {
            curr->next = next_node->next;
            next_node->next = NULL;
            free(next_node);

            next_node = curr->next;
            continue;
        }
        curr = next_node;
        next_node = curr->next;
    }
}

