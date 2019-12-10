#include <stdlib.h>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <conio.h>
#include <winsock2.h>
#include <windows.h>
#include <iostream>
#include <objidl.h>   /* For IPersistFile */
#include <shlobj.h>   /* For IShellLink */
#if defined(_MSC_VER)
#pragma comment(lib, "ole32.lib")
#pragma comment(lib, "uuid.lib")
#endif
#include <tchar.h>
#include <memory>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include<conio.h>
#define TAILLE_BUFFER 150
#include <Windows.h>
#include <wincon.h>
   #include <stdlib.h>
   #include <stdio.h>
#include <cstring>
#include <iostream>
       	typedef struct process
{
int DA;
int TE;
int tempsej;
int temfin;
int pol;
int pr;
int reste;

}process;
int processes[100][3], NP, quantum, scheduler[1000],WT[100];
unsigned int time = 0;
typedef struct el
{
	unsigned int p;
	struct el * next;
}Q;
Q * qeue = NULL;
void getSystem()
{
	int i;
	printf("\nNumber of processes: ");
	scanf("%d", &NP);
	
	printf("\nThe Quantum: ");
	scanf("%d", &quantum);
	
	for(i=0; i<NP; i++ )
	{
		printf("\n Arrival Time of p%d: ", i);
		scanf("%d", &processes[i][0]);
		printf("\n Burst time for p%d: ", i);
		scanf("%d", &processes[i][1]);
		processes[i][2] = processes[i][1];
		printf("\n-----------");
	}
}
void printSystem()
{

}
unsigned int executionRemained()
{
	int i;
	unsigned int x = 0;
	for(i=0; i<NP; i++)
	{
		if(processes[i][2] > 0)
		{
			x = 1;
		}
	}
	return x;
}
void addToQeue(int i)
{
	Q *n, *n1;
	n = (Q *)malloc(sizeof(Q));
	n->next = NULL;
	n->p = i;
	if(qeue == NULL)
	{
		
		qeue = n;
	}
	else
	{
		for(n1 = qeue ; n1->next!=NULL; n1=n1->next);
		n1 -> next = n;
	}
}
void addArrivedProcessesToQeue()
{
	int i;
	for(i=0; i<NP; i++)
	{
		if(processes[i][0] == time)
		{
			addToQeue(i);
		}
	}
}
unsigned int getNextProcess()
{
	Q *n;
	int x;
	if(qeue == NULL)
	{
		return -1;
	}
	else
	{
		x = qeue -> p;
		n = qeue;
		qeue = qeue -> next;
		free(n);
		return x;
	}
}
void schedule()
{
	unsigned int np, toRun, q, i;
	q = 0;
	addArrivedProcessesToQeue();
	while(executionRemained())
	{
		np = getNextProcess();
		if(np == -1)
		{
			
			scheduler[time] = -1;
			time++;
			addArrivedProcessesToQeue();
		}
		else
		{
			q = quantum;
			if(processes[np][2] < q)
			{
				q = processes[np][2];
			}
			for(i = q; i>0; i--)
			{
				scheduler[time]=np;
				time++;
				processes[np][2]--;
				addArrivedProcessesToQeue();
			}
			if(processes[np][2] > 0)
			{
				addToQeue(np);
			}
		}
		
		
		printSystem();
		int x;
		
	}
}
void printScheduling()
{
	int i;
	printf("\n\nScheduling: \n");
	for(i=0; i<time; i++)
	{
		printf("[%d-%d] (P%d) \n",i,i+1 ,scheduler[i]);
	}
	printf("\n\nWaiting Time: \n");
	for(i=0; i<NP; i++)
	{
		printf("\nP%d: %d", i, WT[i]);
	}
	//counting Average Waiting Time...
	float AWT = 0.0;
	for(i=0; i<NP; i++)
	{
		AWT = AWT+WT[i];
	}
	AWT = AWT/NP;
	printf("\n\nAverage Waiting Time: %f", AWT);
	
}
void WatingTime()
{
	int i;
	unsigned int releaseTime, t;
	for(i=0; i<NP; i++)
	{
		
		for(t=time-1; scheduler[t]!= i; t--);
		releaseTime = t+1;
		WT[i] = releaseTime - processes[i][0] - processes[i][1];
	}
}

