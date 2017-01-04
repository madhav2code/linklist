/*
 * linklist.c
 *
 *  Created on: Jan 4, 2017
 *      Author: test
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linklist.h"


struct node *head = NULL;
int size = 0;

void print_list()
{
    struct node *tmp = head;

    while (tmp != NULL) {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }

    printf("\n");
}

int list_size()
{
    return size;
}

int is_empty()
{
    return (size) ? 1 : 0;
}

struct node * node_at(int index)
{
    struct node *ptr = head;
    int tmp = 0;

    if (index > size) {
        return NULL;
    }
    while((ptr != NULL) && (tmp != index)) {
        ptr = ptr->next;
        tmp++;
    }

    return ptr;

}

int value_at(int index)
{
    struct node *ptr = head;
    int tmp = 0;

    if (index > size) {
        return -1;
    }
    while((ptr != NULL) && (tmp != index)) {
        ptr = ptr->next;
        tmp++;
    }

    return (ptr) ? ptr->data : -1;
}

void push_front(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL) {
        return;
    }

    n->data = data;
    n->next = head;
    head = n;
    size++;
}

struct node * pop_front()
{
    struct node *ptr = head;

    if (head != NULL) {
        head = head->next;
    }
    size--;
    return ptr;
}

void push_back(int data)
{
    struct node **ptr = &head;
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL) {
        return;
    }

    n->data = data;
    n->next = NULL;
    if (*ptr == NULL) {
        *ptr = n;
        return;
    }

    while((*ptr)->next != NULL) {
        ptr = &((*ptr)->next);
    }
    (*ptr)->next = n;
}

struct node* pop_back()
{
    struct node *ptr = head;
    struct node *prv = head;

    if (!is_empty()) {
        printf("List is empty\n");
        return NULL;
    }
    if (ptr->next == NULL) {
        head = NULL;
        return ptr;
    }

    while (ptr->next != NULL) {
        prv = ptr;
        ptr = ptr->next;
    }

    prv->next = NULL;
    printf("data = %d\n", ptr->data);
    return ptr;
}

void sorted_insert(int data)
{
    struct node **ptr = &head;
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL) {
        return;
    }

    n->data = data;
    n->next = NULL;
    if (*ptr == NULL || (*ptr)->data >= data) {
        n->next = *ptr;
        *ptr = n;
        return;
    }

    while((*ptr)->next != NULL && (*ptr)->next->data < data) {
        ptr = &((*ptr)->next);
    }
    n->next = (*ptr)->next;
    (*ptr)->next = n;
}

void delete_node(struct node *n)
{
    struct node **ptr = &head;

    while (*ptr != n) {
        ptr = &(*ptr)->next;
    }
    if (*ptr == NULL) {
        return;
    }
    *ptr = n->next;
}
int main(int argc, char* argv[])
{
    printf("is empty %s\n", is_empty() ? "false" : "true");
    push_front(10);
    push_front(20);
    push_front(30);
    push_front(40);
    push_back(50);
    print_list();
    pop_back();
    print_list();
    pop_front();
    print_list();
    printf("size = %d\n", list_size());
    printf("value at %d = %d\n", 5, value_at(5));
    printf("value at %d = %d\n", 2, value_at(2));
    print_list();
    delete_node(node_at(5));
    print_list();
    printf("is empty %s\n", is_empty() ? "false" : "true");
    //printf("pop_back %d\n", pop_back()->data);
    return 0;
}
