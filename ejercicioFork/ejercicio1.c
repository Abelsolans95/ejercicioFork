
#include <stdio.h>
#include <unistd.h>
main(void)
{
 pid_t pid;
 int x=5;
int y=10;
 

  
  pid=fork(); 
  if(pid)
  {
   printf("Soy el proceso %d\n",getpid());
	printf("abuelo. multiplicacion %d\n", x*y);
   sleep(2);
  }

  else
  {
   printf("soy el hijo %d, mi padre es %d\n",getpid(),getppid());
	printf("hijo. resta %d\n", x-y);
   sleep(2);
 
    pid=fork();
     if(pid)
     {/*
      printf("Soy el proceso %d\n",getpid());
printf("se va a crear el nieto");*/
		
      sleep(2);
     }
     else
     {
      printf("soy el hijo %d, mi padre es %d\n",getpid(),getppid());
	printf("nieto. suma %d: " ,x+y);
      sleep(2);
      exit(0);
     }
   }
   exit(0);
  
  
 return 0;
}