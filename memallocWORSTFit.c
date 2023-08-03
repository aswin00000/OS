#include<stdio.h>
int msize[100],psize[100],m,n;
int main()
{
    //void worstfit(int p_size,int m_size, int n, int m);
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
    worstfit(p_size,m_size,n,m);


}

void worstfit(int p_size[],int m_size[],int n,int m)
{ int temp,i;
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
    {
        if(msize[i]<psize[i])
        {
            printf("%d can't be alloted\n",psize[i]);
        }
        else
        {
            printf("%d is alloted in %d memory block\n",psize[i],msize[i]);
            msize[i] = msize[i] - psize[i];
            sort(msize);
        }
        
    }
}

int sort(int msize[])
{   int temp;
    for(int i=0;i<m-1;i++)
    {
        for(int j=0;j<m-i-1;j++)
        {
            if(msize[j+1]>msize[j])
            {
                temp = msize[j];
                msize[j] = msize[j+1];
                msize[j+1] =temp;
            }
        }
    }
}