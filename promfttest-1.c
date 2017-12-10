#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define DEBURG printf("DD\n");
int prompt(char *,char *,char *,char *,char *);
int main()
{
  int i =0;
  char * menu = (char *)malloc(30*sizeof(char));
  char * mda = (char *)malloc(30*sizeof(char));
  char * option = (char *)malloc(30*sizeof(char));
  char * str = (char *)malloc(30*sizeof(char));
  char * num = (char *)malloc(30*sizeof(char));


while(1){  i = prompt(menu,mda,option,str,num);
//////////////printf()함수는 잘 저장됬는지 확인하는 용이니깐 지우면됨
///////
if(i == 7) printf("%d\n%s %s %s %s\n",i,menu,mda,option,str);
if(i == 6) printf("%d\n%s %s %s %s\n",i,menu,mda,option,str);
if(i == 5) printf("%d\n%s %s %d\n",i,menu,mda,atoi(num));
if(i == 4) printf("%d\n%s %s %s %d\n",i,menu,mda,option,atoi(num));
if(i == 3) printf("%d\n%s %s\n",i,menu,mda);
if(i == 2) printf("%d\n%s %s %d\n",i,menu,mda,atoi(num));
if(i == 1) printf("%d\n%s %s %s\n",i,menu,option,str);
////////////////////////////////////////////////////////////////
}
  return 0;
}
int prompt(char * menu, char *mda, char *option,char *str,char *num)
{
  char *tmp = (char *)malloc(30*sizeof(char));
  char *p; //strtok()를 쓰기위한 포인터

  *menu = *mda = *option = *str = *num = '\0';

  printf("(movie) ");
  gets(tmp);

  if(*(tmp)=='s')
  {
    if(*(tmp+1)=='e') //search
    {
      p = strtok(tmp," ");
      if(p) strcpy(menu, p);

      if(p!=NULL)
      {
        p = strtok(NULL," ");
        if(p) strcpy(option, p);
      }
      if(p==NULL)
      {
        strcpy(str,option);
        return 1;
      }
      if(p!=NULL)
      {
        p = strtok(NULL," ");
        if(p) strcpy(str, p);
      }
      return 1;

    }

    if(*(tmp+1)=='o') //sort
    {
      p = strtok(tmp," ");
      if(p) strcpy(menu, p);
      if(p!=NULL)
      {
        p = strtok(NULL," ");
        if(p) strcpy(mda, p);
      }
      if(p!=NULL)
      {
        p = strtok(NULL," ");
        if(*p != '-') strcpy(option, p);
        else if(*p == '-') if(*p){
          p = strtok(NULL," ");
          if(p) strcpy(str,p);
        }
      }
      if(p!=NULL)
      {
        DEBURG
        p = strtok(NULL," ");
        if(p) if(*p=='-')
        {
           p = strtok(NULL," ");
           if(p) strcpy(str, p);
        }
       }
       return 6;
      }
   if(*(tmp+1)=='a') //save
   {
     p = strtok(tmp," ");
     if(p) strcpy(menu, p);
     if(p!=NULL)
     {
       p = strtok(NULL," ");
       if(p) strcpy(mda, p);
     }
     if(p!=NULL)
     {
       p = strtok(NULL," ");
       if(p) {
         if(*p != '-') strcpy(option, p);
         else if(*p == '-') if(*p){
           p = strtok(NULL," ");
           if(p) strcpy(str,p);
         }
       }
     }
     if(p!=NULL)
     {
       p = strtok(NULL," ");
       if(p) if(*p=='-')
       {
          p = strtok(NULL," ");
          if(p) strcpy(str, p);
       }
      }
     return 7;
    }
  }
if(*(tmp)=='p')//  print
{
  p = strtok(tmp," ");
  if(p) strcpy(menu, p);
  if(p!=NULL)
  {
    p = strtok(NULL," ");
    if(p) strcpy(mda, p);
  }
  if(p!=NULL)
  {
    p = strtok(NULL," ");
    if(p) strcpy(num, p);
  }
  return 2;
}
if(*(tmp)=='a')  //add
{
  p = strtok(tmp," ");
  if(p) strcpy(menu, p);
  if(p!=NULL)
  {
    p = strtok(NULL," ");
    if(p) strcpy(mda, p);
  }
  if(p!=NULL)
  {
    p = strtok(NULL," ");
    if(p) strcpy(option, p);
  }
  if(p!=NULL)
  {
    p = strtok(NULL," ");
    if(p) strcpy(str, p);
  }
  return 3;
}
if(*(tmp)=='u')  //update
{
  p = strtok(tmp," ");
  if(p) strcpy(menu, p);
  if(p!=NULL)
  {
    p = strtok(NULL," ");
    if(p) strcpy(mda, p);
  }
  if(p!=NULL)
  {
    p = strtok(NULL," ");
    if(p) strcpy(option, p);
  }
/* if(p==NULL)
  {
    printf("DD");
    strcpy(num,option);
  }*/
  if(p!=NULL)
  {
    p = strtok(NULL," ");
    if(p) strcpy(num, p);
  }
  if(*num=='\0')
  {
    strcpy(num,option);
    *option = '\0';
  }
  return 4;
}
if(*(tmp)=='d')  //delete
{
  p = strtok(tmp," ");
  if(p) strcpy(menu, p);
  if(p!=NULL)
  {
    p = strtok(NULL," ");
    if(p) strcpy(mda, p);
  }
  if(p!=NULL)
  {
    p = strtok(NULL," ");
    if(p) strcpy(num, p);
  }
  return 5;
}
}
