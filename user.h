/*사용자 헤더파일 (std종류, 구조체, 함수원형)
적용 방식 : 다른 기존파일에 #include "user.h" 해주면 된다! */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAN 0
#define FEMALE 1

#ifndef _USER_H_
#define _USER_H_ // _USER_H_가 정의되어 있지 않을 때 정의되도록.

struct stack{
  char *str; //string(문장) 저장
  struct stack *next; //링크드 리스트를 위해 존재.
};

struct director_struct{
  int Serial_number;
  struct stack *name;
  struct stack *sex;
  struct stack *birth;
  struct stack *best_movies;
  struct stack *next;
};

struct actor_struct{
  int Serial_numer;
  struct stack *name;
  struct stack *sex;
  struct stack *birth;
  struct stack *best_movies;
  struct stack *next;
};

struct movie_struct{
  int Serial_numer;
  struct stack *title;
  struct stack *genre;
  struct stack *director;
  struct stack *year;
  struct stack *time;
  struct stack *actors;
  struct stack *next;
};

//단순화 시킨 것.
typedef struct director_struct director;
typedef struct actor_struct actor;
typedef struct movie_struct movie;

//링크드 리스트 사용할때 쓸 것.
typedef struct stack tmp;
typedef tmp *LINK;

#endif // _USER_H_

//이 뒤로는 함수 선언문 작성.
