/*************************************/
/* Author      :Munusamy M           */
/* Date        :22-01-2019           */
/* Filename    :receiver_p6.c        */
/* Description :collect all strings  */
/*             from p1,p2,p3,p4,p5   */
/*************************************/

#include "write.h"
int main()
{
	int shmid,fd;
	char data[30];
	char *data_read;
	ssize_t ret_write;
        
        //   a new shared memory segment 
	shmid=shmget(101,8192,0);
	
	// attaches  the  System V shared memory segment
	data_read=shmat(shmid,NULL,0);
	perror("shmat");
        
	// it is used to copy a string 
	strcpy(data,data_read);
	perror("strcpy");

	printf("%s\n",data);

	//attaches  the  System V shared memory segment
	shmdt(data_read);
}
