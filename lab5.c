/*
 * lab5.c
 *
 *  Created on: Nov 15, 2017
 *      Author: Sheida
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define L 31

typedef struct info{
	char name[L];
	int id;
	float num_lap;
	float avg;
	float sum;
	float time_lap;
}info_t;

info_t *readFile (int *);
void infolist(info_t *,int);
void printBest(info_t *,int);
void details(info_t *,int);

int main(){
	info_t *athletes;
	int n;
	char cmd[L];

	athletes = readFile(&n);
	fprintf(stdout,"COMMAND ?:\n");
	scanf("%s",cmd);
	while (strcmp(cmd,"STOP")!=0){

	if (strcmp(cmd,"LIST")==0){

		infolist(athletes,n);
	}
	if (strcmp(cmd,"BEST")==0){
			printBest(athletes,n);

		}
	if (strcmp(cmd,"DETAILS")==0){
			details (athletes,n);
		}
	if (strcmp(cmd,"STOP")!=0){
			fprintf(stdout,"unknown comment");
		}

	}

	//free!!
	free (athletes);
	fprintf(stdout,"End of Program.\n");
	return 0;
}

info_t *readFile(int *n){
	FILE *fp;
	char name[L],fin[L];
	int i,j,id,num_laps,lap_times;
	info_t *athlete;
	float sum=0,avg=0;


	fprintf(stdout,"input file name :\n");
	scanf("%s",fin);
	fp=fopen(fin,"r");

	if(fp==NULL){
		printf("\n ERROR, file is empty!\n");
		exit (EXIT_FAILURE);
	}

	fscanf(fp,"%d",&n);
	//malloc in sizeof n

	athlete=(info_t *)malloc(*n*sizeof(info_t));
	if(athlete ==NULL){
		printf("\n !ALLOCATION ERROR!\n");
		exit (EXIT_FAILURE);
	}
	i=0;
	while (i<*n && fscanf(fp,"%s %d %d",name,id,num_laps)){
		strcpy(name,athlete[i].name);
		athlete[i].id=id;
		athlete->num_lap=num_laps;
		athlete[i].time_lap=(float *)malloc(athlete[i].num_lap*sizeof(float));

		if(athlete[i].time_lap == NULL){
			printf("ALLOCATION ERROR (time laps)\n");
			exit (EXIT_FAILURE);
		}
		for(j=0;j<num_laps;j++){
			fscanf("%d",lap_times);
			sum+=lap_times;
		}
		athlete[i]->avg=athlete[i].sum/athlete[i]->num_lap;


		//printf("%d",&avg);
	}
	i++;



	fclose(fp);

	return athlete;
}
void infolist(info_t *ath,int n){
	int i;
	fprintf(stdout,"number of athletes:%d\n",n);
	for(i=0;i<n;i++){
	fprint(stdout,"Name : %s	 #id = %d   #Laps=%d\n",ath[i].name,&ath[i].id,&ath[i].num_lap);
	}

}
void printBest(info_t *ath,int n){
	int MAX=0;
	float tmp=0.0;
	int i;
	int flag=0;
	while (flag=0){
		for(i=0;i<n;i++){

			if(ath[i].avg > MAX){
			tmp=ath[i].avg;
			flag=1;
		}
		}
	}
	if (flag==1){
	fprintf(stdout,"Name : %s  #id : %d  #Laps=%d  BEST AVG=%d \n",ath.name,&ath.id,&ath.num_lap,&ath.avg);
	}
}
void details (info_t *ath , int n){
char name[L];
int i;
int flag=0;
	scanf("%s",name);

	for(i=0;i<n;i++){

	if (strcmp(name,ath[i].name)==0){
		flag=1;
	}
	while (flag==1){
		fprintf(stdout,"#id : %d  #Laps=%d #Times: %d \n",&ath.id,&ath.num_lap,&ath->time_lap);

	}
}

}
