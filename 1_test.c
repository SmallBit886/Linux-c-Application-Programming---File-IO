#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <error.h>
int main(void)
{
	int fd1,fd2,fd3 ;
	char buf[100]={0};
	int ret;
	fd1 = open("./1_test.txt",O_RDWR | O_CREAT);
	if(-1==fd1){
		perror("open error"); 	
		return 1;
	}
 	// else printf("open sccess");
  	fd2 = write(fd1,"hello world",11);
  	if(-1==fd2)
	{
		perror("write error");
		return 1;
	}
	ret = lseek(fd1,0,SEEK_SET);
	if(-1 == ret)
	{
		perror("lseek error");
		return 1;	
	}
	fd3 = read(fd1,buf,11);
	if(11>fd3)
	{
		perror("read error");
		return 1;
	}
	printf("%s\n",buf);
	close(fd1);
	return 0;
}

