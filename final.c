//Final Project
//Paige Krueger & Yael Collazo Osorio

#include <stdio.h>

//Define File

#define FILE_NAME "image.txt"

//Declare Functions
int ogMenu();
int uploadimage();
void displayimage();
int editMenu();
void cropimage ();
void dimimage();
void brightenimage();
void exitProgram();

int main(){

int image[][] //add values 
int imageHeight = //VALUE, imagewidth = //VALUE;
char choice;
char echoice;


ogMenu(choice);

switch(choice){

	case '1': uploadimage();
	break;
	
	case '2': displayimage();
	break;

	case '3': editMenu(echoice);
	break;
	
	case '4': exit();
	break;
}

switch(echoice){

	case '1': cropimage();
	break;
	
	case '2': dimimage();
	break;

	case '3': britimage();
	break;
	
	case '4': exit();
	break;
}
	

return 0;
}


int ogMenu(char choice){
	do{
		printf("Upload Image File [1]\nDisplay Image [2]\nEdit Image[3]\nExit [4]\n")
		scanf(" %c", &choice)
	}
	while(choice != '1' && choice !='2' && choice != '3')

	return choice;
}


int uploadimage(){
	//Bones are here, just need to update the file depending on what we want
		
	FILE* readFilePointer = fopen(READ_FILENAME, "r");
	
	if(readFilePointer == NULL){
		printf("Input file does not exist.\nGoodbye!\n");
		return 0;
	}
	
	else{ 
	
	for (int i = 0; i < 10; i++){
		fscanf(readFilePointer, "%d", &whole[i]);
		}
			
	}
	fclose(readFilePointer);
	return 1;
}



int displayimage(){
	//Insert For loop inside a for loop to print
	printf("Current Image:  \n");
	for (int **ROW = 0; ROW < imageHeight; ROW++){
	for (int *COLUMN = 0; COLUMN < imagewidth; *COLUMN++){
		printf("%d ", image[][]);

}


int editMenu(char echoice){
	do{
		printf("Crop Image [1]\nDim Image [2]\nBrighten Image[3]\n")
		scanf(" %c", &choice)
	}
	while(choice != '1' && choice !='2' && choice != '3')
	return choice;
}

	void cropimage(){
	printf("Enter how much coordinates you would like to crop\n");
	scanf("%d" ,    )
	int croppedHigh, croppedWid
	
	
	
	
	
	
}
	void dimimage(){
	printf("How much would you like to dim 	***EX***\n");
	scanf("%d", &****);
	
	float dim = value
	
	for(int *ROW =0; *ROW < imageHeight; *ROW ++){
	   for( int **column = 0; ***column < imageWidth; ***column++){
	   
	
	}
	
	
}
	void brightenimage(){
	printf("how much would you like to brighten ***EX***\n");
	scanf("%d", &***);
	
	for(int **ROW =0; row < imageHeight; row++){
	   for(int ***COLUMN = 0; column < imageWidth; column++){
	   
	
	
	}
	
	
	
}

int exit(){
	printf()

		FILE* dest_fp;
		dest_fp = fopen(FILE_NAME, "w");
	
		if(dest_fp == NULL){
			printf("Can't open file\n");
			return 0;
			}
		else{
			//Insert For loop inside a for loop to print
			
			fprintf(dest_fp, " %c", &Image[][]);
			
			}
			fclose(dest_fp);
		}




