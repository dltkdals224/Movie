#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int prompt(char *,char *,char *,char *,char *);
int main()
{
  int i =0;
  char * menu = (char *)malloc(30*sizeof(char));
  char * mda = (char *)malloc(30*sizeof(char));
  char * option = (char *)malloc(30*sizeof(char));
  char * str = (char *)malloc(30*sizeof(char));
  char * num = (char *)malloc(30*sizeof(char));

  i = prompt(menu,mda,option,str,num);

  printf("%d\n%s %s %s %s\n",i,menu,mda,option,str);

  return 0;
}
int prompt(char * menu, char *mda, char *option,char *str,char *num)
{
  char *tmp = (char *)malloc(30*sizeof(char));
  char *p;
  scanf("%[^\n]",tmp);

  if(*(tmp)=='s')
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
  }
        return 0;
      }
