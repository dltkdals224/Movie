#include"user.h"
void print(char * mda,char * num,struct movie_list *movieHead,struct director_list *directorHead,struct actor_list *actorHead)
{
	struct movie_list *movieTmp = movieHead;
	struct movie_to_actor *mtoaTmp;
	struct director_list *directorTmp = directorHead;
	struct d_title_to_title * dtotTmp;
	struct actor_list *actorTmp = actorHead;
	struct a_title_to_title *atotTmp;
//확인용//
	printf("옵션 , 숫자 쳐\n");
	scanf("%s %s",mda,num);

if(*mda == 'm')
{
	{
		if(movieTmp !=NULL)
		{
			while(atoi(num) != movieTmp -> serial_num)
			{
				if(movieTmp -> next == NULL)
				{
					printf("There is no %d\n",num);
					return ;
				}
				movieTmp = movieTmp -> next;
			}
			if(atoi(num) == movieTmp -> serial_num) mtoaTmp = movieTmp -> actors;
		}

					//////////////////////
		printf("(m)\n");
	printf("%d, %s, %s\n",movieTmp -> serial_num,movieTmp -> title -> str,movieTmp -> genre -> str);
	printf("D : %s(%s)\n",movieTmp -> director -> str, movieTmp -> director ->pair -> birth -> str);
		if(mtoaTmp != NULL)
		{
			int i=1;
			while(mtoaTmp -> next != NULL)
			{
					  printf("A%d : %s(%s)\n",i++,mtoaTmp -> str, mtoaTmp -> pair -> birth -> str);
						mtoaTmp = mtoaTmp -> next;
			}
		}
	}
}
if(*mda == 'd')
{
	{
		if(directorTmp !=NULL)
		{
			while(atoi(num) != directorTmp -> serial_num)
			{
				if(directorTmp -> next == NULL)
				{
					printf("There is no %d\n",num);
					return ;
				}
				directorTmp = directorTmp -> next;
			}
			if(atoi(num) == directorTmp -> serial_num) dtotTmp = directorTmp -> best_movies;
		}

					//////////////////////
		printf("(d)\n");
	printf("%d, %s, %s, %s\n",directorTmp->serial_num,directorTmp->name->str,directorTmp->sex->str,directorTmp->birth->str);
		if(dtotTmp != NULL)
		{
			while(dtotTmp -> next != NULL)
			{
					  printf("%s %syear %sminutes)\n",dtotTmp -> str, dtotTmp -> title -> year,dtotTmp -> title -> time);
						dtotTmp = dtotTmp -> next;
			}
		}
	}
}
if(*mda == 'a')
{
	{
		if(actorTmp !=NULL)
		{
			while(atoi(num) != actorTmp -> serial_num)
			{
				if(actorTmp -> next == NULL)
				{
					printf("There is no %d\n",num);
					return ;
				}
				actorTmp = actorTmp -> next;
			}
			if(atoi(num) == actorTmp -> serial_num) atotTmp = actorTmp -> best_movies;
		}

					//////////////////////
		printf("(a)\n");
	printf("%d, %s, %s, %s\n",actorTmp->serial_num,actorTmp->name->str,actorTmp->sex->str,actorTmp->birth->str);
		if(atotTmp != NULL)
		{
			while(dtotTmp -> next != NULL)
			{
					  printf("%s %syear %sminutes)\n",atotTmp -> str, atotTmp -> title -> year,atotTmp -> title -> time);
						atotTmp = atotTmp -> next;
			}
		}
	}
}
return ;
}
