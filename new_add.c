#include "user.h"

//save 까지 해가서 합치기만 하면 일사천리 ㄹㅇ;
//prompt_add랑 add함수 따로 만들어서 다시 해보자.!!


int prompt_add(char *menu,char *mda)
{

  FILE *ifp = NULL;

  if( *menu == 'a' && *(menu + 1) == 'd' && *(menu + 2) == 'd' )
    if( *mda == 'm' )
    {
    char *title;
    char *genre;
    char *director;
    char *year;
    char *times;
    char *actors;

    title = (char *)malloc(sizeof(char));
    genre = (char *)malloc(sizeof(char));
    director = (char *)malloc(sizeof(char));
    year = (char *)malloc(sizeof(char));
    times = (char *)malloc(sizeof(char));
    actors = (char *)malloc(sizeof(char));

    printf("title > ");
    scanf("%s", title);
    getchar();
    printf("\ngenre > ");
    scanf("%s", genre);
    getchar();
    printf("\ndirector > ");
    scanf("%s", director);
    getchar();
    printf("\nyear > ");
    scanf("%s", year);
    getchar();
    printf("\ntime > ");
    scanf("%s", times);
    getchar();
    printf("\nactors > ");
    scanf("%[^\n]", actors);
    getchar();

    ifp = fopen("movie_log.txt","a");

    //serial_number 적용 함수 적용되지 않아서 임의로 이렇게 두었습니다.
    fprintf(ifp,"add:i:%s:%s:%s:%s:%s:%s\n",title,genre,director,year,times,actors);

    fclose(ifp);

    }

    if( *mda == 'd' )
    {
      char *name;
      char *sex;
      char *birth;
      char *best_movies;

      name = (char *)malloc(sizeof(char));
      sex = (char *)malloc(sizeof(char));
      birth = (char *)malloc(sizeof(char));
      best_movies= (char *)malloc(sizeof(char));

    printf("name > ");
    scanf("%s",name);
    getchar();
    printf("\nsex > ");
    scanf("%s",sex);
    getchar();
    printf("\nbirth > ");
    scanf("%s",birth);
    getchar();
    printf("\nbest_movies > ");
    scanf("%[^\n]",best_movies);
    getchar();

    ifp = fopen("director_log.txt","a");

    //serial_number 적용 함수 적용되지 않아서 임의로 이렇게 두었습니다.
    fprintf(ifp,"add:i:%s:%s:%s:%s\n",name,sex,birth,best_movies);

    fclose(ifp);


    }

    if( *mda == 'a' )
    {

      char *name;
      char *sex;
      char *birth;
      char *best_movies;

      name = (char *)malloc(sizeof(char));
      sex = (char *)malloc(sizeof(char));
      birth = (char *)malloc(sizeof(char));
      best_movies= (char *)malloc(sizeof(char));


      printf("name > ");
      scanf("%s",name);
      getchar();
      printf("\nsex > ");
      scanf("%s",sex);
      getchar();
      printf("\nbirth > ");
      scanf("%s",birth);
      getchar();
      printf("\nbest_movies > ");
      scanf("%[^\n]",best_movies);
      getchar();

      ifp = fopen("actor_log.txt","a");

      //serial_number 적용 함수 적용되지 않아서 임의로 이렇게 두었습니다.
      fprintf(ifp,"add:i:%s:%s:%s:%s\n",name,sex,birth,best_movies);

      fclose(ifp);

    }

}

//아래는 main함수 형식. (동적메모리 할당 필요.)
/*
int main(void)
{
  char *menu;
  char *mda;

  menu = (char *)malloc(sizeof(char));
  mda = (char *)malloc(sizeof(char));

  scanf("%s %s",menu,mda);
  prompt_add(menu,mda);
  return 0;
}
*/
