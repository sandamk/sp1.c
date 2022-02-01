#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct keys{
    char keyword[25];
    int count;
};
//initializing the table
void init_table(struct keys *s, int n)
{
    for (int i =0;i<n-1;i++)
    {
        (s+i)->count = 0;
        strcpy((s+i)->keyword," ");
    }
}
//incremeting the count
void update_table(struct keys *s, int n)
{
    (s+n)->count++;
}
//Displaying the table
void display_table(struct keys *s, int n)
{
    for (int i = 0; i < n-1; i++)
    printf ("Name: %s\t count:%d\n", (s + i)->keyword, (s + i)->count);
}
int main(int argc, char* argv[])
{
    struct keys *ptr;
    char *str=NULL;
    char *split;
    ptr = (struct keys *) malloc (argc * sizeof (struct keys));
    init_table(ptr,argc); //intialize the keywords and counts

    for (int i =1; i< argc; i++){
        printf("%s\n",argv[i]);
        strcpy((ptr+(i-1))->keyword,argv[i]);
    }
  char *line = NULL;
  size_t maxlen = 0;
  ssize_t t;

  /* read the user input using the getlin() until the NULL is found  */
  while ((t = getline (&line, &maxlen, stdin)) > 0)
    {
        split = strtok (line, " "); //Split the word whenever a space is encountered
    while (split != NULL)
    {
      for (int i = 0; i < argc-1; i++)
	{
    /*Comparing the split word with the keywords and if a match is found, increment the corresponding count */
	  if (strcmp (split, (ptr + i)->keyword) == 0)
	    {
	      update_table(ptr,i);
	    }
	}
      split = strtok (NULL, " ,.\n");
    }
    }
    display_table(ptr,argc); //Display the keywords and counts
    free (line);
    return 0;
}
