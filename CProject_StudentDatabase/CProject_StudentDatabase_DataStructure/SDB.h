#ifndef __SDB_H__
#define __SDB_H__
#include"STD.h"
#include<stdio.h>
#include <stdlib.h>
typedef struct SimpleDb{

 uint32 Student_ID;
 uint32 Student_year;
 uint32 Course1_ID;
 uint32 Course1_grade;
 uint32 Course2_ID;
 uint32 Course2_grade;
 uint32 Course3_ID;
 uint32 Course3_grade;
 struct student* next;

}student;

bool SDB_IsFull (student *List);
uint8 SDB_GetUsedSize(student *List);
bool SDB_AddEntry(student **head);
void SDB_DeletEntry ( student **List,uint32 id);
bool SDB_ReadEntry (student* List, int id);
void SDB_GetList (student *head);
bool SDB_IsIdExist (student* List,uint32 id);
void SDB_APP ();
void SDB_action (uint8 choice);

#endif // __SDB_H__
