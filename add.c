int add(char *menu,char *mda,struct movie **movieTmp,struct actor **actorTmp,struct director **directorTmp )//  movieTmp는 늘 링크드리스트의 끝을 가리킴
{

 struct movie *tmp1 = *movieTmp;  // 링크드리스트를 다시돌면서 같은 목록을 찾아줌
 struct stack *tmp2; // actor의 링크드리스트를 돌면서 끝을가리킴
 char tmpActor[100];
 char *p; // strtok
 (*movieTmp) -> next = (struct movie *)malloc(sizeof(struct movie));
 *movieTmp = (*movieTmp) -> next;

 ////////////////////////////////////////////////////////////////////
 ////////////////////////////////////////////////////////////////////
  if (*(mda) =='m')
  {
  printf("title > ");
    (*movieTmp) -> title = (struct stack *)malloc(sizeof(struct stack));
  scanf("%s", (*movieTmp) -> title -> str);

  printf("genre > ");
    (*movieTmp) -> genre = (struct stack *)malloc(sizeof(struct stack));
  scanf("%s",(*movieTmp) -> genre -> str);

  printf("director > ");
    (*movieTmp) -> director = (struct stack *)malloc(sizeof(struct stack));
  scanf("%s",(*movieTmp) -> director -> str);

  printf("year > ");
    (*movieTmp) -> year = (struct stack *)malloc(sizeof(struct stack));
  scanf("%s",& ((*movieTmp) -> year -> str));

  printf("run time > ");
    (*movieTmp) -> time = (struct stack *)malloc(sizeof(struct stack));
  scanf("%s",& ((*movieTmp) -> time -> str));

  printf("actors > ");
    (*movieTmp) -> actors = (struct stack *)malloc(sizeof(struct stack));
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

  ////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////
  if (*(mda) =='d')
  {
  printf("name > ");
    (*movieTmp) -> name = (struct stack *)malloc(sizeof(struct stack));
  scanf("%s", (*movieTmp) -> name -> str);

  printf("sex > ");
    (*movieTmp) -> sex = (struct stack *)malloc(sizeof(struct stack));
  scanf("%s",(*movieTmp) -> sex -> str);

  printf("birth > ");
    (*movieTmp) -> birth = (struct stack *)malloc(sizeof(struct stack));
  scanf("%s",(*movieTmp) -> birth -> str);

  printf("best_movies > ");
    (*movieTmp) -> best_movies = (struct stack *)malloc(sizeof(struct stack));
  scanf("%s",tmpActor);


//아직 완성안됨 actors>부분이 %[^\n]으로 받아야함
  p = strtok(tmpActor,",");
  if(p) {
    (*movieTmp) -> best_movies = (struct stack *)malloc(sizeof(struct stack));
    tmp2 = (*movieTmp) -> best_movies;
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
////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////
  if (*(mda) =='a')
  {
  printf("title > ");
    (*movieTmp) -> title = (struct stack *)malloc(sizeof(struct stack));
  scanf("%s", (*movieTmp) -> title -> str);

  printf("genre > ");
    (*movieTmp) -> genre = (struct stack *)malloc(sizeof(struct stack));
  scanf("%s",(*movieTmp) -> genre -> str);

  printf("director > ");
    (*movieTmp) -> director = (struct stack *)malloc(sizeof(struct stack));
  scanf("%s",(*movieTmp) -> director -> str);

  printf("year > ");
    (*movieTmp) -> year = (struct stack *)malloc(sizeof(struct stack));
  scanf("%s",& ((*movieTmp) -> year -> str));

  printf("run time > ");
    (*movieTmp) -> time = (struct stack *)malloc(sizeof(struct stack));
  scanf("%s",& ((*movieTmp) -> time -> str));

  printf("actors > ");
    (*movieTmp) -> actors = (struct stack *)malloc(sizeof(struct stack));
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
