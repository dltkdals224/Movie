#include "user.h"

int delete(char *menu, char *mda, char *num)
{

  FILE *ifp = NULL;

if( *menu == 'd' && *(menu + 1) == 'e' && *(menu + 2) == 'l' && *(menu + 3) == 'e' && *(menu + 4) == 't' && *(menu + 5) == 'e')
{
  if( *mda == 'm' )
  {
    ifp = fopen("movie_log.txt","a");

    fprintf(ifp,"delete:%s:=:=:=:=:=:=\n", num );

    fclose(ifp);
  }

  if( *mda == 'd' )
  {
    ifp = fopen("director_log.txt","a");

    fprintf(ifp,"delete:%s:=:=:=:=:=:=\n", num );

    fclose(ifp);
  }

  if( *mda == 'a' )
  {
    ifp = fopen("actor_log.txt","a");

    fprintf(ifp,"delete:%s:=:=:=:=:=:=\n", num );

    fclose(ifp);
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
