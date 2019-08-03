
char name[2][30]; //double dimensional array to store names of the player
int chance; //to store the chance, to track which player is to enter the move

int box; //to track the current box the player is on at the moment
char a[3][3]; //array to hold the actual values that player enter while playing
int navigate(char a[3][3], int box, int player, int key);
// to handle key presses and update the current box the player is on
// and to enter the move in to the box when player presses Enter.




int turns; // to count the number of chances




void putintobox(char a[3][3], char ch, int box);









//Function to show the Tic Tac Toe Frame
void showframe(int posx, int posy)
{

  int hr=196, vr=179; // These are ascii character which display the lines
  int crossbr=197;    // Another ascii character
  int x=posx, y=posy;
  int i,j;

  gotoxy(35,4); cprintf("TIC TAC TOE");
  gotoxy(35,5); for(i=0;i<11;i++) cprintf("%c",223);


  for(i=0;i<2;i++)
  {
    for(j=1;j<=11;j++)
     {
      gotoxy(x,y);
      printf("%c",hr);
      x++;p;    x++;
     }
    x=posx; y+=2;
  }
  x=posx+3; y=posy-1;

  for(i=0;i<2;i++)
  {

   for(j=1;j<=5;j++)
   {
      gotoxy(x,y);
      printf("%c",vr);
      y++;
   }
   x+=4;y=posy-1;
  }


  x=posx+3; y=posy;
  gotoxy(x,y);
  printf("%c",crossbr);

   x=posx+7; y=posy;
  gotoxy(x,y);
  printf("%c",crossbr);

  x=posx+3; y=posy+2;
  gotoxy(x,y);
  printf("%c",crossbr);

  x=posx+7; y=posy+2;
  gotoxy(x,y);
  printf("%c",crossbr);

}



//Function to show the character in the specified box
void showbox(char ch, int box)
{
   switch(box)
   {
     case 1 :	gotoxy(_x+1,_y-1); printf("%c",ch); break; //1st box
     case 2 :	gotoxy(_x+5,_y-1); printf("%c",ch); break; //2nd box
     case 3 :	gotoxy(_x+9,_y-1); printf("%c",ch); break; //3rd box
     case 4 :	gotoxy(_x+1,_y+1); printf("%c",ch); break; //4th box
     case 5 :	gotoxy(_x+5,_y+1); printf("%c",ch); break; //5th box
     case 6 :	gotoxy(_x+9,_y+1); printf("%c",ch); break; //6th box
     case 7 :	gotoxy(_x+1,_y+3); printf("%c",ch); break; //7th box
     case 8 :	gotoxy(_x+5,_y+3); printf("%c",ch); break; //8th box
     case 9 :	gotoxy(_x+9,_y+3); printf("%c",ch); break; //9th box
   }
}





//Function to insert the specified character into the array
void putintobox(char arr[3][3], char ch, int box)
{
  switch(box)
  {

    case 1 :	if(arr[0][0] != 'X' && arr[0][0]!= 'O')
                { arr[0][0] = ch;
		          showbox(ch,1);
		        }
		        break;

    case 2 :	if(arr[0][1] != 'X' && arr[0][1]!= 'O')
		        { arr[0][1] = ch;
		          showbox(ch,2);
		        }
		        break;

    case 3 :	if(arr[0][2] != 'X' && arr[0][2]!= 'O')
                { arr[0][2] = ch;
		          showbox(ch,3);
		        }
		        break;

    case 4 :	if(arr[1][0] != 'X' && arr[1][0]!= 'O')
		       { arr[1][0] = ch;
		         showbox(ch,4);
		       }
		        break;

    case 5 :	if(arr[1][1] != 'X' && arr[1][1]!= 'O')
		        { arr[1][1] = ch;
		         showbox(ch,5);
		        }
		        break;

    case 6 :	if(arr[1][2] != 'X' && arr[1][2]!= 'O')
		        { arr[1][2] = ch;
                  showbox(ch,6);
		        }
	        	break;

    case 7 :	if(arr[2][0] != 'X' && arr[2][0]!= 'O')
     		    { arr[2][0] = ch;
		          showbox(ch,7);
		        }
		        break;

    case 8 :	if(arr[2][1] != 'X' && arr[2][1]!= 'O')
		        { arr[2][1] = ch;
		          showbox(ch,8);
		        }
		        break;

    case 9 :	if(arr[2][2] != 'X' && arr[2][2]!= 'O')
		        { arr[2][2] = ch;
		          showbox(ch,9);
		        }
		        break;
   }//end of switch
}



