#include<stdio.h>
#include<conio.h>
struct process
{
    char a[20];
    int ar_t,br_t,ft,tat,rem,pr;
    float ntat;
}Q[5],temp;
int rr[20],q,x,k;
main()
{
    int f,r,n,i,j,tt=0,qt,t,flag,wt=0;
    float awt=0,antat=0,ar_tar_t=0;
    
    printf("Enter the no. of jobs:");
    scanf("%d",&n);
    for(r=0;r<n;r++)
    {
        printf("Enter process name :\n");
        scanf("%s",Q[r].a);
		printf("Enter the arrival time :\n");
        scanf("%d",&Q[r].ar_t);
		printf("Enter burst time :\n");
        scanf("%d",&Q[r].br_t);
		printf("Enter priority :\n");
		scanf("%d",&Q[r].pr);
    }
    printf("Enter quantum:\n");
    scanf("%d",&qt);
    
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(Q[i].ar_t<Q[j].ar_t)
            {
                temp=Q[i];
                Q[i]=Q[j];
                Q[j]=temp;
            }
		}
	}
	for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(Q[i].ar_t==Q[j].ar_t)
            {
                if(Q[i].pr<Q[j].pr)
				{
				temp=Q[i];
                Q[i]=Q[j];
                Q[j]=temp;
            	}
            }
		}
	}
	
    for(i=0;i<n;i++)
    {
        Q[i].rem=Q[i].br_t;
        Q[i].ft=0;
    }
    tt=0;
    q=0;
    rr[q]=0;
    do
    {
        for(j=0;j<n;j++)
        if(tt>=Q[j].ar_t)
        {
            x=0;
            for(k=0;k<=q;k++)
            if(rr[k]==j)
            x++;
            if(x==0)
            {
                q++;
                rr[q]=j;
            }
        }
        if(q==0)
        i=0;
        if(Q[i].rem==0)
        i++;
        if(i>q)
        i=(i-1)%q;
        if(i<=q)
        {
            if(Q[i].rem>0)
            {
                if(Q[i].rem<qt)
                {
                    tt+=Q[i].rem;
                    Q[i].rem=0;
                }
                else
                {
                    tt+=qt;
                    Q[i].rem-=qt;
                }
                Q[i].ft=tt;
            }
            i++;
        }
        flag=0;
        for(j=0;j<n;j++)
        if(Q[j].rem>0)
        flag++;
    }while(flag!=0);
    
    printf("\n\n\t\t\t       ROUND ROBIN ALGORITHM");
	printf("\n\tprocesses || Arrival time || Burst time || Finish time || TAT || WT ");
    for(f=0;f<n;f++)
    {
        wt=Q[f].ft-Q[f].br_t-Q[f].ar_t;
        Q[f].tat=Q[f].ft-Q[f].ar_t;
        Q[f].ntat=(float)Q[f].tat/Q[f].br_t;
        ar_tar_t+=Q[f].tat;
        awt+=wt;
    printf("\n\t  %s              %d               %d               %d         %d     %d ",
        Q[f].a,Q[f].ar_t,Q[f].br_t,Q[f].ft,Q[f].tat,wt);
    }
	antat/=n;
    ar_tar_t/=n;
    awt/=n;
    printf("\n\n\nAverage Turn around time is %f",ar_tar_t);
    printf("\n\n\nAverage waiting time is %f",awt);
   }
