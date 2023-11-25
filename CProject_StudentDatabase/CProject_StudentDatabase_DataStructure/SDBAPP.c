#include"SDB.h"
student *ListHead = NULL; /* A linked list is represented by a pointer to the first node of the linked list (ListHead) */
 void SDB_APP ()
 {
     uint8 x;
     while(1){
        /* The Main Menu in which user will exit from it when entering 0*/
        printf("\nChoose an option:\n");
        printf("1. To add entry, enter 1\n");
        printf("2. To get used size in database, enter 2\n");
        printf("3. To read student data, enter 3\n");
        printf("4. To get the list of all student IDs, enter 4\n");
        printf("5. To check if ID exists, enter 5 \n");
        printf("6. To delete student data, enter 6\n");
        printf("7. To check if database is full, enter 7\n");
        printf("8. To exit enter 0\n");
        printf("\n");
        printf("Enter Operation Number here: ");
        scanf("%d",&x);       //Entering the Operation Number
        printf("\n");
        SDB_action (x);
     }
 }

 /** SDB_action function will take the user option to do the operation needed in which will
  call certain function depending on the user's input*/
 void SDB_action (uint8 x)
 {   uint32 id;
     switch(x){
         case 1:
            if(SDB_IsFull(ListHead)== false)    /* Checks if the User entered the maximum number of students allowed (10)
                                                                      if not it allows the user to add another student to the database */
             {
                 SDB_AddEntry(&ListHead);     /*NOTE: here we add the dereferencing operator because we will want to change
                                                    the ListHead content so we pass it by reference*/
             }
             else
             {
                printf("DataBase is FULL!!\n");

             }
            break;
         case 2:
           printf("Number of Students added are: %d\n\n",SDB_GetUsedSize(ListHead));     //Gets number of students added to the database
             break;
         case 3:
             printf("Enter ID: ");     // Gets the ID of the student that the user wants to know his details
             scanf("%d",&id);

            if(SDB_ReadEntry(ListHead, id)==false)
            {

                printf("Student with ID %d not found.\n", id);
            }
            break;
         case 4:
            SDB_GetList(ListHead);         //Show a List of the Ids of the students added to the database
            break;
         case 5:
             printf("Enter ID: ");
             scanf("%d",&id);
            if(SDB_IsIdExist(ListHead,id)==true)       //Checks if a student with this id exists
            {
                printf("Student with this ID EXISTS!!\n\n");
            }
            else
            {
                printf("Student with this ID DONT EXIST!!\n\n");
            }
            break;
         case 6:
             printf("Enter ID: ");         // Gets the ID of the student that the user wants to remove from the database
             scanf("%d",&id);
             SDB_DeletEntry(&ListHead,id);
            break;
         case 7:
            if(SDB_IsFull(ListHead)==true)             /* Checks if the database if full or not (has 10 students)*/
            {
                printf("Database is FULL!!\n\n");
            }
            else
            {
                printf("Database is NOT FULL!!\n\n");
            }

            break;
         case 0:
              printf("Quit from application \n");
                exit(1);
             break;
         default:
                printf("User Choice out of range, Try Again !!\n\n");
            break;

 }

 }
