#include<stdio.h>
void FCFS();
void SJF();
void Priority();
void RR();

void main(){
int choice;
while(choice!=5){
printf("\n--->1.FCFS 2.SJF 3.priority 4.RR 5.EXIT\nenter the choice:");
scanf("%d",&choice);
switch(choice){
case 1:{
FCFS();
break;
}
case 2:{
SJF();
break;
}
case 3:{
Priority();
break;
}
case 4:{
RR();
break;
}
case 5:{
printf("EXITED!!\n");
break;
}
}
}
}

void FCFS(){
int limit,tot_wt=0,tot_tat=0;
printf("Enter the no of process:");
scanf("%d",&limit);
int process[limit],bt[limit],wt[limit],tat[limit];
printf("Enter the process and the corresponding burst time:");
for(int i=0;i<limit;i++){
scanf("%d%d",&process[i],&bt[i]);
}
wt[0]=0;
tat[0]=bt[0];
printf("PROCESS BURST_TIME TURN_AROUND_TIME WAITING_TIME\n");
printf("  %d        %d            %d             %d\n",process[0],bt[0],tat[0],wt[0]);
tot_tat=tot_tat+bt[0];

for(int i=1;i<limit;i++){
wt[i]=wt[i-1]+bt[i-1];
tat[i]=tat[i-1]+bt[i];
printf("  %d        %d            %d             %d\n",process[i],bt[i],tat[i],wt[i]);
tot_wt=tot_wt+wt[i];
tot_tat=tot_tat+tat[i];
}
printf("GANTT CHART:\n");
for(int i=0;i<limit;i++){
printf(" |P%d| ",process[i]);
}
printf("\n");
for(int i=0;i<limit;i++){
if(i==0){
printf("0    %d",tat[i]);
}
else{
printf("    %d",tat[i]);
}
}
printf("\n");
printf("Total turn around time=%d\n",tot_tat);
printf("Total waitng time=%d\n",tot_wt);
printf("average turn around time=%f\n",((float)tot_tat/limit));
printf("average waitng time=%f\n",((float)tot_wt/limit));
}

void SJF(){
int limit,tot_wt=0,tot_tat=0,temp,temp1;
printf("Enter the no of process:");
scanf("%d",&limit);
int process[limit],bt[limit],wt[limit],tat[limit];
printf("Enter the process and the corresponding burst time:");
for(int i=0;i<limit;i++){
scanf("%d%d",&process[i],&bt[i]);
}
for(int i=0;i<limit;i++){
for(int j=i+1;j<limit;j++){
if(bt[i]>bt[j]){
temp=bt[i];
bt[i]=bt[j];
bt[j]=temp;
temp1=process[i];
process[i]=process[j];
process[j]=temp1;
}
}
}
wt[0]=0;
tat[0]=bt[0];
printf("PROCESS BURST_TIME TURN_AROUND_TIME WAITING_TIME\n");
printf("  %d        %d            %d             %d\n",process[0],bt[0],tat[0],wt[0]);
tot_tat=tot_tat+bt[0];
for(int i=1;i<limit;i++){
wt[i]=wt[i-1]+bt[i-1];
tat[i]=tat[i-1]+bt[i];
printf("  %d        %d            %d             %d\n",process[i],bt[i],tat[i],wt[i]);
tot_wt=tot_wt+wt[i];
tot_tat=tot_tat+tat[i];
}
printf("GANTT CHART:\n");
for(int i=0;i<limit;i++){
printf(" |P%d| ",process[i]);
}
printf("\n");
for(int i=0;i<limit;i++){
if(i==0){
printf("0    %d",tat[i]);
}
else{
printf("    %d",tat[i]);
}
}
printf("\n");
printf("Total turn around time=%d\n",tot_tat);
printf("Total waitng time=%d\n",tot_wt);
printf("average turn around time=%f\n",((float)tot_tat/limit));
printf("average waitng time=%f\n",((float)tot_wt/limit));
}

