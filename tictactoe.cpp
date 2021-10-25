#include <iostream>
#include <string>

using namespace std;

int game(char A[5][5], int n) // 1 means player one won, 2 means player two won, 3 means a tie, 4 means the game continues
{
	if(A[0][0]==A[0][2] && A[0][2]==A[0][4] && A[0][4]=='X')
	{
		return 1;
	}
	else if(A[2][0]==A[2][2] && A[2][2]==A[2][4] && A[2][4]=='X')
	{
		return 1;
	}
	else if(A[4][0]==A[4][2] && A[4][2]==A[4][4] && A[4][4]=='X')
	{
		return 1;
	}
	else if(A[0][0]==A[0][2] && A[0][2]==A[0][4] && A[0][4]=='O')
	{
		return 2;
	}
	else if(A[2][0]==A[2][2] && A[2][2]==A[2][4] && A[2][4]=='O')
	{
		return 2;
	}
	else if(A[4][0]==A[4][2] && A[4][2]==A[4][4] && A[4][4]=='O')
	{
		return 2;
	}
	else if(A[0][0]==A[2][0] && A[2][0]==A[4][0] && A[4][0]=='X')
	{
		return 1;
	}
	else if(A[0][2]==A[2][2] && A[2][2]==A[4][2] && A[4][2]=='X')
	{
		return 1;
	}
	else if(A[0][4]==A[2][4] && A[2][4]==A[4][4] && A[4][4]=='X')
	{
		return 1;
	}
	else if(A[0][0]==A[2][0] && A[2][0]==A[4][0] && A[4][0]=='O')
	{
		return 2;
	}
	else if(A[0][2]==A[2][2] && A[2][2]==A[4][2] && A[4][2]=='O')
	{
		return 2;
	}
	else if(A[0][4]==A[2][4] && A[2][4]==A[4][4] && A[4][4]=='O')
	{
		return 2;
	}
	else if(A[0][0]==A[2][2] && A[2][2]==A[4][4] && A[4][4]=='X')
	{
		return 1;
	}
	else if(A[0][0]==A[2][2] && A[2][2]==A[4][4] && A[4][4]=='O')
	{
		return 2;
	}
	else if(A[0][4]==A[2][2] && A[2][2]==A[4][0] && A[4][0]=='X')
	{
		return 1;
	}
	else if(A[0][4]==A[2][2] && A[2][2]==A[4][0] && A[4][0]=='O')
	{
		return 2;
	}
	else if(n<9)
	{
		return 4;
	}
	else
	{
		return 3;
	}
}

int main()
{
	char board[5][5];	


	cout<<"\n\n  WELCOME TO TIC TAC TOE\n";
	cout<<"--------------------------\n\n";

	int q;

	cout<<"\n PRESS 1 TO PLAY OR -1 TO QUIT\n";
	cin>>q;

	while(q==1)
	{
		cout<<"\n\n GAME STARTS\n\n";

		for(int i=0; i<5; i++)  //creating board
		{
			for(int j=0; j<5; j++)
				board[i][j]=' ';
		}
		for(int i=0; i<5; i++) 
		{
			for(int j=0; j<5; j++)
			{
				if(i==1 || i==3)
				{
					if(j==0 || j==2 || j==4)
					{
						board[i][j]='-';
					}	
				}
			
				if(i==0 || i==2 || i==4)
				{
					if(j==1 || j==3)
					{
						board[i][j]='|';
					}
				}

				if(i==0 || i==2 || i==4)
				{
					if(j==0 || j==2 || j==4)
					{
						board[i][j]='?';
					}
				}
			}	
		}

		int move = 0; // number of moves
		int turn = 1; // if turn = 1, player 1 plays... if turn = 2, player 2 plays
		int winner;

		while(game(board, move)==4)
		{
			if(turn==1)
			{
				cout<<"First person's move\n";
				cout<<"Row, Column\n";
			
				int r, c;
				cin>>r>>c;

				if((r==0 || r==2 || r==4)  && (c==0 || c==2 || c==4))
				{
					board[r][c]='X';
					turn=2;
				}
				else
				{
					cout<<"\nTry entring values such as 0, 2 or 4\n";
					turn=1;
				}
				
			}
			else
			{
				cout<<"Second person's move\n";
				cout<<"Row, Column\n";
			
				int r, c;
				cin>>r>>c;

				if((r==0 || r==2 || r==4)  && (c==0 || c==2 || c==4))
				{
					board[r][c]='O';
					turn=1;
				}
				else
				{
					cout<<"Try entring values such as 0, 2 or 4\n";
					turn=2;
				}

				
			}

			cout<<endl;

			for(int i=0; i<5; i++)
			{
				for(int j=0; j<5; j++)
				{
					cout<<board[i][j];
				}
				cout<<endl;
			}

			cout<<endl;

			move++;
			winner = game(board, move);
		}

		if(winner==1)
		{
			cout<<"\n***PLAYER 1 HAS WON*\n";
		}

		else if(winner==2)
		{
			cout<<"\n***PLAYER 2 HAS WON*\n";
		}
		else 
			cout<<"\n***TIE*\n";



		cout<<"\nPRESS 1 TO PLAY OR -1 TO QUIT\n";
		cin>>q;
	}

	cout<<"\n\n BYE BYE!\n\n";	
}