//Function to show the curson on the box specified
//uses the position to check the coordinates
void gotobox(int box)
{
  switch(box)
  {
    case 1 : gotoxy(_x+1,_y-1); break;
    case 2 : gotoxy(_x+5,_y-1); break;
    case 3 : gotoxy(_x+9,_y-1); break;
    case 4 : gotoxy(_x+1,_y+1); break;
    case 5 : gotoxy(_x+5,_y+1); break; //5th box
    case 6 : gotoxy(_x+9,_y+1); break; //6th box
    case 7 : gotoxy(_x+1,_y+3); break; //7th box
    case 8 : gotoxy(_x+5,_y+3); break; //8th box
    case 9 : gotoxy(_x+9,_y+3); break;

  }
}


//Function to handle the navigation
int navigate(char arr[3][3], int box, int player, int key)
{
   switch(key)
   {
     case UPARROW    : if( (box!=1) || (box!=2) || (box!=3) )
		               { box-=3; if(box<1) box = 1; gotobox(box); }
	                   break;

     case DOWNARROW  : if( (box!=7) || (box!=8) || (box!=9) )
		               { box+=3; if(box>9) box = 9; gotobox(box); }
		               break;

     case LEFTARROW  : if( (box!=1) || (box!=4) || (box!=7) )
		               { box--;  if(box<1) box = 1; gotobox(box); }
		               break;

     case RIGHTARROW : if( (box!=3) || (box!=6) || (box!=9) )
		               { box++; if(box>9) box = 9; gotobox(box); }
		               break;

     case ENTER      : if(player == 0)
			            putintobox(arr,'O',box);
		               else if(player == 1)
			            putintobox(arr,'X',box);
		               break;
    }//end of switch(key)

 return box;
}


int checkforwin(char arr[3][3])
{
  int w=0;

/*  0,0   0,1   0,2
    1,0   1,1   1,2
    2,0   2,1   2,2
*/
  //rows
  if((arr[0][0] == arr[0][1]) && (arr[0][1] == arr[0][2])) w = 1;
  else if((arr[1][0] == arr[1][1]) && (arr[1][1] == arr[1][2])) w = 1;
  else if((arr[2][0] == arr[2][1]) && (arr[2][1] == arr[2][2])) w = 1;

  //coloums
  else if((arr[0][0] == arr[1][0]) && (arr[1][0] == arr[2][0])) w = 1;
  else if((arr[0][1] == arr[1][1]) && (arr[1][1] == arr[2][1])) w = 1;
  else if((arr[0][2] == arr[1][2]) && (arr[1][2] == arr[2][2])) w = 1;

  //diagonal
  else if((arr[0][0] == arr[1][1]) && (arr[1][1] == arr[2][2])) w = 1;
  else if((arr[0][2] == arr[1][1]) && (arr[1][1] == arr[2][0])) w = 1;

  return w;
}



int boxesleft(char a[3][3])
{
   int i,j,boxesleft=9;

   for(i=0;i<3;i++)
    { for(j=0;j<3;j++)
      { if((a[i][j] == 'X') ||(a[i][j] == 'O'))
          boxesleft--;
      }
    }

   return boxesleft;
}



#include <stdio.h>

int main()
{
    FILE *fh;
    int  ch;

    fh = fopen("ascii.txt","r");

    for(i=0;i<256;i++)
     fprint(fh,"\n%d - %c",i,i);

    fclose(fh);
    return 0;
}



#include <stdio.h>
#include <conio.h>

int main()
{
    /*
      Declaration of variables used
    */

    showframe(12,25);
    printf("\nPlayer 1, enter your name:"); fgets(name[0], 30, stdin);
    printf("\nPlayer 2, enter your name:"); fgets(name[1], 30, stdin);

    printf("\n%s, you take 0",name[0]);
    printf("\n%s, you take X",name[1]); getch();

    clrscr();

    do
    {
       while(!enter)
       {
         if(khbit())
          ch = getch();

           switch(ch)
           {
             case UPARROW : box = navigate(a[3][3], box, player, UPARROW);
             .
             .
             .
           }
       }
       if(quit) break;
       //check if the player wins
       win = checkforwin(a);

     }while(!win)

    if(win)
    { .
      .
    }

    else if(quit)
    {    .
         .
    }

 return 0;
}






