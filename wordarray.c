#include<stdio.h>
#include<string.h>
#include<conio.h>
#define size 200

//Write a program that asks the user to enter a sentence and separates this sentence into words and saves the words into a string array. 
//The sentence can be limited to 20 words. 
//Then save the words in a text file, one after the other. 
//The user may or may not have placed a period at the end of the sentence. 
//The code you write must provide both conditions.

int main(){
	
	FILE *f=fopen("words.txt","w");
	
	char sentence[size];
	
	int len=strlen(sentence);
	
	const char *space=" ";
	
	char *p=NULL;
	
	printf("Enter a sentence:");
	gets(sentence);
	
	int i=0,count=0;
	while(sentence[i]!='\0'){
		if(sentence[i]==' '){
			count++;
		}
		i++;
	}
	
	
	p=strtok(sentence,space);
	
	while(p!=NULL){
	
		fprintf(f,"%s\n",p);
		p=strtok(NULL,space);
	}

    
	fprintf(f,"\nAll words have been saved in words.txt file!\nThe sentence consists of %d words.",count+1);
    
	fclose(f);
	
	return 0;
}
