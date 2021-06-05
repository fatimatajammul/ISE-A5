#include <iostream>
#include <fstream>
#include <string>
#include<cstdlib>
#include <ctime>
using namespace std;

class helper
{
public:
	static int stringlenght( char* str )
	{
		int count =0;
		for(int i=0;i<str[i]!='\0';i++){                          //calculates the length of string
			count++;
		}
		return count;
	}
	static char* getstringfrombuffer(char* str)
	{
		char* B = 0;
		int B_Length = stringlenght(str);
		if (B_Length > 0){	
			B = new char[B_Length+1];  
			char* tempD = B;
			for (char* temp = str; *temp != '\0'; temp++, tempD++)
				*tempD = *temp;                                                 //deep copy
			*tempD = '\0';
		}
		return B;
	}

	static char* FileName(char* toconvert)
	{
		int length;
		length=helper::stringlenght(toconvert);
		char* temp= new char[length+5];
		int i;
		for( i=0; i<length; i++)
		{
			temp[i]=toconvert[i];
		}
		temp[i]='.';
		temp[i]='t';
		temp[i]='x';
		temp[i]='t';
		temp[i]='\0';

		return temp;


	}
	
};

bool FindingWords( ofstream& OUT,char**& Puzzle, char* temparr, int twords, int trows, int tcols)
{
	
	int A=0;
	int startrow, startcol, endcol, endrow;
	int templength,K,J;

	templength=helper::stringlenght(temparr);            //storing length of the word

	for(int j=0; j<trows; j++)
	{
		for(int k=0; k<tcols; k++)
		{
			int h=0;
			if(Puzzle[j][k]==temparr[h])
			{
				startrow=j;
				startcol=k;

				//left to right
				 K=k+1;
				for(int g=1; g<templength; g++)   
				{
					if(j>=0 && K>=0 && j<trows && K<tcols)
					{
						if(Puzzle[j][K]==temparr[g])
						{
							A++;
							K++;
						}
					}
					
				
				}
				endrow=j;
				endcol=K-1;
				if(A==templength-1)
				{
					OUT<<"{"<<startrow<<","<<startcol<<"}{"<<endrow<<","<<endcol<<"}"<<endl<<endl;
					return true;
				}
				A=0;
				
				//Right to left
				K=k-1;
				for(int g=1; g<templength; g++)   
				{
					if(j>=0 && K>=0 && j<trows && K<tcols)
					{
						if(Puzzle[j][K]==temparr[g])
						{
							A++;
							K--;
						}
					}
					
				
				}
				endrow=j;
				endcol=K+1;
				if(A==templength-1)
				{
					OUT<<"{"<<startrow<<","<<startcol<<"}{"<<endrow<<","<<endcol<<"}"<<endl<<endl;
					return true;
				}
				A=0;

				//top to bottom
				K=j+1;
				for(int g=1; g<templength; g++)   
				{
					if(k>=0 && K>=0 && K<trows && k<tcols)
					{
						if(Puzzle[K][k]==temparr[g])
						{
							A++;
							K++;
						}
					}
					
				
				}
				endrow=K-1;
				endcol=k;
				if(A==templength-1)
				{
					OUT<<"{"<<startrow<<","<<startcol<<"}{"<<endrow<<","<<endcol<<"}"<<endl<<endl;
					return true;
				}
				A=0;
				
				//bottom left to top right
				K=j-1;
				for(int g=1; g<templength; g++)   
				{
					if(k>=0 && K>=0 && K<trows && k<tcols)
					{
						if(Puzzle[K][k]==temparr[g])
						{
							A++;
							K--;
						}
					}
					
				
				}
				endrow=K+1;
				endcol=k;
				if(A==templength-1)
				{
					OUT<<"{"<<startrow<<","<<startcol<<"}{"<<endrow<<","<<endcol<<"}"<<endl<<endl;
					return true;
				}
				A=0;

				//bottom left to top right
				J=j-1;
				K=k+1;
				for(int g=1; g<templength; g++)   
				{
					if(J>=0 && K>=0 && J<trows && K<tcols)
					{
						if(Puzzle[J][K]==temparr[g])
						{
							A++;
							K++;
							J--;
						}
					}
					
				
				}
				endrow=J+1;
				endcol=K-1;
				if(A==templength-1)
				{
					OUT<<"{"<<startrow<<","<<startcol<<"}{"<<endrow<<","<<endcol<<"}"<<endl<<endl;
					return true ;
				}
				A=0;

				//top right to bottom left
				J=j+1;
				K=k-1;
				for(int g=1; g<templength; g++)   
				{
					if(J>=0 && K>=0 && J<trows && K<tcols)
					{
						if(Puzzle[J][K]==temparr[g])
						{
							A++;
							K--;
							J++;
						}
					}
					
				
				}
				endrow=J-1;
				endcol=K+1;
				if(A==templength-1)
				{
					OUT<<"{"<<startrow<<","<<startcol<<"}{"<<endrow<<","<<endcol<<"}"<<endl<<endl;
					return true ;
				}
				A=0;

				//Bottom right to top left
				J=j-1;
				K=k-1;
				for(int g=1; g<templength; g++)   
				{
					if(J>=0 && K>=0 && J<trows && K<tcols)
					{
						if(Puzzle[J][K]==temparr[g])
						{
							A++;
							K--;
							J--;
						}
					}
					
				
				}
				endrow=J+1;
				endcol=K+1;
				if(A==templength-1)
				{
					OUT<<"{"<<startrow<<","<<startcol<<"}{"<<endrow<<","<<endcol<<"}"<<endl<<endl;
					return true ;
				}
				A=0;

				//top left TO bottom right
				J=j+1;
				K=k+1;
				for(int g=1; g<templength; g++)   
				{
					if(J>=0 && K>=0 && J<trows && K<tcols)
					{
						if(Puzzle[J][K]==temparr[g])
						{
							A++;
							K++;
							J++;
						}
					}
					
				
				}
				endrow=J-1;
				endcol=K-1;
				if(A==templength-1)
				{
					OUT<<"{"<<startrow<<","<<startcol<<"}{"<<endrow<<","<<endcol<<"}"<<endl<<endl;
					return true;
				}
				
				A=0;

			}
		}

	}
	return false;
	
}

