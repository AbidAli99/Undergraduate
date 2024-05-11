#include <curses.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_PROCESS 10
int process_number=0;
typedef struct pcb{
	struct pcb *next;
	char process_name[20];
	int process_number;
	int process_start_moment;
	int process_burst_time;      
	int process_time_slice;
	int process_priority;
}PCB;

PCB pcb_table[MAX_PROCESS];

PCB *pcb_run=NULL;
PCB *pcb_free=NULL;
PCB *pcb_ready=NULL;
PCB *pcb_ready_rear=NULL;
PCB *pcb_blocked=NULL;
PCB *pcb_blocked_rear=NULL;

void init_pcb_table();
void display_process_queue(PCB *queue);
PCB *create_process();
void block_process_by_name();
void wakeup_process();

void FCFS();
void RR();
void PS();
void input();
void changeArrival();