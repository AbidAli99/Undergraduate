#include "process_schedule.h"
int main(int argc,char *argv[]){
	char select;
        initscr();
	init_pcb_table();
	bool end=false;
	
	while(!end){
		clear();
		refresh();
		printw("|----------MAIN    MENU-------------|\n");
		printw("|  1:first come first served        |\n");
		printw("|  2:round robin                    |\n");
		printw("|  3:priority scheduling            |\n");
		printw("|  4:display ready process queue    |\n");
		printw("|  5:display blocked process queue  |\n");
		printw("|  6:display running queue          |\n");
		printw("|  a:create a process               |\n");
		printw("|  b:delete a process               |\n");
		printw("|  c:block  a process               |\n");
		printw("|  d:wakeup  a process              |\n");
		printw("|  7:exit                           |\n");
		printw("|-----------------------------------|\n");
		printw("select a function(1~8,a~d):");
                refresh();
		do{
			select=(char)getch();
                        refresh();
		}while(!((49<=select&&select<=56)||(97<=select&&select<=100)));
		clear();
        refresh();
		switch(select){
		case '1':
			FCFS();
			break;
		case '2':
			RR();
			break;
		case '3':
			PS();
			break;
		case '4':
			printw("              ready  queue\n");
			display_process_queue(pcb_ready);
			break;
		case '5':
			printw("              blocked  queue\n");
                        display_process_queue(pcb_blocked);
			break;
		case '6':
			printw("              running  queue\n");
                        display_process_queue(pcb_run);
			break;
		case 'a':
			create_process();
			break;
		case 'b':
			break;
		case 'c':
			block_process_by_name();
			break;
		case 'd':
			wakeup_process();
			break;
		case '7':
			printw("\n");
		        end=true;
		}
		printw("press any key to continue.\n");
		getch();
		refresh();
	}
	endwin();
	return 0;
}

void init_pcb_table()
{
	int i=0;
	pcb_free=&pcb_table[0];
	pcb_table[MAX_PROCESS-1].next=NULL;
	pcb_table[MAX_PROCESS-1].process_number=0;
	pcb_table[MAX_PROCESS-1].process_start_moment=0;
    pcb_table[MAX_PROCESS-1].process_burst_time=0;
	pcb_table[MAX_PROCESS-1].process_time_slice=0;
	pcb_table[MAX_PROCESS-1].process_priority=0;
	strcpy(pcb_table[MAX_PROCESS-1].process_name,"");
	for(i=0;i<MAX_PROCESS-1;i++){
		pcb_table[i].next=&pcb_table[i+1];
		pcb_table[i].process_number=0;
		pcb_table[i].process_start_moment=0;
        pcb_table[i].process_burst_time=0;
	    pcb_table[i].process_time_slice=0;
	    pcb_table[i].process_priority=0;
		strcpy(pcb_table[i].process_name,"");
	}
}

void display_process_queue(PCB *queue)
{
	PCB *p=queue;
	int i=4;
    move(1,1);
	printw("|----------|----------|----------|----------|----------|----------|\n");
	move(2,1);
	printw("| name     | number   | start    | need     | slice    | priority |\n");
	move(3,1);
	printw("|----------|----------|----------|----------|----------|----------|\n");
	while(p!=NULL){
		move(i,1);
		printw("| ");
		printw("%s",p->process_name);
		move(i,12);
		printw("| ");
		printw("%d",p->process_number);
		move(i,23);
		printw("| ");
		printw("%d",p->process_start_moment);
		move(i,34);
		printw("| ");
		printw("%d",p->process_burst_time);
		move(i,45);
		printw("| ");
		printw("%d",p->process_time_slice);
		move(i,56);
		printw("| ");
		printw("%d",p->process_priority);
		move(i,67);
		printw("|");
		p=p->next;
		i++;
	}
	move(i,1);
	printw("|----------|----------|----------|----------|----------|----------|\n");
	refresh();
}

void FCFS()
{

    int n,bt[5],wt[5],tat[5],i,j;
    float avwt=0,avtat=0;
    printw("Enter total number of processes(maximum 5):");
    scanw("%d",&n);
    printw("Arrival Time is considered 0\n");
    printw("\nEnter Process Burst Time\n");
    for(i=0;i<n;i++)
    {
        printw("P[%d]:",i);
        scanw("%d",&bt[i]);
    }

    wt[0]=0;    //waiting time for first process is 0

    //calculating waiting time
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
    }

    printw("|    Process  |    Burst  Time  |  Waiting  Time | Turnaround Time |\n");

    //calculating turnaround time
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
        avwt+=wt[i];
        avtat+=tat[i];
        printw("\tP[%d]\t\t%d\t\t%d\t\t%d\n",i,bt[i],wt[i],tat[i]);
    }

    avwt/=i;
    avtat/=i;
    printw("Average Waiting Time:%f\n",avwt);
    printw("Average Turnaround Time:%f\n",avtat);
	refresh();
}
			
