/////////////////////////////////////////////////////////////////////////////
//
//
// 1.prompt함수에서 입력받은 add m/d/a 는 받아져있다고 가정.
// 2.m 일때만 구현
// 3.add m 명령어입력시 프로그램 흐름을 보여준다.
// 4.영화목록을 하나추가하고 다음 링크드리스트로 연결되고 저장된것을 보여준다
//
//
//////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack{
  char str[100];
  struct stack *next;
};
struct movie{
  int serial_num;
  struct stack *next_tt; //title
  struct stack *next_g; // genre
  struct stack *next_d; //director
  int year; //year
  int runtime; //runtime
  struct stack *next_a; //actor
  struct movie *next;
};
int add(char *,char *,struct movie **);
int main()
{

  struct movie *movieHead = (struct movie *)malloc(sizeof(struct movie));
  struct movie *movieTmp;

  char * menu = (char *)malloc(30*sizeof(char));
  char * mda = (char *)malloc(30*sizeof(char));

  movieHead -> next_tt = (struct stack *)malloc(sizeof(struct stack));
  movieHead -> next_g = (struct stack *)malloc(sizeof(struct stack));
  movieHead -> next_d = (struct stack *)malloc(sizeof(struct stack));
  movieHead -> next_a = (struct stack *)malloc(sizeof(struct stack));

  *menu = 'a';
  *(menu+1) = 'd';
  *(menu+2) = 'd';
  *mda = 'm';

  strcpy(movieHead -> next_tt -> str, "test1\0");
  strcpy(movieHead -> next_g -> str , "test2\0");
  strcpy(movieHead -> next_d-> str , "test3\0");
  movieHead -> year = 2004;
  movieHead -> runtime = 124;
  strcpy(movieHead -> next_a -> str, "Lee3Mean\0");
  movieTmp = movieHead;

  add(menu,mda,&movieTmp);

  printf("%s   %s   %s   %d   %d   %s\n",movieHead -> next_tt -> str,movieHead -> next_g -> str,movieHead -> next_d -> str,movieHead -> year,movieHead -> runtime,movieHead -> next_a -> str);
  printf("%s   %s   %s   %d   %d   %s\n",movieTmp -> next_tt -> str,movieTmp -> next_g -> str,movieTmp -> next_d -> str,movieTmp -> year,movieTmp -> runtime,movieTmp -> next_a -> str);

  return 0;
}

int add(char *menu,char *mda,struct movie **movieTmp)
{
 struct movie *tmp = *movieTmp; // 늘 링크드리스트의 끝을 가리킴
 struct movie *tmp1 = *movieTmp;  // 링크드리스트를 다시돌면서 같은 목록을 찾아줌
 struct stack *tmp2; // actor의 링크드리스트를 돌면서 끝을가리킴
 char tmpActor[100];
 char *p; // strtok
 (*movieTmp) -> next = (struct movie *)malloc(sizeof(struct movie));
 *movieTmp = (*movieTmp) -> next;

  if (*(mda) =='m')
  {
  printf("title > ");
    (*movieTmp) -> next_tt = (struct stack *)malloc(sizeof(struct stack));
  scanf("%s", (*movieTmp) -> next_tt -> str);

  printf("genre > ");
    (*movieTmp) -> next_g = (struct stack *)malloc(sizeof(struct stack));
  scanf("%s",(*movieTmp) -> next_g -> str);

  printf("director > ");
    (*movieTmp) -> next_d = (struct stack *)malloc(sizeof(struct stack));
  scanf("%s",(*movieTmp) -> next_d -> str);

  printf("year > ");
  scanf("%d",& ((*movieTmp) -> year));

  printf("run time > ");
  scanf("%d",& ((*movieTmp) -> runtime));

  printf("actors > ");
    (*movieTmp) -> next_a = (struct stack *)malloc(sizeof(struct stack));
  scanf("%s",tmpActor);


//아직 완성안됨 actors>부분이 %[^\n]으로 받아야함
  p = strtok(tmpActor,",");
  if(p) {
    (*movieTmp) -> next_a = (struct stack *)malloc(sizeof(struct stack));
    tmp2 = (*movieTmp) -> next_a;
    strcpy(tmp2 -> str, p);
  }
  while (p!=NULL){
    p = strtok(NULL,",");
    if(p){
      tmp2 -> next = (struct stack *)malloc(sizeof(struct stack));
      tmp2 = tmp2 -> next;
      strcpy(tmp2 -> str, p);
    }
}
    //////////////겹치는 목록이 있는지 먼저 확인
  /*  if(겹친다면)
    {
      printf("@@");
    }
    */
}
  return 0;

}
