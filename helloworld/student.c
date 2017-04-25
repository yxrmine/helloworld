/*
 * student.c
 *
 *  Created on: 2017年4月19日
 *      Author: Administrator
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"


 /*声明学生数组及学生数量*/
struct Student students[1000];
int num=0;

/*求平均值*/

float Avg(struct Student stu)
{
     return (stu.Mark1+stu.Mark2+stu.Mark3)/3;
}


/*通过学号返回数组下标*/

int Student_SearchByIndex(char id[])
{
     int i;

     for (i=0;i<num;i++)
     {
         if (strcmp(students[i].ID,id)==0)
         {
              return i;
         }
     }
     return -1;
}


/*通过姓名返回数组下标*/

int Student_SearchByName(char name[])
{
     int i;

     for (i=0;i<num;i++)
     {
         if (strcmp(students[i].Name,name)==0)
         {
              return i;
         }
     }

     return -1;

}



/*显示单条学生记录*/

void Student_DisplaySingle(int index)

{
     printf("%10s%10s%8s%8s%8s%10s\n","学号","姓名","成绩","成绩","成绩","平均成绩");
     printf("-------------------------------------------------------------\n");
     printf("%10s%10s%8.2f%8.2f%8.2f%10.2f\n",students[index].ID,students[index].Name,
              students[index].Mark1,students[index].Mark2,students[index].Mark3,students[index].Average);
}


/*插入学生信息*/

void Student_Insert()
{
     while(1)
     {
         printf("请输入学号:");
         scanf("%s",students[num].ID);
         getchar();

         printf("请输入姓名:");
         scanf("%s",students[num].Name);
         getchar();

         printf("请输入成绩:");
         scanf("%f",&students[num].Mark1);
         getchar();

         printf("请输入成绩:");
         scanf("%f",&students[num].Mark2);
         getchar();

         printf("请输入成绩:");
         scanf("%f",&students[num].Mark3);
         getchar();

         students[num].Average=Avg(students[num]);
         num++;

         printf("是否继续?(y/n)");

         if (getchar()=='n')
         {
              break;
         }
     }
}



/*修改学生信息*/

void Student_Modify()
{
     //float mark1,mark2,mark3;

     while(1)
     {
         char id[20];
         int index;

         printf("请输入要修改的学生的学号:");
         scanf("%s",id);
         getchar();

         index=Student_SearchByIndex(id);
         if (index==-1)
         {
              printf("学生不存在!\n");
         }

         else
         {
              printf("你要修改的学生信息为:\n");
              Student_DisplaySingle(index);
              printf("-- 请输入新值--\n");
              printf("请输入学号:");
              scanf("%s",students[index].ID);
              getchar();

              printf("请输入姓名:");
              scanf("%s",students[index].Name);
              getchar();

              printf("请输入成绩:");
              scanf("%f",&students[index].Mark1);
              getchar();

              printf("请输入成绩:");
              scanf("%f",&students[index].Mark2);
              getchar();

              printf("请输入成绩:");
              scanf("%f",&students[index].Mark3);
              getchar();

              students[index].Average=Avg(students[index]);
         }

         printf("是否继续?(y/n)");
         if (getchar()=='n')
         {
              break;
         }
     }
}


/*删除学生信息*/

void Student_Delete()
{
     int i;
     while(1)
     {
         char id[20];
         int index;

         printf("请输入要删除的学生的学号:");
         scanf("%s",id);
         getchar();

         index=Student_SearchByIndex(id);
         if (index==-1)
         {
              printf("学生不存在!\n");
         }
         else
         {
              printf("你要删除的学生信息为:\n");
              Student_DisplaySingle(index);

              printf("是否真的要删除?(y/n)");
              if (getchar()=='y')
              {
                   for (i=index;i<num-1;i++)
                   {
                       students[i]=students[i+1];//把后边的对象都向前移动
                   }
                   num--;
              }
              getchar();
         }

         printf("是否继续?(y/n)");
         if (getchar()=='n')
         {
              break;
         }
     }
}


/*按姓名查询*/

void Student_Select()
{
     while(1)
     {
         char name[20];
         int index;

         printf("请输入要查询的学生的姓名:");
         scanf("%s",name);
         getchar();

         index=Student_SearchByName(name);
         if (index==-1)
         {
              printf("学生不存在!\n");
         }
         else
         {
              printf("你要查询的学生信息为:\n");
              Student_DisplaySingle(index);
         }

         printf("是否继续?(y/n)");
         if (getchar()=='n')
         {
              break;
         }
     }
}


/*按平均值排序*/

void Student_SortByAverage()
{
     int i,j;
     struct Student tmp;

     for (i=0;i<num;i++)
     {
         for (j=1;j<num-i;j++)
         {
              if (students[j-1].Average<students[j].Average)
              {
                   tmp=students[j-1];
                   students[j-1]=students[j];
                   students[j]=tmp;
              }
         }
     }
}


/*显示学生信息*/

void Student_Display()
{
     int i;

     printf("%10s%10s%8s%8s%8s%10s\n","学号","姓名","成绩","成绩","成绩","平均成绩");
     printf("-------------------------------------------------------------\n");

     for (i=0;i<num;i++)
     {
         printf("%10s%10s%8.2f%8.2f%8.2f%10.2f\n",students[i].ID,students[i].Name,
              students[i].Mark1,students[i].Mark2,students[i].Mark3,students[i].Average);
     }
}


/*将学生信息从文件读出*/

void IO_ReadInfo()
{
     FILE *fp;
     int i;

     if ((fp=fopen("Database.txt","rb"))==NULL)
     {
         printf("不能打开文件!\n");
         return;
     }

     if (fread(&num,sizeof(int),1,fp)!=1)
     {
         num=-1;
     }

     else
     {
         for(i=0;i<num;i++)
         {
              fread(&students[i],sizeof(struct Student),1,fp);
         }
     }
     fclose(fp);
}


/*将学生信息写入文件*/

void IO_WriteInfo()
{
     FILE *fp;
     int i;

     if ((fp=fopen("Database.txt","wb"))==NULL)
     {
         printf("不能打开文件!\n");
         return;
     }

     if (fwrite(&num,sizeof(int),1,fp)!=1)
     {
         printf("写入文件错误!\n");
     }

     for (i=0;i<num;i++)
     {
         if (fwrite(&students[i],sizeof(struct Student),1,fp)!=1)
         {
              printf("写入文件错误!\n");
         }
     }
     fclose(fp);
}
