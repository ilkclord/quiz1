/*
 * =====================================================================================
 *
 *       Filename:  lkst.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  廿廿一年三月五日 〇時33分47秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
typedef struct node{
    struct node *next;
    struct node *pre;
    int data ;

}n;

void add(n * a , int data){
    a->next = malloc(sizeof(n));
    a->next->next = NULL;
    a->next->data = data;
    a->next->pre = a;
}
void  fake_swap(n * a , n * b){
    int tmp = a->data;
    a->data = b->data;
    b->data = tmp ;
}
void display(n * head){
    while(head != NULL){
        printf("%u ", head->data);
        head = head->next;
    }
    printf("%c",'\n');
}
n *  is_order(n * root){
    while(root->next != NULL){
        if(root->data - root->next->data > 0)
          return root;
        root = root->next ;
    }
    return NULL ;
}
n * find_tail(n * root){
  while(root->next != NULL)
    root = root->next ;
  return root ;
}
void quick_sort(n * list , n * tail){
    int pivot = list->data ;
    n * L = list;
    while(L != NULL){
        display(list);
        n * R = tail;
        while(&(*L) != &(*R)){
            while(R->data > pivot) R = R->pre ;
            fake_swap(L , R);
            while(L->data < pivot) L = L->next;
            fake_swap(L , R);
        }
        L->data = pivot ;
        L = is_order(list);
        if(L == NULL)
            return ;
        else
           pivot = L->data;
    }
}
n * reverse(n * root){
  if (root != NULL  && root->next != NULL){
        n *tmp = root->next;
        n *tmp2 = NULL;
        root->next = NULL;
        while (tmp != NULL) {
            printf("%u\n" , root->data);
            tmp2 = tmp->next;
            tmp->next = root;
            root = tmp;
            tmp = tmp2;
       }
    }
    return root;
}
int main(){
    int data[6] = {7,8,4,5,9,10 };
    n * head = malloc(sizeof(n));
    head->next = NULL;
    head->data = 7;
    head->pre = NULL;
    n *root = head;
    for(int i = 5 ; i> 0 ;i--){
        add(head , data[i]);
        head = head->next;
    }
    display(root);
    quick_sort(root , find_tail(root));
    display(root);

    return 0 ;
}
