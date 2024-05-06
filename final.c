//Final Project
//Paige Krueger & Yael Collazo Osorio

#include <stdio.h>

void ogMenu(char *choice);
void uploadimage(int image[][500]);
void displayimage(int image[][500], int imageWidth, int imageHeight);
void editMenu(char *echoice);
void cropimage(int *imageWidth, int *imageHeight, int image[][500]);
void brightenimage(int image[][500]);
void dimimage(int image[][500]);
void done(char *fchoice, int imageWidth, int imageHeight, int image[][500]);

int main(){

int image[500][500];
int imageHeight = 500;
int imageWidth = 500;
char choice;
char echoice;
char fchoice;

ogMenu(&choice);

	if(choice == '1'){
		uploadimage(image);} 
	else if(choice == '2'){
		displayimage(image, imageWidth, imageHeight);}
	else if(choice == '3'){
		editMenu(&echoice);}
	else if(choice == '0'){
		done(&fchoice, imageWidth, imageHeight, image);}
		return 0;
		
	if (echoice == '1'){
		cropimage(&imageWidth, &imageHeight, image);}
	else if (echoice == '2'){
	  dimimage(image);}
	else if (echoice == '3'){
	 	brightenimage(image);}
	else if(echoice == '0'){
		printf("Okay!\n");}
		



return 0;
}



void ogMenu(char *choice){
	do{
		printf("**ERINSTAGRAM**\n1: Load image\n2: Display image\n3: Edit image\n0: Exit\nChoose from one of the options above: ");
		scanf(" %c", choice);
	if(*choice != '1' && *choice !='2' && *choice != '3' && *choice != '0'){
		printf("Invalid Choice\n");}
	}
	while(*choice != '1' && *choice !='2' && *choice != '3' && *choice != '0');
}
	
	

void editMenu(char *echoice){
	do{
		printf("1: Crop Image \n2: Dim Image\n3: Brighten Image\n0: Exit\nChoose from one of the options above: ");
		scanf(" %c", echoice);
	if(*echoice != '1' && *echoice !='2' && *echoice != '3' && *echoice != '0'){
		printf("Invalid Choice\n");}
		}
	while(*echoice != '1' && *echoice !='2' && *echoice != '3' && *echoice != '0');
	}
	


void uploadimage(int image[][500]){	
char FILE_NAME[500];

	printf("Enter your file name : ");
	scanf("%s", FILE_NAME);

	FILE *readFilePointer = fopen(FILE_NAME, "r");
	
	if(readFilePointer == NULL){
		printf("Input file does not exist.\n");}
	else{for (int i = 0; i < 500; i++){
		for (int l = 0; l < 500; l++){
			fscanf(readFilePointer, "%d ", &image[i][l]);
			fclose(readFilePointer);
		}}}
	}



void displayimage(int image[][500], int imageWidth, int imageHeight){
	printf("Current Image: \n");
	for (int i = 0; i < imageWidth; i++){
		imageWidth = i;
		for (int j = 0; j < imageHeight; j++){
		imageHeight = j;
			printf("%d ", image[i][j]);		
	}}
}



void cropimage(int *imageWidth, int *imageHeight, int image [][500]){	
	int croppedWidth, croppedHeight;
	
	printf("Your currect max image height is 500x500\n");
	printf("Enter how much coordinates you would like to crop\n");
		scanf("%d %d", &croppedHeight, &croppedWidth);
			
			*imageHeight -=croppedHeight;
			*imageWidth -=croppedWidth;
		}

void dimimage(int image[][500]){
	char db;
	for (int i = 0; i < 500; i++){
	for (int l = 0; l < 500; l++){
		scanf(" %d ", &image[i][l]);
			if(db == '0'){ 
				db = 'O';} 
               		else if(db == 'O'){ 
                		db = 'o';} 
                	else if(db == 'o'){ 
                		db = '.';} 
                	else if (db == '.'){ 
                		db = ' ';} 
                	else if (db == ' '){ 
                		printf("Image cannot be any dimmer\n");}}}
}
	


void brightenimage(int image[][500]){
	char db;
	for (int i = 0; i < 500; i++){
	for (int l = 0; l < 500; l++){
		scanf("%d", &image[i][l]);
			if(db == ' '){ 
				db = '.';} 
               		else if(db == '.'){ 
                		db = 'o';} 
                	else if(db == 'o'){ 
                		db = 'O';} 
                	else if (db == 'O'){ 
                		db = '0';} 
                	else if (db == '0'){ 
                		printf("Image cannot be any brighter\n");}}}
	   }
	


void done(char *fchoice, int imageWidth, int imageHeight, int image[][500]){

	printf("Do you want to save your image? [Y/N]: ");
  	scanf(" %c", fchoice); 
do{

if(*fchoice == 'Y' || *fchoice == 'y'){
char FILE_NAME[500];
FILE* dest_fp;

	do{
        	printf("Enter the file name to save: ");
        	scanf("%s", FILE_NAME);
		
		dest_fp = fopen(FILE_NAME, "w");

		if (dest_fp == NULL) {
   			 printf("Can't open file\n");} 
   		else{
    			for (int i = 0; i < imageWidth; i++){
        			for (int j = 0; j < imageHeight; j++) {
            				fprintf(dest_fp, "%d ", image[i][j]);}
        	fprintf(dest_fp, "\n");}
    			printf("Image saved successfully.\n");
    				fclose(dest_fp);
}}
	while(dest_fp == NULL);}

else if(*fchoice == 'N' || *fchoice == 'n'){
        printf("Goodbye!\n");} 
else{
        printf("Invalid choice.\n");}
}
while(*fchoice != 'Y' && *fchoice !='y' && *fchoice != 'N' && *fchoice != 'n');
    }
    

