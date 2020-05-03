#include <string.h>

typedef struct Node {
    char data;
    struct Node* next;
} node;

bool isValid(char * s){
    node* head = NULL;
    char ref[] = "()[]{}";
    int i = 0;
    
    while (*(s+i) != '\0') {
        //If left bracket, add to linked list
        if (s[i] == ref[0] || s[i] == ref[2] || s[i] == ref[4]) {
            if (!head) {
                head = (node*)malloc(sizeof(node));
                head->data = s[i];
                head->next = NULL;
            } else {
                node* new_head = (node*)malloc(sizeof(node));
                new_head->data = s[i];
                new_head->next = head;
                head = new_head;
            }
            //if not left bracket, check for corresponding bracket
        } else { 
            if (head) { 
                if (s[i] == ref[1]) {
                    if (head->data != ref[0]) {
                        return 0;
                    } else {
                        #FREE HEAD
                        node* temp = head;
                        head = head->next;
                        free(temp);
                    }
                } else if (s[i] == ref[3]){
                    if (head->data != ref[2]) {
                        //printf("we got 2\n");
                        return 0;
                    } else {
                        #FREE HEAD
                        node* temp = head;
                        head = head->next;
                        free(temp);
                    }
                } else if (s[i] == ref[5]){
                   if (head->data != ref[4]) {
                     
                        return 0;
                    } else {
                        #FREE HEAD
                        node* temp = head;
                        head = head->next;
                        free(temp);
                    }
                }
            } else {
                #head is NULL - unmatched
                return 0;
            }        
        }
        i++;
    }
    if (head) {
        return 0;
    }
        
    return 1;
}