void RR()
{
 // initlialize the variable name  
    int i, NOP, sum=0,count=0, y, quant, wt=0, tat=0, at[10], bt[10], temp[10];  
    float avg_wt, avg_tat;  
    printw(" Total number of process in the system: ");  
    scanw("%d", &NOP);  
    y = NOP; // Assign the number of process to variable y  
  
// Use for loop to enter the details of the process like Arrival time and the Burst Time  
for(i=0; i<NOP; i++)  
{  
printw("\n Enter the Arrival and Burst time of the Process[%d]\n", i+1);  
printw(" Arrival time is: \t");  // Accept arrival time  
scanw("%d", &at[i]);  
printw(" \nBurst time is: \t"); // Accept the Burst time  
scanw("%d", &bt[i]);  
temp[i] = bt[i]; // store the burst time in temp array  
}  
// Accept the Time qunat  
printw("Enter the Time Quantum for the process: \t");  
scanw("%d", &quant);  
// Display the process No, burst time, Turn Around Time and the waiting time  
printw("\n Process No \t\t Burst Time \t\t TAT \t\t Waiting Time ");  
for(sum=0, i = 0; y!=0; )  
{  
if(temp[i] <= quant && temp[i] > 0) // define the conditions   
{  
    sum = sum + temp[i];  
    temp[i] = 0;  
    count=1;  
    }     
    else if(temp[i] > 0)  
    {  
        temp[i] = temp[i] - quant;  
        sum = sum + quant;    
    }  
    if(temp[i]==0 && count==1)  
    {  
        y--; //decrement the process no.  
        printw("\nProcess No[%d] \t\t %d\t\t\t\t %d\t\t\t %d", i+1, bt[i], sum-at[i], sum-at[i]-bt[i]);  
        wt = wt+sum-at[i]-bt[i];  
        tat = tat+sum-at[i];  
        count =0;     
    }  
    if(i==NOP-1)  
    {  
        i=0;  
    }  
    else if(at[i+1]<=sum)  
    {  
        i++;  
    }  
    else  
    {  
        i=0;  
    }  
}  
// represents the average waiting time and Turn Around time  
avg_wt = wt * 1.0/NOP;  
avg_tat = tat * 1.0/NOP;  
printw("\n Average Turn Around Time: \t%f", avg_wt);  
printw("\n Average Waiting Time: \t%f\n", avg_tat);  
refresh();  
}
		
void PS()
{
	 int bt[20],p[20],wt[20],tat[20],pr[20],i,j,n,total=0,pos,temp,avg_wt,avg_tat;
    printw("Enter Total Number of Process:");
    scanw("%d",&n);
 
    printw("\nEnter Burst Time and Priority\n");
    for(i=0;i<n;i++)
    {
        printw("\nP[%d]\n",i+1);
        printw("Burst Time:");
        scanw("%d",&bt[i]);
        printw("Priority:");
        scanw("%d",&pr[i]);
        p[i]=i+1;           //contains process number
    }
 
    //sorting burst time, priority and process number in ascending order using selection sort
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }
 
        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
 
    wt[0]=0; //waiting time for first process is zero
 
    //calculate waiting time
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
 
        total+=wt[i];
    }
 
    avg_wt=total/n;      //average waiting time
    total=0;
 
    printw("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];     //calculate turnaround time
        total+=tat[i];
        printw("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
    }
 
    avg_tat=total/n;     //average turnaround time
    printw("\n\nAverage Waiting Time=%d",avg_wt);
    printw("\nAverage Turnaround Time=%d\n",avg_tat);
}
		

PCB *create_process()
{
	PCB *p=pcb_free;
	if(p==NULL)
		return NULL;
	else
	{
		pcb_free=pcb_free->next;
		clear();
		refresh();
		printw("please enter the following fields:\n");
		printw("| name | start_moment | burst_time | time_slice | priority |\n");
		scanw("%s%d%d%d%d",
p->process_name,
&(p->process_start_moment),
&(p->process_burst_time),
&(p->process_time_slice),
&(p->process_priority));
		p->process_number=(process_number+1)%100;
		process_number++;
		p->next=NULL;
		if(pcb_ready==NULL)
			pcb_ready=pcb_ready_rear=p;
		else
		{
		    pcb_ready_rear->next=p;
		    pcb_ready_rear=p;
		}
		return p;
	}
}


void block_process_by_name()
{
	char process_name[20];
	PCB *p=pcb_ready;
	PCB *previous_p=pcb_ready;
	if(p==NULL)
	{
		printw("ready queue is empty,no process can be blocked!\n");
		return;
	}
	display_process_queue(pcb_ready);
	printw("enter the process name you want to block:\n");
	scanw("%s",process_name);
	while(p!=NULL){
		if(!strcmp(p->process_name,process_name))
			break;
		previous_p=p;
		p=p->next;
	}
	if(p==NULL)
	{
		printw("no such a process in ready queue:%s\nyou typed the wrong name\n",
process_name);
		return;
	}
	else
	{
		if(p==pcb_ready_rear)
		{
			pcb_ready_rear=previous_p;
		}
         previous_p->next=p->next;
		 if(pcb_blocked==NULL)
		 {
			 pcb_blocked=pcb_blocked_rear=p;
			 p->next=NULL;
		 }
		 else
		 {
			 pcb_blocked_rear->next=p;
             pcb_blocked_rear=pcb_blocked_rear->next;
			 p->next=NULL;
		 }
	}

}

void wakeup_process()
{
	PCB *p=pcb_blocked;
	if(pcb_blocked==NULL)
	{
		printw("blocked queue is empty,no process needs to be wakeuped.\n");
	}
    else{
	
	      if(pcb_blocked==pcb_blocked_rear)
	            	pcb_blocked=pcb_blocked_rear=NULL;
	      else
		            pcb_blocked=pcb_blocked->next;
	
          if(pcb_ready==NULL)
		 {
		    pcb_ready=pcb_ready_rear=p;
		    p->next=NULL;
		 }
      	else
		{
		   pcb_ready_rear->next=p;
		   pcb_ready_rear=pcb_ready_rear->next;
		   p->next=NULL;
		}
	}
}//wakeup