void SearchWords(string wordsinput, string gridinput, string outputfile)
{
	
    ifstream fin(wordsinput.c_str());
	int trows, tcols, twords;
	fin>>trows;
	fin>>tcols;                         //input
	fin>>twords;

	ofstream OUT(outputfile.c_str());

	char ** WordsArray=new char *[twords];
	for(int i=0; i<twords; i++)
	{
		WordsArray[i]= new char [40];                   //storing all n words in 2D dynamic array
	}
	fin.ignore();
	for(int i=0; i<twords; i++)
	{
		fin.getline(WordsArray[i],40);                //input of words to find
		
	}

	char** Puzzle= new char*[trows];
	for(int i=0; i<trows; i++)
	{
		Puzzle[i]=new char[tcols];
	}

	ifstream CIN(gridinput.c_str());
	
	for(int r=0; r<trows; r++)
    {
    	for(int c=0; c<tcols; c++)
		{
			CIN>>Puzzle[r][c];
		}
	}
	
	for(int i=0; i<twords; i++)
	{
		if(FindingWords( OUT,Puzzle, WordsArray[i] , twords, trows, tcols)==false)       //finding words
			OUT<<"Not Found"<<endl<<endl;
	}

	fin.close();
	CIN.close();
	
	for(int i=0; i<twords; i++)
	{
		delete[] WordsArray[i];                              //deallocation of dynamic array
		WordsArray[i]=0;
	}
	
	delete[] WordsArray;
	WordsArray=0;

	for(int i=0; i<trows; i++)
	{
		delete[] Puzzle[i];                              //deallocation of dynamic array
		Puzzle[i]=0;
	}
	
	delete[] Puzzle;
	Puzzle=0;
}

bool Place_Left_to_Right(char**& Grid, char* arr, int Rows, int Cols)
{
	int r,c;
	int A=0;
	int wordlength;
	wordlength=helper::stringlenght(arr);
	for(int i=0; i<Rows; i++)
	{
		for(int j=0; j<Cols; j++)
		{
			r=i;
			c=j;
			for(int k=0; k<wordlength; k++)
			{
				if(r<Rows && c<Cols && r>=0 && c>=0)
				{
					if(Grid[r][c]=='-' || Grid[r][c]==arr[k])
					{
						A++;
						c++;
					}
				}
			}
			if(A==wordlength)
			{
				r=i;
				c=j;
				for(int I=0; I<wordlength; I++)
				{
					Grid[r][c]=arr[I];
					c++;
				}
				return true;
			}
			A=0;
		}
	}
	return false;
}

