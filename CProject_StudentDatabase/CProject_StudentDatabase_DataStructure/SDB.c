#include"SDB.h"
#define Max_Students_Number 10

/**SDB_IsFull function
Checks if the database is full or not */
bool SDB_IsFull (student *List )   // We don't need here to modify the head of the linked list so we pass it as a copy
{
    student *TempNode=List;   //Initialize a pointer to the struct student with the list of the students
    uint32 NodeCount=0;         //Counter to all the nodes in the database
    while(TempNode!=NULL)
    {
        NodeCount++;
        TempNode=TempNode->next;
    }
    if(NodeCount==Max_Students_Number)      //Checks if the counter is equal to 10 students then the database is full
    {
        return true;
    }
    else
    {
        return false;
    }
}
/**SDB_GetUsedSize function
Prints Number of students added in the database */
uint8 SDB_GetUsedSize(student *List)        // We don't need here to modify the head of the linked list so we pass it as a copy
{
    student *TempNode=List;                  //Initialize a pointer to the struct student with the list of the students
    uint32 NodeCount=0;
    while(TempNode!=NULL)
    {
        NodeCount++;                  //Checks if we didn't reach the end of the database then increment the counter
        TempNode=TempNode->next;      // Traversing through the database by setting the pointer to the node after
    }

return NodeCount;

}
/**SDB_AddEntry function
Adds a student to the database and returns true if the data is added succesfully */
bool SDB_AddEntry(student **List)  /* To Pass a linked list to a function which will
                                    change the (Linked List Head) we need to pass it by reference ( Double Pointer in this case) */
{
    printf("Add New Student info\n");           //Prints the number of the student to be added

    student* newStudent = (student*)malloc(sizeof(student));        //Allocate memory to the pointer (new student to be added)

   if(NULL!=newStudent)    //Checks if memory allocating was successfull
    {
        /*Asks for the Student Id, Courses Id and Courses Grades
         and checks if the entered values are valid numbers*/
            printf("\nEnter ID: ");
            if (scanf("%d", &newStudent->Student_ID) != 1) {
            printf("\nInvalid input for student ID.\n\n");
            while (getchar() != '\n'); // Clear input buffer
            free(newStudent);
            return false;
            }
            printf("\nEnter StudentYear: ");
            if (scanf("%d", &newStudent->Student_year) != 1) {
            printf("\nInvalid input for student ID.\n\n");
            while (getchar() != '\n'); // Clear input buffer
            free(newStudent);
            return false;
            }

            printf("Enter Course_1 ID: ");
            if (scanf("%d", &newStudent->Course1_ID) != 1) {
            printf("\nInvalid input for Course1_ID.\n\n");
            while (getchar() != '\n'); // Clear input buffer
            free(newStudent);
            return false;
            }
            printf("Enter Course_1 Grade: ");
            if (scanf("%d", &newStudent->Course1_grade) != 1) {
            printf("\nInvalid input for Course1_Grade.\n\n");
            while (getchar() != '\n'); // Clear input buffer
            free(newStudent);
            return false;
            }
            printf("Enter Course_2 ID: ");
            if (scanf("%d", &newStudent->Course2_ID) != 1) {
            printf("\nInvalid input for Course2_ID.\n\n");
            while (getchar() != '\n'); // Clear input buffer
            free(newStudent);
            return false;
            }
            printf("Enter Course_2 Grade: ");
            if (scanf("%d", &newStudent->Course2_grade) != 1) {
            printf("\nInvalid input for Course2_Grade.\n\n");
            while (getchar() != '\n'); // Clear input buffer
            free(newStudent);
            return false;
            }



            if(NULL == *List){              /* Linked list is empty */
            newStudent->next = NULL;
            *List = newStudent;
            }
            else{                           /* Linked list is not empty */
            newStudent->next = *List;
            *List = newStudent;
            }

            printf("\nStudent added successfully.\n\n");
            return true;

        }
      else
        {
            printf("\nError Allocating Memory please try again!!\n ");
        }

}

/**SDB_DeletEntry function
Deletes the student with the id that the user entered */
void SDB_DeletEntry (student **List,uint32 id)/* To Pass a linked list to a function which will
                                                 change the (Linked List Head) we need to pass it by reference ( Double Pointer in this case) */
{
    student* current = *List;
    student* previous = NULL;

    // Traverse the linked list to find the student with the given ID
    while (current != NULL && current->Student_ID != id) {
        previous = current;
        current = current->next;
    }

    // If the student is found, delete it from the linked list
    if (current != NULL) {
        // If the student is the head of the linked list
        if (previous == NULL) {
            *List = current->next;
        } else {
            previous->next = current->next;        //Connecting nodes after deleting
        }

        free(current);       //Free the memory allocated

        printf("Student with ID %d has been deleted.\n\n", id);
    } else {
        printf("Student with ID %d was not found.\n\n", id);
    }

}

/**SDB_ReadEntry function
Reades the student data the id that the user entered */
bool SDB_ReadEntry(student* List, int id)
{
    student* current = List;
    int found = 0;

    while (current != NULL) {
        if (current->Student_ID == id) {
            found = 1;
            printf("ID: %d\n", current->Student_ID);
             printf("StudentYear: %d\n", current->Student_year);
            printf("Course_1 ID: %d\n",current->Course1_ID);
            printf("Course_1 Grade: %d\n", current->Course1_grade);
            printf("Course_2 ID: %d\n",current->Course2_ID);
            printf("Course_2 Grade: %d\n", current->Course2_grade);
            break;
        }
        current = current->next;
    }

    if (!found) {

        return false;
    }
    else
    {
        return true;
    }

}

/**SDB_GetList function
Prints a list of the added students ids */
void SDB_GetList (student* List)
{
    student *TempNode = List;
    if(NULL == TempNode){
        printf("List is empty !! \n");
    }
    else{
            printf("\nStudent IDs:\n\n");
        while(TempNode != NULL){
            printf("ID: %d\t\t", TempNode->Student_ID);

             TempNode = TempNode->next;

        }
    }

}

/**SDB_IsIdExist function
Checks if the id entered by the user exists or not */
bool SDB_IsIdExist (student* List,uint32 id)
{
    student* TempNode = List;
    bool found ;

    while (TempNode != NULL) {
        if (TempNode->Student_ID == id) {
            found = true;

            break;
        }
        else
        {
            found=false;
        }
        TempNode = TempNode->next;
    }

return found;

}
