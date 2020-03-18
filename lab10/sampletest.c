// Starting code for Q1 Sample Questions for Week-11 Lab Practical Exam 
// Base code by Elizabeth Willer 

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};


struct node *strings_to_list(int len, char *strings[]);
void print_list(struct node *head);
int sum_list(struct node *head);
struct node *find_item(struct node *head, int item);
int find_last(struct node *head);
int find_nth(struct node *head, int nth);
struct node *add_last(struct node *head, int item);
struct node *remove_first(struct node *head);
struct node *remove_last(struct node *head) ;
struct node *remove_item(struct node *head, int item);
void free_list(struct node *head);
struct node *lastToFirst(struct node *head);
struct node *zip(struct node *head1, struct node *head2);

int main(int argc, char *argv[]) {
   // TODO: Write some test cases for your functions  
   char *list1[] = {"1","3","5","7"};
   struct node *head1 = strings_to_list(4, list1);
   char *list2[] = {"2", "4", "6"};
   struct node *head2 = strings_to_list(3, list2);
   print_list(zip(head1, head2));
   //print_list(head1);
   //print_list(add_last(head1, 16));
   //printf("%d\n", find_nth(head1, 1));
   //print_list(remove_item(head1,16));
   //print_list(lastToFirst(head1));
   
   
   /*
   char *list2[] = {"1", "2", "3", "4"};
   struct node *head2 = strings_to_list(4, list2);
   print_list(head2);
   print_list(add_last(head2, 22));
   printf("%d\n", find_nth(head2, 5));
   print_list(remove_last(head2));
   print_list(lastToFirst(head2));
   
   char *list3[] = {};
   struct node *head3 = strings_to_list(0, list3);
   print_list(head3);
   print_list(add_last(head3, 122));
   // printf("%d\n", find_nth(head3, 1));
   print_list(remove_last(head3));
   print_list(lastToFirst(head3));
   */
   return 0;
}




// create linked list from array of strings
struct node *strings_to_list(int len, char *strings[]) {
    struct node *head = NULL;
    int i = len - 1;
    while (i >= 0) {
        struct node *n = malloc(sizeof (struct node));
        assert(n != NULL);
        n->next = head;
        n->data = atoi(strings[i]);
        head = n;
        i = i-1;
    }
    return head;
}


// print linked list in python style (i.e. [1, 2, 3, 4])
void print_list(struct node *head) {
    // TODO: Write this function first!
    // This will help you write your tests!
    
    printf("[");
    struct node *n;
    for (n = head; n != NULL; n = n->next) {
        printf("%d", n->data);
        if (n->next != NULL) {
            printf(",");
        }
    }
    printf("]\n");
}


//calculate sum of a list
int sum_list(struct node *head) {
    // TODO: complete this function
    
    int sum = 0;
    for (struct node *n = head; n != NULL; n = n->next) {
        sum = sum + n->data;
    }
    return sum;
}


//find an item (say 25) in a list (return pointer to that item)
struct node *find_item(struct node *head, int item) {
    // TODO: complete this function
    
    struct node *n = head;
    while ( n != NULL && n->data != item) {
        n = n->next;
    }
    return n;
}

//find last item in a list (return the value of that item)
int find_last(struct node *head) {
    // TODO: complete this function
    
    if (head == NULL) {
        return 0;
    }
    
    struct node *n = head;
    while (n->next != NULL) {
            n = n->next;
    }
    return n->data;
}

//find nth item in a list (return the value of that item)
int find_nth(struct node *head, int nth) {
    // TODO: complete this function
    
    int count = 1;
    struct node *n = head;
    while (count != nth) {
        n = n->next;
        count++;
    }
    return n->data;
}

//add item at the end of the list (return a pointer to the head of the list)
struct node *add_last(struct node *head, int item) {
    // TODO: complete this function
    
    struct node *n = head;
    struct node *last = malloc(sizeof(struct node));
    last->data = item;
    last->next = NULL;
    
    if (head == NULL) {
        return last;
    }
    else {
        while (n->next != NULL) {
            n = n->next;
        }
        n->next = last;
        return head;
    }

}

//remove first item from a list (return a pointer to the head of the list)
struct node *remove_first(struct node *head) {
    // TODO: complete this function
    
    if (head == NULL || head->next == NULL) {
        return NULL;
    }
    else {
        struct node *tmp = head;
        head = head->next;
        free(tmp);
        return head;
    }
}

//remove last item from a list (return a pointer to the head of the list)
struct node *remove_last(struct node *head) {
    // TODO: complete this function
    
    if (head == NULL || head->next == NULL) {
        return NULL;
    }
    else {
        struct node *curr = head;
        struct node *prev;
        while (curr->next != NULL) {
            prev = curr;
            curr = curr->next;
        }
        free(curr);
        prev->next = NULL;
        return head;
    }
    
}

//remove a given item (say 25) from a list (return a pointer to the head of the list)
struct node *remove_item(struct node *head, int item) {
    // TODO: complete this function
    
    struct node *curr = head;

    if (head->data == item) {
        head = curr->next;
        free(curr);
    }
    else {
        struct node *prev;
        while (curr != NULL && curr->data != item) {
                prev = curr;
                curr = curr->next;
            }
            prev->next = curr->next;
            free(curr);
        
    }        
    return head;
}
/*
// free the memory used by the linked list
void free_list(struct node *head) {
    // TODO: complete this function
    
}*/

struct node *lastToFirst(struct node *head) {
    
    if (head == NULL || head->next == NULL) {
        return head;
    }
    else {
        struct node *curr = head;
        struct node *prev;
        while (curr->next != NULL) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = NULL;
        curr->next = head;
        head = curr;
        
        return head; 
    }
    
}

struct node *zip(struct node *head1, struct node *head2) {

    if (head1 == NULL) {
        return head2;    
    }
    else if (head2 == NULL) {
        return head1;    
    }
    else {
        struct node *prev = head1;
        struct node *curr = head2;
        struct node *next = prev->next;
        while (curr != NULL) {
            prev->next = curr;
            prev = curr;
            curr = next;
            next = prev->next;
        }
        return head1;
    }
    
}


