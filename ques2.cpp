#include<stdio.h> 
#include<conio.h>
/* schedule is the function which calculates the waiting time and turn around time of each process and then calculates
the average waiting time and the turn around time.*/
void schedule(int no,int remt[10],int current,int arrival[10], int burst[10]){
	
	float avg_wait,avg_tut;
 int i,j,n=no,temp,btime[20],process_no[20],wait[20],tat[20],total=0,loc;
 
 printf("Third round with maximum burst time.\n");
 
 for(i=0;i<n;i++)// calculation of waiting time of each process.
 {
 btime[i]=remt[i];
 wait[i]=current-arrival[i]-btime[i];
	process_no[i]=i+1;
 }
	
 for(i=0;i<n;i++)
 {
 loc=i;
 for(j=i+1;j<n;j++)
 {
 if(btime[j]>btime[loc]){
 loc=j;
 }
 }
 temp=btime[i];
 btime[i]=btime[loc];
 btime[loc]=temp;
 temp=process_no[i];
 process_no[i]=process_no[loc];
 process_no[loc]=temp;
 }
	
 for(i=1;i<n;i++)
 {
 for(j=0;j<i;j++){
 wait[i]+=btime[j];
 }
 total+=wait[i];
 }
 
 avg_wait=(float)total/n; //average waiting time.
 total=0;
 printf("\nProcess\t\tBurst time\t\twaiting time\t\tTurnaround Time");
 for(i=0;i<n;i++)
 {
 tat[i]=btime[i]+wait[i]; //calculating the turn around time
 total=total + tat[i];
 printf("\nP%d\t\t\t%d\t\t\t%d\t\t\t%d",process_no[i],btime[i],wait[i],tat[i]);
 }
 avg_tut=(float)total/n; //average turn around time
 printf("\n\nAverage waiting time = %f",avg_wait);
 printf("\n Average turnaround time = %f\n",avg_tut);
	
}

main() 
{
	int process_no,j,no,CurT,RemProc,counter,tq,wait,tut,arrival[10],burst[10],remt[10],x=1;
	counter = 0;
	wait = 0;
	tut = 0;
	printf("Enter number of processes "); //user inputs for the details of processes.
	scanf("%d",&no);
	RemProc = no;
	
	printf("\nEnter the details of the processes as stated:\n");
	for(process_no = 0;process_no < no;process_no++) 
	{
	printf("\nProcess P%d\n",process_no+1);
	printf("Arrival time = "); 
	scanf("%d",&arrival[process_no]);
	printf("Burst time = "); 
	scanf("%d",&burst[process_no]); 
	remt[process_no]=burst[process_no]; 
	} 
	
	printf("The time quantum for first round is 6.\n"); 
	tq=3;
	CurT=0;
	for(process_no=0;RemProc!=0;) 
	{
	if(remt[process_no]<=tq && remt[process_no]>0)
	{ 
	CurT+=remt[process_no]; 
	remt[process_no]=0; 
	counter=1; 
	} 
	else if(remt[process_no]>0)
	{ 
	remt[process_no]-=tq; 
	CurT+=tq; 
	} 
	if(remt[process_no]==0 && counter==1)	
	{ printf("%d",process_no);
	RemProc--;	
	printf("P %d",process_no+1); 
	printf("\t\t\t%d",CurT-arrival[process_no]);
	printf("\t\t\t%d\n",CurT-burst[process_no]-arrival[process_no]);
	wait+=CurT-arrival[process_no]-burst[process_no]; 
	tut+=CurT-arrival[process_no]; 
	counter=0; 
 
	} 
	if(process_no==no-1){
	x++;
	if(x==2){
	process_no=0;
	tq=6;
	
	printf("The time quantum for second round is 10. \n");
	}
	else{
	break;
	}
	}
	else if(CurT >= arrival[process_no+1]){
	process_no++;
	}
	else{
	process_no=0;
	}
	}
	
	schedule(no,remt,CurT,arrival,burst);
	
	return 0;
}



