/*
 ============================================================================
 Name        : xuesheng.c
 Author      : yxr
 Version     :
 Copyright   : 第一个真正的程序
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "student.h"

int main()

{
     int choice;

     IO_ReadInfo();

     while(1)
     {
         /*主菜单*/

         printf("\n------ 学生成绩管理系统------\n");
         printf("1. 增加学生记录\n");
         printf("2. 修改学生记录\n");
         printf("3. 删除学生记录\n");
         printf("4. 按姓名查询学生记录\n");
         printf("5. 按平均成绩排序\n");
         printf("6. 退出\n");
         printf("请选择(1-6):");
         scanf("%d",&choice);
         getchar();

         switch(choice)
         {
            case 1:
              Student_Insert();
              break;

            case 2:
              Student_Modify();
              break;

            case 3:
              Student_Delete();
              break;

            case 4:
              Student_Select();
              break;

            case 5:
              Student_SortByAverage();
              Student_Display();
              break;

            case 6:
              exit(0);
              break;
         }

      IO_WriteInfo();

     }
     return 0;
}
