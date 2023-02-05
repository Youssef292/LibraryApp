/**********************************************************************************************/
/***** Name: Youssef Abdelhakem          ********************************************************/
/***** Date: 6/2/2023                 ********************************************************/
/***** Component:  LinkedList.h  ********************************************************/
/**********************************************************************************************/
#ifndef LIBRARY_MANAGMENT_SYSTEM_LINKEDLIST_H
#define LIBRARY_MANAGMENT_SYSTEM_LINKEDLIST_H
#include <stdio.h>
#include <stdlib.h>
#include "Types.h"
/*Book Info*/
typedef struct Book {
    uint8_t Book_Name[20];
    uint8_t Auther[20];
    uint32_t  Book_price;

}Book_t;

/*LinkedList to store Book Data*/
struct Node {
    Book_t Book_info;
    struct Node *NextNode;

};

typedef enum {
    L_NOK = 0,
    L_OK,
    L_Empty
}Lib_stat;

Lib_stat ViewBooks(struct Node *Book);
Lib_stat AddBook(struct Node **Book);
Lib_stat  DeleteBook(struct Node* Book, uint32_t B_Id);
uint32_t Num_of_Books(struct Node* Book);
Lib_stat  DeleteBook_AtBeginning(struct Node** Book );
void lines(void);
void Menu(void);



#endif //LIBRARY_MANAGMENT_SYSTEM_LINKEDLIST_H
