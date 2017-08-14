#include <pthread.h>
#include<stdio.h>

pthread_mutex_t count_mutex;
int count;

void
increment_count()
{
	    pthread_mutex_lock(&count_mutex);
    count = count + 1;
    printf("\n First thread processing\n %d", count);
	    pthread_mutex_unlock(&count_mutex);
}

int
get_count()
{
    int c;
    
    pthread_mutex_lock(&count_mutex);
	    c = count;
	printf("\n second thread processing\n %d", c);
    pthread_mutex_unlock(&count_mutex);
	    return (c);
}

void main(){
increment_count();
int final=get_count();
printf("\n%d", final);

}
