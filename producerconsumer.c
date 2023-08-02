#include <stdio.h>
#include <stdlib.h>
int mutex =1, full =0 , empty =3, x =0;
int main()
{
    void producer();
    void consumer();
    
    while(1){
    printf("1.Producer \n2.Consumer\n");
    int c;
    scanf("%d",&c);
    switch (c)
    {
    case 1:
        /* code */
        if((mutex==1)&&(empty!=0))
        {
            producer();
        }
        else{
            printf("\nBuffer is FULL\n");
        }
        break;
    
    case 2:
        if((mutex==1)&&(full!=0))
        {
            consumer();
        }
        else
        {
            printf("\nBuffer is empty\n");
        }
        break;
    }}

}
int wait(int s)
{
    return(--s);
}
int signal(int s)
{
    return(++s);
}

void producer()
{
    mutex = wait(mutex);
    full = signal(full);
    empty = wait(empty);
    x++;
    printf("\nproducer produces item %d\n",x);
    mutex = signal(mutex);
}
void consumer()
{
    mutex = wait(mutex);
    full = wait(full);
    empty = signal(empty);
    printf("\nconsumer consumes item %d\n",x);
    x--;
    mutex = signal(mutex);
}