bool Place_Right_to_Left(char**& Grid, char* arr, int Rows, int Cols)
{
	int A=0;
	int r;
	int c;
	int wordlength;
	wordlength=helper::stringlenght(arr);
	for(int i=0; i<Rows; i++)
	{
		for(int j=0; j<Cols; j++)
		{
			r=j;
		    c=i;
			for(int k=0; k<wordlength; k++)
			{
				if(r<Rows && c<Cols && r>=0 && c>=0)
				{
					if(Grid[r][c]=='-'|| Grid[r][c]==arr[k] )
					{
						A++;
						c--;
					}
					
				}
			}
			if(A==wordlength)
			{
				r=j;
				c=i;

				for(int I=0; I<wordlength; I++)
				{
					Grid[r][c]=arr[I];
					c--;
				}
				return true;
			}
			A=0;
		}
	}
	return false;
}

bool Place_Top_to_Bottom(char**& Grid, char* arr, int Rows, int Cols)
{
	int A=0;
	int r;
	int c;
	int wordlength;
	wordlength=helper::stringlenght(arr);
	for(int i=0; i<Rows; i++)
	{
		for(int j=0; j<Cols; j++)
		{
			r=j;
		    c=i;
			for(int k=0; k<wordlength; k++)
			{
				if(r<Rows && c<Cols && r>=0 && c>=0)
				{
					if(Grid[r][c]=='-' || Grid[r][c]==arr[k] )
					{
						A++;
						r++;
					}
					
				}
			}
			if(A==wordlength)
			{
				r=j;
				c=i;

				for(int I=0; I<wordlength; I++)
				{
					Grid[r][c]=arr[I];
					r++;
				}
				return true;
			}
			A=0;
		}
	}
	return false;
}

bool Place_Bottom_to_Top(char**& Grid, char* arr, int Rows, int Cols)
{
	int A=0;
	int r;
	int c;
	int wordlength;
	wordlength=helper::stringlenght(arr);
	for(int i=0; i<Rows; i++)
	{
		for(int j=0; j<Cols; j++)
		{
			r=j;
		    c=i;
			for(int k=0; k<wordlength; k++)
			{
				if(r<Rows && c<Cols && r>=0 && c>=0)
				{
					if(Grid[r][c]=='-' || Grid[r][c]==arr[k])
					{
						A++;
						r--;
					}
					
				}
			}
			if(A==wordlength)
			{
				r=j;
				c=i;

				for(int I=0; I<wordlength; I++)
				{
					Grid[r][c]=arr[I];
					r--;
				}
				return true;
			}
			A=0;
		}
	}
	return false;
}

bool Place_BottomLeft_to_TopRight(char**& Grid, char* arr, int Rows, int Cols)
{
	int A=0;
	int r;
	int c;
	int wordlength;
	wordlength=helper::stringlenght(arr);
	for(int i=0; i<Rows; i++)
	{
		for(int j=0; j<Cols; j++)
		{
			r=j;
		    c=i;
			for(int k=0; k<wordlength; k++)
			{
				if(r<Rows && c<Cols && r>=0 && c>=0)
				{
					if(Grid[r][c]=='-' || Grid[r][c]==arr[k])
					{
						A++;
						r--;
						c++;
					}
					
				}
			}
			if(A==wordlength)
			{
				r=j;
				c=i;

				for(int I=0; I<wordlength; I++)
				{
					Grid[r][c]=arr[I];
					r--;
					c++;
				}
				return true;
			}
			A=0;
		}
	}
	return false;
}

bool Place_TopRight_to_BottomLeft(char**& Grid, char* arr, int Rows, int Cols)
{
	int A=0;
	int r;
	int c;
	int wordlength;
	wordlength=helper::stringlenght(arr);
	for(int i=0; i<Rows; i++)
	{
		for(int j=0; j<Cols; j++)
		{
			r=j;
		    c=i;
			for(int k=0; k<wordlength; k++)
			{
				if(r<Rows && c<Cols && r>=0 && c>=0)
				{
					if(Grid[r][c]=='-' || Grid[r][c]==arr[k])
					{
						A++;
						r++;
						c--;
					}
					
				}
			}
			if(A==wordlength)
			{
				r=j;
				c=i;

				for(int I=0; I<wordlength; I++)
				{
					Grid[r][c]=arr[I];
					r++;
					c--;
				}
				return true;
			}
			A=0;
		}
	}
	return false;
}

