/*************************************/
/* Author      :Munusamy M           */
/* Date        :22-01-2019           */
/* Filename    :receiver_p6.c        */
/* Description :collect all strings  */
/*             from p1,p2,p3,p4,p5   */
/*************************************/

#include "read.h"
int main()
{
	int shmid,fd;
	char *data_read;
	
	ssize_t ret_read;
	unsigned char str[100];
       
       	//shmget is a system call its used to create a new shared memory segment
	shmid=shmget(101,8192,IPC_CREAT |S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);
	
	//shmat attaching address is specified by shmaddr with one of the following criteria
	data_read=shmat(shmid,NULL,0);
	perror("shmat");
	
	//open is a system call 
	fd=open("./11.c",O_RDWR);
	
	//read is a system call 
        ret_read =read(fd,str,27);
	perror("read");
        
	//stcpy used to copy a string
          strcpy(data_read,str);
	
	//Detached location
	shmdt(data_read);
	perror("shmdt");

	close (fd);
	perror("close");
}
