#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int pno;
    int pri;
    int btime;
    int wtime;
}sp;

int main()
{
    int i, j,n;
    int tbm = 0, totwtime=0, totttime=0;
    sp *p,t;
    printf("\n PRIORITY SCHEDULING\n");
    printf("\n enter the no of process...\n");
    scanf("%d",&n);
    p = (sp*)malloc(sizeof(sp));
    printf("enter the burst time and priority:\n");
    for(i=0;i<n;i++)
    {
        printf("process%d:",i+1);
        scanf("%d%d",&p[i].btime,&p[i].pri);
        p[i].pno= i+1;
        p[i].wtime=0;
    }
    for(i=0;i<n-1;i++)
    for(j=0;j<n-i-1;j++)
    {
        if(p[j].pri>p[j+1].pri)
        {
            t = p[j];
            p[j]=p[j+1];
            p[j+1] =t;
        }
    }
    printf("\n process\tbursttime\twaiting time\tturnaround time");
    for(i=0;i<n;i++)
    {
        totwtime+=p[i].wtime=tbm;
        tbm+=p[i].btime;
        printf("\n%d\t\t%d\t\t%d\t\t%d",p[i].pno,p[i].btime,p[i].wtime,p[i].wtime+p[i].btime);

    }
    totttime=tbm+totwtime;
    printf("\n total waiting time:%d",totwtime);
    printf("\n average waiting time:%f",(float)totwtime/n);
    printf("\n total turnaround time:%d",totttime);
    printf("\n avg turnaround time:%f",(float)totttime/n);


}