#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>

wchar_t Input[65535];// 16bits array which contains the file input
wchar_t leter_l=0;
int n=0, position_counter=0, tamano=0;

/*Functions declarations*/
int find_text (wchar_t Crypt_test [65535]);
int length(wchar_t cad[65535],int position);
char key[255];

int main()
	{
	FILE *document;
	char character;
	document = fopen("test.doc","rt");
	if (document == NULL)
		{
		printf("\nCould not read the file. \n\n");
        }
    else
    	{
	    /* Copy the file content into a string for easier manipulation*/
	    /*"feof" detects the end of the file*/
	    while (feof(document) == 0)
		    {
			character = fgetwc(document);
			leter_l = character;
			Input[n] = leter_l;
			n++;
		    }
        }
    /*Close the file*/
    fclose(document);
		printf("\nInsert your key by selecting the following characters: ABEHIKMNOPTYZbegos\n");
		scanf("%s",&key);
		printf("\nYour key is %s\n",key);
		find_text(Input);
		printf ("\nWater mark inserted\n");
	return 0;
	}
/*Inserta la marca de agua en la cadena*/
int find_text (wchar_t Crypt_test [65535])
	{
	FILE * pFile;
	int i,x;
	tamano=length(Crypt_test, position_counter);
	pFile = fopen ("watermark.doc", "wt, ccs = UNICODE");
	for(x=0;key[x]!= '\0';x++)
	{
	for(i=position_counter;i<=(tamano-2);i++)
		{
		if(Input[i] == 'X' && key[x] == 'X'){Input[i]=0x3A7;}
		else if(Input[i] == 'A' && key[x] == 'A'){Input[i]=0x391;}
		else if(Input[i] == 'B' && key[x] == 'B'){Input[i]=0x392;}
		else if(Input[i] == 'E' && key[x] == 'E'){Input[i]=0x395;}
		else if(Input[i] == 'H' && key[x] == 'H'){Input[i]=0x397;}
		else if(Input[i] == 'I' && key[x] == 'I'){Input[i]=0x399;}
		else if(Input[i] == 'K' && key[x] == 'K'){Input[i]=0x39A;}
		else if(Input[i] == 'M' && key[x] == 'M'){Input[i]=0x39C;}
		else if(Input[i] == 'N' && key[x] == 'N'){Input[i]=0x39D;}
		else if(Input[i] == 'O' && key[x] == 'O'){Input[i]=0x39F;}
		else if(Input[i] == 'P' && key[x] == 'P'){Input[i]=0x3A1;}
		else if(Input[i] == 'T' && key[x] == 'T'){Input[i]=0x3A4;}
		else if(Input[i] == 'Y' && key[x] == 'Y'){Input[i]=0x3A5;}
		else if(Input[i] == 'Z' && key[x] == 'Z'){Input[i]=0x3A6;}
		else if(Input[i] == 'b' && key[x] == 'b'){Input[i]=0x185;}
		else if(Input[i] == 'e' && key[x] == 'e'){Input[i]=0x435;}
		else if(Input[i] == 'g' && key[x] == 'g'){Input[i]=0x261;}
		else if(Input[i] == 'o' && key[x] == 'o'){Input[i]=0x43E;}
		else if(Input[i] == 's' && key[x] == 's'){Input[i]=0x455;}
		else if(Input[i] == 10){Input[i]= 0x0D;}
		else{Input[i]= Input[i];}
		}
	}
	fwrite(Input , sizeof(wchar_t), (tamano-1), pFile);
	fclose (pFile);
	return 0;
	}
/*Returns the string size*/
int length(wchar_t cad[65535], int position)
	{
	while (((cad[position]!=10)||(cad[position+1]!=10))&&(cad[position]!='\0'))
		{
		position++;
		}
	return position;
	}