bool Place_BottomRight_to_TopLeft(char**& Grid, char* arr, int Rows, int Cols)
{
	int A=0;
	int r;
	int c;
	int wordlength;
	wordlength=helper::stringlenght(arr);
	for(int i=0; i<Rows; i++)
	{
		for(int j=0; j<Cols; j++)
		{
			r=j;
		    c=i;
			for(int k=0; k<wordlength; k++)
			{
				if(r<Rows && c<Cols && r>=0 && c>=0)
				{
					if(Grid[r][c]=='-' || Grid[r][c]==arr[k])
					{
						A++;
						r--;
						c--;
					}
					
				}
			}
			if(A==wordlength)
			{
				r=j;
				c=i;

				for(int I=0; I<wordlength; I++)
				{
					Grid[r][c]=arr[I];
					r--;
					c--;
				}
				return true;
			}
			A=0;
		}
	}
	return false;
}

bool Place_TopLeft_to_BottomRight(char**& Grid, char* arr, int Rows, int Cols)
{
	int A=0;
	int r;
	int c;
	int wordlength;
	wordlength=helper::stringlenght(arr);
	for(int i=0; i<Rows; i++)
	{
		for(int j=0; j<Cols; j++)
		{
			r=j;
		    c=i;
			for(int k=0; k<wordlength; k++)
			{
				if(r<Rows && c<Cols && r>=0 && c>=0)
				{
					if(Grid[r][c]=='-' || Grid[r][c]==arr[k])
					{
						A++;
						r++;
						c++;
					}
					
				}
			}
			if(A==wordlength)
			{
				r=j;
				c=i;

				for(int I=0; I<wordlength; I++)
				{
					Grid[r][c]=arr[I];
					r++;
					c++;
				}
				return true;
			}
			A=0;
		}
	}
	return false;
}


void WordsGrid( string NameInput, string NameOutput, int No_of_words, int Rows, int Cols)
{
	ifstream IN(NameInput.c_str());
	ofstream out(NameOutput.c_str());
	int length;
	char ** temp=new char *[No_of_words];
	char* Temporary= new char[30];
	for(int i=0; i<No_of_words; i++)
	{
		IN.getline(Temporary,30);
		temp[i]= helper::getstringfrombuffer(Temporary);                 //storing all words in 2D dynamic temporary array
	}


	char ** WordsArray=new char *[No_of_words];
	for(int i=0; i<No_of_words; i++)
	{
		if(i==No_of_words-1)
			WordsArray[i]= new char[helper::stringlenght(temp[i])];
		else
			WordsArray[i]= new char[helper::stringlenght(temp[i])+1];                   //storing all words in 2D dynamic after conversion in capital letters 
	}

	for(int i=0; i<No_of_words; i++)
	{
		char* arr=0;
		arr=temp[i];
		WordsArray[i][0]=arr[0];
		int j=1;
		int k=1;
		for(; arr[j]!='\0'; j++, k++)
		{
			if(arr[j]==' ')
			{
				//WordsArray[i][j]=arr[j];
				WordsArray[i][k]=arr[j+1];
				k=k+1;
				j=j+2;
			}
			WordsArray[i][k]=arr[j]-32;
		}
		WordsArray[i][k]='\0';

		delete[] arr;
		arr=0;

	}

	int maxlength=0;

	for(int i=0; i<No_of_words; i++)
	{
		length=helper::stringlenght(WordsArray[i]);
		if(maxlength<=length)
			maxlength=length;
	}

	char anycharacter;
	if(maxlength>Rows || maxlength>Cols)
	{
		cout<<"Grid cannot be formed, press any key to return to the home screen";
		cin>>anycharacter;
		
		return;
	}
	else
	{
		
	
		char* temporary;
		int i,j;
		for(i=0; i<No_of_words-1; i++)
		{
			for(j=0; j<No_of_words-1-i; j++)
			{
				if(helper::stringlenght(WordsArray[j]) < helper::stringlenght(WordsArray[j+1]))
				{
					temporary=WordsArray[j+1];
					WordsArray[j+1]=WordsArray[j];                 //sorting algorithm
					WordsArray[j]=temporary;
				
				}
			}
		}

	
	
	


		char ** Grid= new char *[Rows];
		for(int i=0; i<maxlength; i++)
		{
			Grid[i]= new char [Cols];                   //storing all words in 2D dynamic after conversion in capital letters 
		}

		for(int i=0; i<Rows; i++)
		{
			for(int j=0; j<Cols; j++)
				Grid[i][j]='-';
		}
	
	
		srand((unsigned)time(0));   // Initialize random number generator.
		int randomNo,Randomnotemp;
		for(int i=0; i<No_of_words; i++)
		{
			Randomnotemp=10;
			for(int j=0; ;j++)
			{
				randomNo=1+(rand() % 8) + 1;
				for(int k=0; randomNo==Randomnotemp; k++)
				{
					randomNo=1+(rand() % 8) + 1;
				}
				Randomnotemp=randomNo;
				if(randomNo==2)
				{
					if(Place_Left_to_Right( Grid,WordsArray[i], Rows, Cols)==true)
						break;
				}
				if(randomNo==3)
				{
					if(Place_Right_to_Left( Grid,WordsArray[i], Rows, Cols)==true)
						break;
				}
				if(randomNo==4)
				{
					if(Place_Top_to_Bottom( Grid,WordsArray[i],Rows, Cols)==true)
						break;
				}
				if(randomNo==5)
				{
					if(Place_Bottom_to_Top( Grid,WordsArray[i], Rows, Cols)==true)
						break;
				}
				if(randomNo==6)
				{
					if(Place_BottomLeft_to_TopRight( Grid,WordsArray[i],Rows, Cols)==true)
						break;
				}
				if(randomNo==7)
				{
					if(Place_TopRight_to_BottomLeft( Grid,WordsArray[i],Rows, Cols)==true)
						break;
				}
				if(randomNo==8)
				{
					if(Place_BottomRight_to_TopLeft( Grid,WordsArray[i], Rows, Cols)==true)
						break;
				}
				if(randomNo==9)
				{
					if(Place_TopLeft_to_BottomRight( Grid,WordsArray[i], Rows, Cols)==true)
						break;
				}
			
			}
		

		}
		cout<<endl<<endl;
		for(int i=0; i<Rows; i++)
		{
			for(int j=0; j<Cols; j++)
			{
				if(Grid[i][j]=='-')
					Grid[i][j]= 'A' + rand() % 26;
			}
		}
	
		 for(int i=0; i<Rows; i++)
		{
			for(int j=0; j<Cols; j++)
				out<<Grid[i][j]<<" ";
			out<<endl;
		}
	

		 for(int i=0; i<Rows; i++)
		{
			delete[] Grid[i];
			Grid[i]=0;
		}
		delete[] Grid;
		Grid=0;
	
	}
		
	
	
}