struct sched_param P;
int main(int argc, char *argv[])
{
 
    int nbCaracteres = 20; 
    int b;
	int n=8;
    char ch[20];
    int nb;
    int choix;
    int L;
    system("cls");

	puts("HELLO");

do{
//	system("cls");
    printf("\n\t\t***  CMD  ******\n\n");
    
    puts("1 commande_out ");
    puts("2 change_directory  ");
	puts("3 changer_couleur ");
	puts("4 afficher_fichier");
    puts("5 creer_fichier");
	puts("6 creer_dossier");
	puts("7 commande_clean cmd ");
    puts("8 Supprimer_dossier ");
    puts("9  Affichage de l adresse Mac ");
    puts("10 pipe");
    puts("11 ordonnacement");
	do{
	    printf("donnez votre choix :");
	    scanf("%d",&choix);
	    if(choix>=12 || choix<1)
	         printf("votre choix doit etre 1 ..10 .\n"); 
    }while(choix>11 || choix<1); 
		  
	switch (choix)
	{
	  case 1:{
	     printf("out \n");
  	

   std::string line;
while (std::getline(std::cin, line))
{
	printf("Choisissez le nom du dossier :");
    std::cout << line << std::endl;
char nomDossier[20];


std::string l="creerdossier |";

if(line==l){
		mkdir("nouveau dossier");
		
		system("cls");
			break;	
					
}}	
  

	   }break;
	  case 2:{
       char s[100]; 
       printf("Votre path actuel est : %s\n", getcwd(s, 100));  
       char str1[100]="C:/TDM-GCC-64/proj/";
       char str2[100];
        printf("le nom de dossier pour acceder':\n ");
		strcat(str1, str2);    
        const char *filename=strcat(str1, str2);
        printf("%S",filename);
        scanf("%s",str1);
        const char* dir = filename;
        int ret = chdir(dir);
       if (ret){ // same as ret!=0, means an error occurred and errno is set
    	printf("dirrection erroné");
       }
     system("cls");
	  printf("Votre path actuel est : %s\n", getcwd(s, 100)); 

 

	system("cls");
do{
   printf(" %s\n", getcwd(s, 100)); 
    printf("\n\t\t***  CMD  ******\n\n");
    puts("1 commande out ");
    puts("2 Direction ");
	puts("3 changer le couleur ");
	puts("4 afficher un fichier");
	puts("5 creer un fichier commande creer_f");
	puts("6 creer dossier");
	puts("7 comm vider_cmd ");
int choix1;
	do{
	    printf("donnez votre choix :");
	    scanf("%d",&choix1);
	    if(choix1>=8 || choix1<1)
	         printf("votre choix doit etre 1 ..3 .\n"); 
    }while(choix1>7 || choix1<1); 
 
 switch (choix1)
	{
	case 1:{
	 printf("out \n");
    
	 exit(0);
	}break;	
	case 2:{
	
    printf("Votre path actuel est : %s\n", getcwd(s, 100));  
	 
	}break;
	case 3:{
			system("cls");
            system ("color 0C");

	}break;
    case 4:{
           system("cls");
           char str1[100];
           char str2[100];
           printf("Entrez le nom de fichier: ");
           scanf("%s",str1);
           const char *filename=str1;
           std::ifstream ifs(filename); 
           system("color e0");
           if(!ifs){ std::cerr << "Le fichier [" << filename << "] n'existe pas" << std::endl; return 1; } 
            system ("color e0");
           std::string line; while(std::getline(ifs,line)) std::cout << line << std::endl; ifs.close();
          return 0; 
		}break;
	case 5:{


 
   FILE *f;

  char str1[100];
  char  str2[100];
 
  printf("Entrez le nom de fichier: ");
  scanf("%s",str1);
  printf("Entrez l'extention':\n ");
  scanf("%s",str2);
  strcat(str1, str2);
  f=fopen( strcat(str1, str2),"w");
  if(f==NULL)
  
  {
             printf("Impossible d'ouvrir le fichier");
             }
 
        fclose(f);
       
      f=fopen( strcat(str1, str2),"r");
      
      
          fclose(f);
      }break;
  
  case 6:{

char nomDossier[20];
printf("Choisissez le nom du dossier :");
scanf("%s",nomDossier);
mkdir(nomDossier);
printf("votre dossier est crée avec succès ");

}break;
		
  case 7:{
    system("cls");
}break;		
	
	default:{
		
			}break;	}			
}while(choix !=7);	
 

	}break;
	
	case 3:{
    system ("color 0C");
    	system("cls");	
	}break;
    	case 4:{
    system("cls");
     char str1[100];
      char str2[100];
     printf("Entrez le nom de fichier: ");
     scanf("%s",str1);
    printf("Entrez l'extention':\n ");
     scanf("%s",str2);
    strcat(str1, str2);
    const char *filename=strcat(str1, str2);
    //const char *filename="sha.txt";
     std::ifstream ifs(filename); 
      system("color 0e");
      if(!ifs){ std::cerr << "Le fichier [" << filename << "] n'existe pas" << std::endl; return 1; } 
      system ("color 0e");
      std::string line; while(std::getline(ifs,line)) std::cout << line << std::endl; ifs.close();
     return 1; 
		
	}break;
	case 5:{
		
    FILE *f;
    char str1[100];
    char  str2[100];
    printf("Entrez le nom de fichier: ");
    scanf("%s",str1);
    printf("Entrez l'extention':\n ");
    scanf("%s",str2);
    strcat(str1, str2);
    f=fopen( strcat(str1, str2),"w");
    if(f==NULL)
    {
             printf("Impossible d'ouvrir le fichier");
     }
     fclose(f);
     f=fopen( strcat(str1, str2),"r");
               fclose(f);
      }break;
  
    case 6:{

      char nomDossier[20];
      printf("Choisissez le nom du dossier :");
      scanf("%s",nomDossier);
      mkdir(nomDossier);
      printf("votre dossier est crée avec seccess ");

    }break;
	case 7: {
	system("cls");	
  
    }break;
    case 8:{
	   char nomDossier[20];
       printf("Choisissez le nom du dossier :");
       scanf("%s",nomDossier);
       rmdir(nomDossier);
       printf("Dossier supprimer avec succès ");	
			system("cls");
    }break;
    case 9:{
  system("getmac");
    }break;
     case 10:{
    std::string line;
     	
while (std::getline(std::cin, line))
{
  
    FILE  *fp2;
    char ch;
  int i;
   

  std::cout << line << std::endl;
  std::string l="creer.txt|copy file";

if(line==l){
FILE* f1=fopen("creer.txt","w" );
fclose(f1);
 // ouvrir le fichier en lecture
    f1 = fopen("creer.txt", "a");
    // ouvrir le fichier en écriture
    fp2 = fopen("file.txt", "r");

    // Lire le contenu du fichier
    while((ch = getc(fp2)) != EOF)
        putc(ch, f1);
  
    fclose(f1);
    fclose(fp2);
    getch();
  char str[] = "creer.txt|copy file";
  char d[] = "|"; 

   int len = std::strlen(str);
   int le = std::strlen(d);
   char *p = strtok(str,d);	
   while(p != NULL)
  {
  
    printf("%s\n", p);
    p = strtok(NULL, d);
  }  
      break;
      }}
    }break;
    case 11:{
    	 printf ("<<<<<<<<<<<<<<< Program to Implement FCFS >>>>>>>>>>\n");
    char pn[10][10],t[10];
    int arr[10],bur[10],star[10],finish[10],tat[10],wt[10],i,j,n,temp;
    int totwt=0,tottat=0;
    //clrscr();
    	int ch;
    		do{
    	printf("choisir methode d'ordonnancement\n 1:FIFO 2:SJF 3:PRIORITY 4:Quantum\n");
    	scanf("%d",&ch);
    
	    if(ch>5 || ch<1)
	         printf("votre choix doit etre 1 ..3 .\n"); 
     }while(ch>4 || ch<1); 
     
      
 
 switch (ch)
	{
	case 1:{
		char pn[100];
 int pn1[100][100];
 int arr1[100][100];
  int arr[100];
 int h1[100][100];
  int h[100];
  int bur[3]={5,2,3};
  int t;
  int n=3;
    int i,j,k;
	int tab [100][100];
	int tmp;
    char tab1 [100][100];
	char tmp1;
     
    FILE *fichier = fopen("file.TXT", "rb");  
    FILE *fichier1 = fopen("file.TXT", "rb");  
	if (fichier != NULL)
    {
		printf("fichier ouvert\n");
	    for(i=0;i<4;i++)
		{
			for(j=0;j<3;j++)
			{
                 	 
				
			        
			         	
					   
				fscanf(fichier, "%d", &tmp);
				tab[i][j]=tmp;
		     	arr1[i][j]=tab[0][j];
		     	h1[i][j]=tab[1][j];
		     	pn1[i][j]=tab[3][j];
			}

		}
		
		fclose(fichier);
		printf("fichier referme\n");
		printf("le temps d'arriver'----est: %d,%d,%d \n", tab[0][0], tab[0][1], tab[0][2]);
		printf("le temps d'execution' est : %d %d %d \n", tab[1][0],tab[1][1],tab[1][2]);
		printf("la priorité --------- est : %d %d %d \n", tab[2][0],tab[2][1],tab[2][2]);
		
		//printf("la valeur de tab(.,.) est : %c %c %c \n", &tab[3][0],&tab[3][1],&tab[3][2]);
     	
	}
	
    else
    {
        printf("Impossible d'ouvrir le fichier .txt");
    }  
 printf("le nom de prosessus est :");
 for(i=0,j=0;i<3;j<3,j++,i++)
		{
		arr[i]=arr1[i][j];
		pn[i]=(intptr_t)&arr[i];
        printf("%c\t",pn[i]);
         }
     /*    
 //calcul temps d'arriver
    for(i=0,j=0;i<3;j<3,j++,i++)
		{
		arr[i]=arr1[i][j];
        printf(" %d \n",arr[i]);
         }
//nom pross
  
         //calcul temps d'execution
        
 for(i=0,j=0;i<3;j<3,j++,i++)
		{
		arr[i]=arr1[i][j];
		pn[i]=(intptr_t)&arr[i];
        printf(" %c \n",pn[i]);
         }
         int z=1;
        
	
        for(i=0;i<3;i++){
   
           printf(" %d \n",bur[i]);
		}*/
	getchar();        
		printf("\n<<<<<<<<<<<<<<<< Program to Simulate FIFO >>>>>>>>>>>>>>>>>>>");
			printf(" \n(\ _ /)\n ");
	        printf("(='.'=) \n");
	      printf("  ('')('') \n");
   
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(arr[i]<arr[j])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
                temp=bur[i];
                bur[i]=bur[j];
                bur[j]=temp;
                 t=pn[i];
                pn[i]=pn[j];
                pn[j]=t;
            
            }
 
        }
    } 
   
    for(i=0; i<n; i++)
    {
        if(i==0)
            star[i]=arr[i];
        else
            star[i]=finish[i-1];
        wt[i]=star[i]-arr[i];
        finish[i]=star[i]+bur[i];
        tat[i]=finish[i]-arr[i];
    }
  
  printf("\n");
    printf("Grant") ; 
		for(i=0; i<n; i++)
    { 
	  printf("\nprossesus %s||%1d===>%2d\t",&pn[i],star[i],finish[i]);
        totwt+=wt[i];
        tottat+=tat[i];
    }
  printf("\nPName Arrtime Burtime WaitTime Start TAT Finish");
	for(i=0; i<n; i++)
    {
        printf("\n%s\t%3d\t%3d\t%3d\t%3d\t%6d\t%6d",pn[i],arr[i],bur[i],wt[i],star[i],tat[i],finish[i]);
        totwt+=wt[i];
        tottat+=tat[i];
    }
    printf("\nAverage Waiting time:%f",(float)totwt/n);
    printf("\nAverage Turn Around Time:%f",(float)tottat/n);
    getch();      
    
  	 
	}break;
		case 2:{
		printf("\033[00m<<<<<<<<<<<<<<<< Program to Implement SJF >>>>>>>>>>>>>>>>>>>\033[00m\n");
			printf("\n(\ _ /)\n");
	        printf("(='.'=) \n");
	      printf("  ('')('') \n");
    int et[20],at[10],n,i,j,temp,st[10],ft[10],wt[10],ta[10];
    int totwt=0,totta=0;
    float awt,ata;
    char pn[10][10],t[10];
    //clrscr();
   printf("Enter the number of process:\n");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("Enter process name, arrival time& execution time:");
        //flushall();
        scanf("%s%d%d",pn[i],&at[i],&et[i]);
    }
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {   
        
             if(at[i]<at[j])
            {
              
                temp=at[i];
                at[i]=at[j];
                at[j]=temp;
                strcpy(t,pn[i]);
                strcpy(pn[i],pn[j]);
                strcpy(pn[j],t);
            }
            if(et[i]<et[j])
            {
           
                temp=et[i];
                et[i]=et[j];
                et[j]=temp;
                strcpy(t,pn[i]);
                strcpy(pn[i],pn[j]);
                strcpy(pn[j],t);
            }
        }
    for(i=0; i<n; i++)
    {
        if(i==0)
            st[i]=at[i];
        else
            st[i]=ft[i-1];
        wt[i]=st[i]-at[i];
        ft[i]=st[i]+et[i];
        ta[i]=ft[i]-at[i];
        totwt+=wt[i];
        totta+=ta[i];
    }
    awt=(float)totwt/n;
    ata=(float)totta/n;
     printf("\n");
     for(i=0; i<n; i++)
    {
        if(i==0)
            star[i]=at[i];
        else
            star[i]=finish[i-1];
        wt[i]=star[i]-at[i];
        finish[i]=star[i]+et[i];
        tat[i]=finish[i]-at[i];
    }
    printf("Grant") ; 
		for(i=0; i<n; i++)
    { 
	  printf("\nprossesus %s||%1d===>%2d\t",pn[i],star[i],finish[i]);
        totwt+=wt[i];
        tottat+=tat[i];
    }
    printf("\n Pname\t arrivaltime\t executiontime\t waitingtime\t tatime\n");
    for(i=0; i<n; i++)
        printf("\n%s\t%5d\t\t%5d\t\t%5d\t\t%5d",pn[i],at[i],et[i],wt[i],ta[i]);
    printf("\nAverage waiting time is:%f",awt);
    printf("\nAverage turnaroundtime is:%f",ata);
    getch();
		
		
	}	break;
	case 3:{
			printf("<<<<<<<<<<<<<<<< Program to Simulate PRIORITY >>>>>>>>>>>>>>>>>>>");
    int et[20],v[10],at[10],n,i,j,temp,p[10],st[10],ft[10],wt[10],ta[10],temp1[10];
    int totwt=0,totta=0;
    float awt,ata;
    char pn[10][10],t[10];
    //clrscr();
    printf("Enter the number of process:\n");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("Enter process name,      arrivaltime     ,execution time     & priority:");
        //flushall();
        scanf("%s %d %d %d",pn[i],&at[i],&et[i],&p[i]);
    }
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {   
        
            if(at[i]<at[j])
            {
                temp=at[i];
                at[i]=at[j];
                at[j]=temp;
                
                strcpy(t,pn[i]);
                strcpy(pn[i],pn[j]);
                strcpy(pn[j],t);
            }
            if(p[i]>p[j])
            {
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
                temp=at[i];
                at[i]=at[j];
                at[j]=temp;
                temp=et[i];
                et[i]=et[j];
                et[j]=temp;
                strcpy(t,pn[i]);
                strcpy(pn[i],pn[j]);
                strcpy(pn[j],t);
            }
        }
    for(i=0; i<n; i++)
 
    {
 
        if(i==0)
        {
            st[i]=at[i];
            wt[i]=st[i]-at[i];
            ft[i]=st[i]+et[i];
            ta[i]=ft[i]-at[i];
        }
        else
        {
            st[i]=ft[i-1];
            wt[i]=st[i]-at[i];
            ft[i]=st[i]+et[i];
            ta[i]=ft[i]-at[i];
        }
        totwt+=wt[i];
        totta+=ta[i];
    }
    awt=(float)totwt/n;
    ata=(float)totta/n;
    

    printf("\nPname\tarrivaltime\texecutiontime\tpriority\twaitingtime\ttatime");
    for(i=0; i<n; i++)
        printf("\n%s\t%5d\t\t%5d\t\t%5d\t\t%5d\t\t%5d",pn[i],at[i],et[i],p[i],wt[i],ta[i]);
        // print Gantt chart
    puts(""); // Empty line
    puts("          GANTT CHART          ");
    puts("          ***********          ");

    // print top bar
    printf(" ");
    for(i=0; i<n; i++) {
        for(j=0; j<p[i]; j++) printf("--");
        printf(" ");
    }
    printf("\n|");

    // printing process id in the middle
    for(i=0; i<n; i++) {
        for(j=0; j<p[i] - 1; j++) printf(" ");
        printf(" P%s",pn[i]);
        for(j=0; j<p[i]- 1; j++) printf(" ");
        printf(" | ");
    }
    printf("\n ");
    // printing bottom bar
    for(i=0; i<n; i++) {
        for(j=0; j<p[i]; j++)// printf("-");
        printf(" ");
    
         // printing the time line
   // printf("0");
   
    	int min =100;
       for(i=0; i<n; i++) {
if(min>at[i]){
	min=at[i];
}}
   printf("%d",min); 

    for(i=0; i<n; i++) {
        for(j=0; j<at[i]; j++) printf(" ");
        if(at[i] > 9)printf("\b"); // backspace : remove 1 space
   	  //  v[i]=at[i]+et[i];
     //   printf("%d ",(at[i]+et[i]));

    }
            printf("\n ");
    printf("\nAverage waiting time is:%f",awt);
    printf("\nAverage turnaroundtime is:%f",ata);
    getch();
}

	}break;
	case 4:{
	/*
	int count,j,n,time,remain,flag=0,time_quantum; 
  int wait_time=0,turnaround_time=0,at[10],bt[10],rt[10]; 
  printf("Enter Total Process:\t "); 
  scanf("%d",&n); 
  remain=n; 
  for(count=0;count<n;count++) 
  { 
    printf("Enter Arrival Time and Burst Time for Process Process Number %d :",count+1); 
    scanf("%d",&at[count]); 
    scanf("%d",&bt[count]); 
    rt[count]=bt[count]; 
  } 
  printf("Enter Time Quantum:\t"); 
  scanf("%d",&time_quantum); 
   if(rt[count]==0 && flag==1) 
    { 
    printf("\nP[%d]\t||",count+1);}
  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n"); 
  for(time=0,count=0;remain!=0;) 
  { 
    if(rt[count]<=time_quantum && rt[count]>0) 
    { 
      time+=rt[count]; 
      rt[count]=0; 
      flag=1; 
    } 
    else if(rt[count]>0) 
    { 
      rt[count]-=time_quantum; 
      time+=time_quantum; 
    }

    if(rt[count]==0 && flag==1) 
    { 
      remain--; 
      printf("P[%d]\t|\t%d\t|\t%d\n",count+1,time-at[count],time-at[count]-bt[count]); 
      wait_time+=time-at[count]-bt[count]; 
      turnaround_time+=time-at[count]; 
      flag=0; 
    } 
    if(count==n-1) 
      count=0; 
    else if(at[count+1]<=time) 
      count++; 
    else 
      count=0; 
  } 
  printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n); 
  printf("Avg Turnaround Time = %f",turnaround_time*1.0/n); 
*/

	getSystem();
	printSystem();
	schedule();
	WatingTime();
	printScheduling();
	}break;	

	
	 default:{
		
			}break;
     }break;
    
     }break;

	default:{
		
			}break;	}			
}while(choix !=11);		
return 0;
    }                                     
		 
