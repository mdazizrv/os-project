#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>


int main()
{
    int  i,file_descriptor[2], n;
    pid_t child;
    char str[20];
    char buffer[20];

    printf("\n\n Enter a string input : ");
    fgets(str,20,stdin);

    pipe(file_descriptor);

    child=fork();


    if(child == -1)
    {
        perror("\n\n child process not created");
        exit(1);
    }
    else if(child == 0)
    {
        close(file_descriptor[0]);
        write(file_descriptor[1], str, (strlen(str)+1));
        exit(0);
    }
    else
    {
        close(file_descriptor[1]);

        n = read(file_descriptor[0], buffer, sizeof(buffer));

        printf("input string: %s", buffer);

        for(i=0;i<sizeof(buffer)-1;i++)
        {
            if(buffer[i]>64 && buffer[i]<91)
                buffer[i]+=32;
            else if(buffer[i]>96 && buffer[i]<123)
                buffer[i]-=32;
            else
                buffer[i]=buffer[i];
		}

	    printf("output string: %s",buffer);
    }

	return(0);
}
