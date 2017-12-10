#include"user.h"
void init_add(char *menu,char *mda,movie **movieTmp,actor **actorTmp, director **directorTmp)
{
  char * charTmp = (char *)calloc(100,sizeof(char));
  stack *stackTmp;
  char * p;

  if(*mda == 'm')
  {
    *movieTmp =(movie *)calloc(1,sizeof(movie));
    //입출력부분//
    printf("title > ");
    (*movieTmp) -> title = (stack *)calloc(1,sizeof(stack));
    (*movieTmp) -> title -> str = (char *)calloc(30,sizeof(char));
    scanf("%s",((*movieTmp) -> title -> str));

    printf("genre > ");
    (*movieTmp) -> genre = (stack *)calloc(1,sizeof(stack));
    (*movieTmp) -> genre -> str = (char *)calloc(30,sizeof(char));
    scanf("%s",((*movieTmp) -> genre -> str));

    printf("director > ");
    (*movieTmp) -> director = (stack *)calloc(1, sizeof(stack));
    (*movieTmp) -> director -> str = (char *)calloc(30,sizeof(char));
    scanf("%s",((*movieTmp) -> director -> str));

    printf("year > ");
    (*movieTmp) -> year = (stack *)calloc(1,sizeof(stack));
    (*movieTmp) -> year -> str = (char *)calloc(30,sizeof(char));
    scanf("%s",(*movieTmp) -> year -> str);

    printf("run time > ");
    (*movieTmp) -> time = (stack *)calloc(1,sizeof(stack));
    (*movieTmp) -> time -> str = (char *)calloc(30,sizeof(char));
    scanf("%s",(*movieTmp) -> time -> str);

    printf("actors > ");
    (*movieTmp) -> actors = (stack *)calloc(1,sizeof(stack));
    (*movieTmp) -> actors -> str = (char *)calloc(100,sizeof(char));
    getchar();
    scanf("%[^\n]",charTmp);
    getchar();

  //strtok로 인자나누는 부분//
  p = strtok(charTmp,",");
  if(p)
    stackTmp = (*movieTmp) -> actors;
    strcpy(stackTmp -> str, p);
  }

  while (p!=NULL){
    p = strtok(NULL,",");
    if(p){

      stackTmp -> next = (stack *)calloc(1,sizeof(stack));
      stackTmp -> next -> str = (char *)calloc(100,sizeof(char));
      stackTmp = stackTmp -> next;
      strcpy(stackTmp -> str, p);
    }
  }



  return ;
}
