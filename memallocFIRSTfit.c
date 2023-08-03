#include<stdio.h>
int main()
{ 
  int i,p_size[100],m_size[100],n,m;
  printf("ENTER THE NUMBER OF PROCESS : ");
  scanf("%d",&n);
  printf("ENTER THE ARRAY OF PROCESS : ");
  for(i=0;i<n;i++)
  {
    scanf("%d",&p_size[i]);
  }
  printf("ENTER THE NUMBER OF MEMORY BLOCK : ");
  scanf("%d",&m);
  printf("ENTER THE ARRAY OF MEMORY BLOCK : ");
  for(i=0;i<m;i++)
  {
    scanf("%d",&m_size[i]);
  }
  firstfit(p_size,n,m_size,m);
}
void firstfit(int p_size[],int n, int m_size[], int m)
{
    printf("\t\tFIRST FIT \n");
    int i,j,flag,psize[100],msize[100];
    for(i=0;i<n;i++)
    {
        psize[i] = p_size[i];
    }
    for(i=0;i<m;i++)
    {
        msize[i] = m_size[i];
    }
    for(i=0;i<n;i++)
    {
    flag=0;
    for(j=0;j<m;j++)
    {
      if(msize[j]>=psize[i])
      {
        printf("%d ALLOCATED IN %d MEMORY BLOCK",psize[i],msize[j]);
        msize[j] = msize[j]-psize[i];
        printf(" => %d SPACE REMAINING \n",msize[j]);
        flag=1;
        break;
      }
    }
    if(flag==0)
    {
      printf("%d CANNOT BE ALLOCATED \n",psize[i]);
    }
    }
}