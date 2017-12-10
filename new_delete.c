#include "user.h"

int delete(char *menu, char *mda, char *num)
{

  FILE *movie_log = NULL;
  FILE *director_log = NULL;
  FILE *actor_log = NULL;

if( *menu == 'd' && *(menu + 1) == 'e' && *(menu + 2) == 'l' && *(menu + 3) == 'e' && *(menu + 4) == 't' && *(menu + 5) == 'e')
{
  if( *mda == 'm' )
  {
    movie_log = fopen("movie_log.txt","a");

    fprintf(movie_log,"delete:%s:=:=:=:=:=:=\n", num );

    fclose(movie_log);
  }

  if( *mda == 'd' )
  {
    director_log = fopen("director_log.txt","a");

    fprintf(director_log,"delete:%s:=:=:=:=:=:=\n", num );

    fclose(director_log);
  }

  if( *mda == 'a' )
  {
    actor_log = fopen("actor_log.txt","a");

    fprintf(actor_log,"delete:%s:=:=:=:=:=:=\n", num );

    fclose(actor_log);
  }
}

}

/*아래는 main함수 형식. (동적메모리 할당 필요.)
int main(void)
{
  char *menu;
  char *mda;
  char *num;

  menu = (char *)malloc(sizeof(char));
  mda = (char *)malloc(sizeof(char));
  num = (char *)malloc(sizeof(char));

  scanf("%s %s %s",menu,mda,num);
  delete(menu,mda,num);
  return 0;
}
*/
