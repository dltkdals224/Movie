int prompt(char * menu, char *mda, char *option,char *str,char *num)
{
  char *tmp = (char *)malloc(30*sizeof(char));
  char *p; //strtok()를 쓰기위한 포인터

  *menu = *mda = *option = *str = *num = '\0';

  printf("(movie) ");
  gets(tmp);

  if(*(tmp)=='s')
  {
    if(*(tmp+1)=='e') //search
    {
      p = strtok(tmp," ");
      if(p) strcpy(menu, p);

      if(p!=NULL)
      {
        p = strtok(NULL," ");
        if(p) strcpy(option, p);
      }
      if(p==NULL)
      {
        strcpy(str,option);
        return 1;
      }
      if(p!=NULL)
      {
        p = strtok(NULL," ");
        if(p) strcpy(str, p);
      }
      return 1;

    }

    if(*(tmp+1)=='o') //sort
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
        if(*p != '-') strcpy(option, p);
        else if(*p == '-') if(*p){
          p = strtok(NULL," ");
          if(p) strcpy(str,p);
        }
      }
      if(p!=NULL)
      {
        DEBURG
        p = strtok(NULL," ");
        if(p) if(*p=='-')
        {
           p = strtok(NULL," ");
           if(p) strcpy(str, p);
        }
       }
       return 6;
      }
   if(*(tmp+1)=='a') //save
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
       if(*p != '-') strcpy(option, p);
       else if(*p == '-') if(*p){
         p = strtok(NULL," ");
         if(p) strcpy(str,p);
       }
     }
     if(p!=NULL)
     {
       DEBURG
       p = strtok(NULL," ");
       if(p) if(*p=='-')
       {
          p = strtok(NULL," ");
          if(p) strcpy(str, p);
       }
      }
     return 7;
    }
  }
if(*(tmp)=='p')//  print
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
    if(p) strcpy(num, p);
  }
  return 2;
}
if(*(tmp)=='a')  //add
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
  return 3;
}
if(*(tmp)=='u')  //update
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
/* if(p==NULL)
  {
    printf("DD");
    strcpy(num,option);
  }*/
  if(p!=NULL)
  {
    p = strtok(NULL," ");
    if(p) strcpy(num, p);
  }
  if(*num=='\0')
  {
    strcpy(num,option);
    *option = '\0';
  }
  return 4;
}
if(*(tmp)=='d')  //delete
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
    if(p) strcpy(num, p);
  }
  return 5;
}
}
