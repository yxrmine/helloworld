/*
 * student.h
 *
 *  Created on: 2017年4月19日
 *      Author: Administrator
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*定义学生结构体*/

struct Student

{

     char ID[20];

     char Name[20];

     float Mark1;

     float Mark2;

     float Mark3;

     float Average;

};


float Avg(struct Student stu);          /*求平均值*/

int Student_SearchByIndex(char id[]);    /*通过学号返回数组下标*/

int Student_SearchByName(char name[]);  /*通过姓名返回数组下标*/

void Student_DisplaySingle(int index);  /*显示单条学生记录*/

void Student_Insert();              /*插入学生信息*/

void Student_Modify();                   /*修改学生信息*/

void Student_Delete();                   /*删除学生信息*/

void Student_Select();                   /*按姓名查询*/

void Student_SortByAverage();            /*按平均值排序*/

void Student_Display();                  /*显示学生信息*/

void IO_ReadInfo();                      /*将学生信息从文件读出*/

void IO_WriteInfo();                    /*将学生信息写入文件*/



#endif /* STUDENT_H_ */
