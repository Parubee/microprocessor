#pass1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
char opcode[20],operand[20],code[20],label[20],add[10];
int locctr=0,start,length=0,flag=0;
FILE *fp1,*fp2,*fp3,*fp4;
printf("o");
fp1=fopen("input.txt","r");
printf("o");
fp2=fopen("optab.txt","r");
printf("o");
fp3=fopen("symtab.txt","w");
printf("o");
fp4=fopen("outputdata.txt","w");
printf("File opened\n");
//reading first input line
fscanf(fp1,"%s\t%s\t%s",label,opcode,operand);
//if opcode equals start
if(strcmp(opcode,"START")==0)
{
start=atoi(operand);
locctr=start;
//write line to intermediate file
fprintf(fp4,"%s\t%s\t%s\n",label,opcode,operand);
//read next input line
}
else
{
locctr=0;
}
fscanf(fp1,"%s\t%s\t%s",label,opcode,operand);
//while opcode!=end
while(strcmp(opcode,"END")!=0)
{
fprintf(fp4,"%d\t",locctr);
flag=0;
//if this is not a comment line
if(strcmp(label,"**")!=0)
{
fprintf(fp3,"%s\t%d\n",label,locctr);
}

fscanf(fp2,"%s\t%s",code,add);
//searching the optab for opcode and if found
while(strcmp(code,"END")!=0)
{
if((strcmp(opcode,code))==0)
{
locctr=locctr+3;
flag=1;
break;
}
fscanf(fp2,"%s\t%s",code,add);
}
printf("Opcode searching");
//if the opcode not found
/*if(flag==0)
{
printf("Error occurred..\n");
exit(0);
}*/
//if opcode is word
if((strcmp(opcode,"WORD"))==0)
{
locctr=locctr+3;
}
//if opcode is RESW
else if(strcmp(opcode,"RESW")==0)
{
locctr=locctr+(3*atoi(operand));
}
//if opcode is RESB
else if(strcmp(opcode,"RESB")==0)
{
locctr=locctr+atoi(operand);
}
printf("opcode search finished\n");
fprintf(fp4,"%s\t%s\t%s\n",label,opcode,operand);
fscanf(fp1,"%s\t%s\t%s",label,opcode,operand);
}
//write last line to intermediate file
fprintf(fp4,"%d\t%s\t%s\t\n",locctr,label,opcode);
//calculating the length of the program
length=locctr-start;
printf("The length of the program is %d\n",length);
fclose(fp1);
fclose(fp2);
fclose(fp3);
fclose(fp4);
}
	