void main()
{
	char UserChoice='A';
	char anykey;
	int No_of_words, Rows, Cols;
	string  NameInput, NameOutput, NameSearch, NameGrid, Nameoutput;

	for(int i=0; UserChoice!='Q'; i++)
	{
		cout<<"1) Create Grid"<<endl<<endl;
		cout<<"2) Search Words from Grid"<<endl<<endl;
		cout<<"3) Quit"<<endl<<endl;
		cout<<"Enter your choice:\t";

		cin>>UserChoice;	
		cout<<endl;

		if(UserChoice=='C')
		{
			cout<<"1) Name of the input file:\t";
			cin>>NameInput; 
			cout<<endl;
			cout<<"2) Number of words in the file:\t";
			cin>>No_of_words;
			cout<<endl;
			cout<<"3) Number of rows in the grid:\t";
			cin>>Rows;    
			cout<<endl;
			cout<<"4) Number of columns in the grid:\t";
			cin>>Cols;    
			cout<<endl;
			cout<<"5) Name of the output file where the grid needs to be placed:\t";
			cin>>NameOutput;    
			cout<<endl;
			WordsGrid(NameInput, NameOutput, No_of_words, Rows, Cols);
	        cout<<"Press Any Key to return to the main menu\t";
			cin>>anykey;

		}
		if(UserChoice=='S')
		{
			cout<<"1) Name of the input file which has a grid in it:\t";
			cin>>NameGrid;
			cout<<endl;
			cout<<"2) Name of the file with input to be searched:\t";
			cin>>NameSearch;
			cout<<endl;
			cout<<"3) Name of the output file:\t";
			cin>>Nameoutput;    
			cout<<endl;
		 
			SearchWords(NameSearch,NameGrid,Nameoutput);
			cout<<"Press Any Key to return to the main menu\t";
			cin>>anykey;
	
		}
		
	}
	

	if(UserChoice=='Q')
	{
		system("pause");
		return;
	}


	system("pause");
}