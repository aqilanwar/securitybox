#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
void login();
void signup();
void reset();
void loggedin();
void setpassword();

char username[100], password[100] ,holdpassword[100], name[20] , phonenum[20] , ansq1[20] ,ansq2[20] , ansq3[20];
char question1[100] = "What is my first car registration number ?";
char question2[100] = "What is my first motorcycle registration number ?";
char question3[100] = "What is my first girlfriend's mother phone number ?";

int main() {
 
  int choice ;

  printf("=========================================== \n");
  printf("\t Welcome to SECUREBOX. \n");
  printf("=========================================== \n");
  printf("\t \nThank you for purchasing our product \nPlease register your account before you can proceed.\n\n\n");

  printf("\t1. Register \n");
  printf("\t2. Exit \n");
  
  printf("\nPlease Enter the option [1/2]: ");
  
  scanf("%d", &choice);
  
  if(choice == 1){
    system("CLS");
  	signup();
  }else if(choice == 2){
  	return 0;
  }else{
  	system("CLS");
  	printf("Input is invalid, Please try again.\n");
  	main();
  }
}

void menu(){
  
  int choice ;
  
  printf("=========================================== \n");
  printf("\t \t[SECUREBOX] Main Menu\n");
  printf("=========================================== \n");
  printf("\tYou have succesfully sign up !\n");
  printf("\t1. Login \n");
  printf("\t2. Reset Password \n");
  
  printf("\nPlease Enter the option [1/2]: ");
  
  scanf("%d", &choice);
  
  if(choice == 1){
    system("CLS");
  	login();
  }else if(choice == 2){
  	reset();
  }else{
  	system("CLS");
  	printf("Input is invalid, Please try again.\n");
  	menu();
  }
}

void login(){
  char holdusername[100];
  char holdpassword[100];
  
  printf("=========================================== \n");
  printf("\t [SECUREBOX] Login\n");
  printf("=========================================== \n\n\n");

  printf("\tEnter your username : ");
  scanf("%s", holdusername);
  printf("\tEnter your password : ");
  scanf("%s", holdpassword);
  
  
  if(strcmp(holdusername,username) != 0 || strcmp(holdpassword,password) !=0 ){
  	system("cls");
  	printf("\n Your username or password is incorrect, try again.\n\n");
  	menu();
  }
  system("CLS");
  loggedin(); 
}

void loggedin(){
  int closedoor;
  
  printf("=========================================== \n");
  printf("\t \t[SECUREBOX]\n");
  printf("=========================================== \n\n\n");
  printf("\nYou have succesfully logged in.");                     
  printf("\t \nYour SECUREBOX is currently open.\nPlease close the door and enter [1] to lock the door : ");
  scanf("%d", &closedoor);
  
  if(closedoor == 1){
	   system("cls");
	   printf("Your SECUREBOX is currently locked.\n");
	   menu();
  }

  


}
void signup(){
  printf("=========================================== \n");
  printf("\t [SECUREBOX] Sign Up \n");
  printf("=========================================== \n\n\n");

  printf("\tEnter your username : ");
  scanf("%s", username);
  
  setpassword();
 	  
 	   printf("\n\n\n\n=========================================== \n");
	   printf("\t [SECUREBOX] Security Question \n");
	   printf("=========================================== \n");
  	   printf("[NOTE : Do not include space for each answer]\n\n");

	   printf("%s" , question1);
   	   printf("\nAnswer : ");
	   scanf("%s" , ansq1);
	   
	   printf("%s" , question2);
	   printf("\nAnswer : ");
	   scanf("%s" , ansq2);
	   
	   printf("%s" , question3);
	   printf("\nAnswer : ");
	   scanf("%s" , ansq3);
	   
	   system("cls");
	   menu();
  
}

void reset(){
  
  int question, gate = 0;
  char holdusername[100] , password[100], holdans[20];
  printf("=========================================== \n");
  printf("\t [SECUREBOX] Reset Password \n");
  printf("=========================================== \n\n\n");

  printf("\tEnter your username : ");
  scanf("%s", holdusername);
  
  if(strcmp(holdusername,username) != 0 ){
  	system("cls");
  	printf("\n Your username is incorrect, try again.\n\n");
  	reset();
  }
    
	printf("\nChoose at least 1 security question : ");
    printf("\n1. %s" , question1);
	printf("\n2. %s" , question2);
	printf("\n3. %s" , question3);
	
	
	do{
		printf("\n\nEnter question [1/2/3] : ");
	 	scanf("%d", &question);
	 	
	 	if(question == 1){
	 		printf("%s" , question1);
	 		printf("Answer :");
		    scanf("%s" , holdans);
		    
		    if(strcmp(holdans,ansq3)==0){
		    	gate == 1;
		    	system("cls");
		    	printf("=========================================== \n");
				printf("\t [SECUREBOX] Setup Your New Password \n");
				printf("=========================================== \n\n\n");
		    	setpassword();	
		    	system("CLS");
				menu();	
		    }else{
		    	printf("Your answer is incorrect. Please Try again");
		    	
			}
		}else if(question == 2){
		 	printf("%s" , question2);
	 		printf("Answer :");
		    scanf("%s" , holdans);
		    
			if(strcmp(holdans,ansq3)==0){
				gate == 1;
		    	system("cls");
		    	printf("=========================================== \n");
				printf("\t [SECUREBOX] Setup Your New Password \n");
				printf("=========================================== \n\n\n");
		    	setpassword();	
		    	system("CLS");
		    	menu();
		    	
		    }else{
		    	printf("Your answer is incorrect. Please Try again");	
			}
		}else if(question == 3){
		 	printf("%s" , question3);
	 		printf("Answer :");
		    scanf("%s" , holdans);
		    
		    if(strcmp(holdans,ansq3)==0){
		    	gate == 1;
		    	system("cls");
		    	printf("=========================================== \n");
				printf("\t [SECUREBOX] Setup Your New Password \n");
				printf("=========================================== \n\n\n");
		    	setpassword();
		    	system("CLS");
		    	menu();
				}
			else{
		    	printf("Your answer is incorrect. Please Try again");	
			}
				
		}else{
		 	printf("Question Number is not valid. Try again!");
		}  	
	}while(gate == 0);
	
}


void setpassword(){
	  do{
  	 
  	  printf("\tEnter your password : ");
	  scanf("%s", password);
	  
	  while(strlen(password)<7){
	  	printf("\tYour password is too short, please insert at least 7 character/number to proceed.\n");
	  	printf("\tEnter your password : ");
	    scanf("%s", password);
	  }
	  
	  printf("\tRe-enter your password : ");
	  scanf("%s", holdpassword); 
	  
	  if(strcmp(password,holdpassword) != 0)
 		printf("\tYour password is incorrect, please retype again.\n");
  }while(strcmp(password,holdpassword) != 0);
}

