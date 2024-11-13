#include<stdio.h>
#include<stdlib.h>
void main(){
 FILE *objectcode;
 int i,length;
 char arr[50],line[50];
 objectcode=fopen("objectcode.txt","r");
 fscanf(objectcode,"%s",line);
 printf("The name of the program:");
 for(i=2;i<4;i++){
 printf("%c",line[i]);
 }
  printf("\n");
 do{
  fscanf(objectcode,"%s",line);
  if(line[0]=='T'){
  for (i=2;i<6;i++){
  arr[i]=line[i+2];
  }
 arr[i]='\0';
 length=atoi(arr);
 i=12;
 while(line[i]!='\0'){
  if(line[i]!='^'){
  printf("%d: %c%c\n",length,line[i],line[i+1]);
  length++;
  i=i+2;
  }
  
  else{
  i++;
  }
  }
  }
 else if(line[0]=='E'){
      break;
      }
      }
  while(!feof(objectcode));
  fclose(objectcode);
  }
  
