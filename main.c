#include"user.h"
int main()
{
	char *menu = "add";
	char *mda = "m";
	movie *movieTmp;
  movie *movieHead = NULL;
	actor *actorHead;
	director *directorHead;

	int checkSame = 0;

movieTmp = movieHead;

while(1){
  int i=1;
  if(movieHead ==NULL)
  {
    init_add(menu,mda,&movieHead,&actorHead,&directorHead);
    justprint(movieHead,i);
  }
	checkSame = add(menu,mda,movieHead,actorHead,directorHead);
	if(checkSame == 0) justprint(movieHead,i);
}

	return 0;
}