void Priority(){
int limit,tot_wt=0,tot_tat=0,temp,temp1,temp2;
printf("Enter the no of process:");
scanf("%d",&limit);
int process[limit],bt[limit],wt[limit],tat[limit],priority[limit];
printf("Enter the process and the corresponding burst time and priority:");
for(int i=0;i<limit;i++){
scanf("%d%d%d",&process[i],&bt[i],&priority[i]);
}
for(int i=0;i<limit;i++){
for(int j=i+1;j<limit;j++){
if(priority[i]>priority[j]){
temp=bt[i];
bt[i]=bt[j];
bt[j]=temp;
temp1=process[i];
process[i]=process[j];
process[j]=temp1;
temp2=priority[i];
priority[i]=priority[j];
priority[j]=temp2;
}
}
}
wt[0]=0;
tat[0]=bt[0];
printf("PROCESS BURST_TIME PRIORITY TURN_AROUND_TIME WAITING_TIME\n");
printf("  %d        %d         %d          %d             %d\n",process[0],bt[0],priority[0],tat[0],wt[0]);
tot_tat=tot_tat+bt[0];
for(int i=1;i<limit;i++){
wt[i]=wt[i-1]+bt[i-1];
tat[i]=tat[i-1]+bt[i];
printf("  %d        %d         %d          %d             %d\n",process[i],bt[i],priority[i],tat[i],wt[i]);
tot_wt=tot_wt+wt[i];
tot_tat=tot_tat+tat[i];
}
printf("GANTT CHART:\n");
for(int i=0;i<limit;i++){
printf(" |P%d| ",process[i]);
}
printf("\n");
for(int i=0;i<limit;i++){
if(i==0){
printf("0    %d",tat[i]);
}
else{
printf("    %d",tat[i]);
}
}
printf("\n");
printf("Total turn around time=%d\n",tot_tat);
printf("Total waitng time=%d\n",tot_wt);
printf("average turn around time=%f\n",((float)tot_tat/limit));
printf("average waitng time=%f\n",((float)tot_wt/limit));
}

void RR(){
int limit,tot_wt=0,tot_tat=0,tq,total=0,flag=0,i,q[50];
printf("Enter the no of process:");
scanf("%d",&limit);
int process[limit],bt[limit],wt[limit],tat[limit],rt[limit];
printf("Enter the process and the corresponding burst time:");
for(int i=0;i<limit;i++){
scanf("%d%d",&process[i],&bt[i]);
rt[i]=bt[i];
}
printf("Enter the time quantum:");
scanf("%d",&tq);
int a=0;
q[a]=0;
while(flag!=limit){
for(i=0;i<limit;i++){
if(rt[i]>tq){
total=total+tq;
rt[i]=rt[i]-tq;
q[++a]=q[a]+tq;
printf(" |P%d| ",process[i]);
}
else if(rt[i]==0){
continue;
}
else{
total=total+rt[i];
q[++a]=q[a]+rt[i];
rt[i]=0;
tat[i]=total;
wt[i]=total-bt[i];
printf(" |P%d| ",process[i]);
flag++;
}
}
}
printf("\n");
for(int i=0;i<=a;i++){
printf("%d    ",q[i]);
}
printf("\nPROCESS BURST_TIME TURN_AROUND_TIME WAITING_TIME\n");
for(int i=0;i<limit;i++){
printf("  %d        %d            %d             %d\n",process[i],bt[i],tat[i],wt[i]);
tot_wt=tot_wt+wt[i];
tot_tat=tot_tat+tat[i];
}

printf("\n");
printf("Total turn around time=%d\n",tot_tat);
printf("Total waitng time=%d\n",tot_wt);
printf("average turn around time=%f\n",((float)tot_tat/limit));
printf("average waitng time=%f\n",((float)tot_wt/limit));
}
