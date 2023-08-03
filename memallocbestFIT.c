#include<stdio.h>
int msize[100],psize[100],m,n;
int main()
{
    //void bestFIT(int p_size,int m_size, int n, int m);
    int p_size[100],m_size[100],i;
    printf("enter the number of processes - ");
    scanf("%d",&n);
    printf("enter the process required mem");
    for(i=0;i<n;i++)
    {
        scanf("%d",&p_size[i]);
    }
    printf("enter the number of memory blocks - ");
    scanf("%d",&m);
    printf("enter the array of mem");
    for(i=0;i<m;i++)
    {
        scanf("%d",&m_size[i]);
    }
    bestFIT(p_size,m_size,n,m);


}

void bestFIT(int p_size[],int m_size[],int n,int m)
{ int temp,i,j,flag=0;
    //void sort(int msize[]);
    for(i=0;i<n;i++)
    {
        psize[i]= p_size[i];
    }
    for(i=0;i<m;i++)
    {
        msize[i]= m_size[i];
    }
    sort(msize);
    for(i=0;i<n;i++)
    {flag=0;
       for(j=0;j<m;j++)
       {
         
         if(msize[j]>=psize[i])
        {
            printf("%d is allocated in memory %d\n",psize[i],msize[j]);
            msize[j] = msize[j] - psize[i];
            sort(msize);
            flag = 1;
            break;
        }
       }
       if(flag==0)
       {
            printf("%d cant be allocted\n",psize[i]);
       }
        
    }
}

int sort(int msize[])
{   int temp;
    for(int i=0;i<m-1;i++)
    {
        for(int j=0;j<m-i-1;j++)
        {
            if(msize[j+1]<msize[j])
            {
                temp = msize[j];
                msize[j] = msize[j+1];
                msize[j+1] =temp;
            }
        }
    }
}