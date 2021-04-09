//戻り値 1 配置不可
//戻り値 2 配置可
#include <stdio.h>

/*盤面の表示を行う関数*/
int display(int bord[11][11], int have_1[12],int have_2[12])
{
	int loop1;
	int loop2;
	int loop3;
	int koma;

	/*P2持駒の表示*/
	printf("持駒 P2 ");

	for (loop1 = 0, loop2 = 1; loop1 <= 11; loop1++)
	{
		if (have_2[loop1] != 0)
		{
			switch (loop1)
			{
			case 0:
				printf("%d：飛×%d、",loop2,have_2[loop1]);
				loop2++;
				break;
			case 2:
				printf("%d：角×%d、",loop2,have_2[loop1]);
				loop2++;
				break;
			case 4:
				printf("%d：金×%d、", loop2, have_2[loop1]);
				loop2++;
				break;
			case 5:
				printf("%d：銀×%d、", loop2, have_2[loop1]);
				loop2++;
				break;
			case 7:
				printf("%d：桂×%d、", loop2, have_2[loop1]);
				loop2++;
				break;
			case 9:
				printf("%d：香×%d、", loop2, have_2[loop1]);
				loop2++;
				break;
			case 11:
				printf("%d：歩×%d、", loop2, have_2[loop1]);
				loop2++;
				break;
			}
		}
	}
	printf("\n\n");



	/*盤面の表示*/
	for (loop1 = 0; loop1 < 10; loop1++)
	{
		/*盤面の横列表示*/
		for (loop3 = 9; loop3 > 0; loop3--)
		{
			if ((loop1 == 0) && (loop3 != 0))
			{
				printf("   %d  ", loop3);
			}

			if (loop1 == 0)
			{
				printf(" ");
			}

			if (loop1 != 0)
			{
				printf("------+");
			}
		}

		printf("\n");
		if (loop1 != 0)
		{
			printf(" ");
		}
		else
		{
			printf("--");
		}

		/*駒の判定*/
		for (loop2 = 1; loop2 < 10 && loop1 != 0; loop2++)
		{
			koma = bord[loop1][loop2] % 14;

			if (bord[loop1][loop2] > 0)
			{
				switch (koma)
				{
				case 1:
					printf("|王将");
					break;
				case 2:
					printf("|飛車");
					break;
				case 3:
					printf("|成飛");
					break;
				case 4:
					printf("|角行");
					break;
				case 5:
					printf("|成角");
					break;
				case 6:
					printf("|金将");
					break;
				case 7:
					printf("|銀将");
					break;
				case 8:
					printf("|成銀");
					break;
				case 9:
					printf("|桂馬");
					break;
				case 10:
					printf("|成桂");
					break;
				case 11:
					printf("|香車");
					break;
				case 12:
					printf("|成香");
					break;
				case 13:
					printf("|歩　");
					break;
				case 0:
					printf("|成歩");
					break;
				}


				if (bord[loop1][loop2] < 15)
				{
					printf("↑");
				}
				else
				{
					printf("↓");
				}
			}

			if (bord[loop1][loop2] == 0)
			{
				printf("|　　  ");
			}
		}
		if (loop1 != 0)
		{
			printf("| %d\n", loop1);
			printf("--");
		}
	}

	/*P1持駒の表示*/
	printf("\n持駒 P1 ");
	for (loop1 = 0, loop2 = 1; loop1 <= 11; loop1++)
	{
		if (have_1[loop1] != 0)
		{
			switch (loop1)
			{
			case 0:
				printf("%d：飛×%d、", loop2, have_1[loop1]);
				loop2++;
				break;
			case 2:
				printf("%d：角×%d、", loop2, have_1[loop1]);
				loop2++;
				break;
			case 4:
				printf("%d：金×%d、", loop2, have_1[loop1]);
				loop2++;
				break;
			case 5:
				printf("%d：銀×%d、", loop2, have_1[loop1]);
				loop2++;
				break;
			case 7:
				printf("%d：桂×%d、", loop2, have_1[loop1]);
				loop2++;
				break;
			case 9:
				printf("%d：香×%d、", loop2, have_1[loop1]);
				loop2++;
				break;
			case 11:
				printf("%d：歩×%d、", loop2, have_1[loop1]);
				loop2++;
				break;
			}
		}
	}
	printf("\n");
}
//-------------------------------------------------------------------------------------------------------------------------------
int have_put(int board[][],int have[],int have_choice,int x_put,int y_put,int player_num)
{
	int i,j,flag=0;

	if((board[x_put][y_put]>=1)&&(board[x_put][y_put]<=28))
	{
		printf("コマが置かれています.\n指し直してください.\n");
		return 1;
	}
	else if(x_put <= 0 || x_put >= 10 || y_put <= 0 || y_put >= 10)
	{
		printf("盤面外です.\n指し直してください.\n");
		return 1;
	}
	else
	{
		for(i=0;i<12;i++)
	  	{
			if(have[i]!=0)
			{
				flag++;
			}
			if(flag==have_choice)
			{
				have[i];
				if(i==11)
				{
					for(j=1;j<10;i++)
					{
						if(board[j][y_put]==13+14*(player_num-1))
						{
							printf("2歩です.\n指し直してください.\n");
							return 1;
						}
					}
				}
				if(player_num==1)
				{
					board[x_put][y_put]=i+2;
					return 2;
				}
				if(player_num==2)
				{
					board[x_put][y_put]=i+16;
					return 2;
				}
			}
		}
	}
	return 1;
}
//------------------------------------------------------------------------------------------------------------------------------------------------
int kin_1(int board[11][11],int have[],int x_choice,int y_choice,int x_put,int y_put)              //1p金
{
    int i, j, around[3] = {-1, 0, 1};
    int loop1,loop2,number;

    if(board[x_put][y_put] >= 1 && board[x_put][y_put] <= 14)                            //入力した場所に自分の駒があるとき
    {
        printf("味方のコマが置いてあります.\n指し直してください.");
        return 1;
    }
    else if(x_put == 0 || x_put == 10 || y_put == 0 || y_put == 10)                      //盤面外に指した場合
    {
        printf("盤面外です.\n指し直してください.");
        return 1;
    }
    else if(x_choice == x_put && y_choice == y_put)                                      //駒が動かない入力をしたとき
    {
        printf("動いてません.\n指し直してください.");
        return 1;
    }
    else if((x_put == x_choice -1 || x_put == x_choice + 1) && (y_put == y_choice - 1))  //動けない位置に指した場合
    {
        printf("不正な入力です.\n指し直してください.");
        return 1;
    }
    else
    {
        for(i = 0;i < 3;i++)
        {
            for(j = 0;j < 3;j++)
            {
                if(x_put == x_choice + around[i] && y_put == y_choice + around[j])
                {
                    if(board[x_choice][y_choice] == 6)           //金
                    {
                        board[x_put][y_put] = 6;
                    }
                    else if(board[x_choice][y_choice] == 8)      //裏銀
                    {
                        board[x_put][y_put] = 8;
                    }
                    else if(board[x_choice][y_choice] == 10)     //裏桂馬
                    {
                        board[x_put][y_put] = 10;
                    }
                    else if(board[x_choice][y_choice] == 12)     //裏香車
                    {
                        board[x_put][y_put] = 12;
                    }
                    else if(board[x_choice][y_choice] == 14)     //裏歩
                    {
                        board[x_put][y_put] = 14;
                    }
                    board[x_choice][y_choice] = 0;
                    return 2;
                }
            }
        }
    }
    /*以下の処理をするときは動けることが確定している、ここでコマの成りを判定する。*/
	/*相手のコマを自分のコマの番号に直し保存する処理*/
	if(board[x_put][y_put] >= 15)
	{
		for (loop2 = 0; loop2 <= 39; loop2++)
		{
			if (have[loop2] == 0)
			{
				number = loop2;
				have[loop2] = board[x_put][y_put] - 14;	/*自分の対応する番号に修正し保存*/
				loop2 = 40;	/*ループから出るために代入*/
			}
		}

		/*成りコマは元のコマに直して保存する*/
		for (loop1 = 17;loop1 <= 19; loop1 = loop1 + 2)
		{
			if(board[x_put][y_put] == loop1)
			{
				have[number]--;
			}
		}
		for (loop1 = 22; loop1 <= 28; loop1 = loop1 + 2)
		{
			if(board[x_put][y_put] == loop1)
			{
				have[number]--;
			}
		}
	}
}
//------------------------------------------------------------------------------------------------------------------------------------------------
int kin_2(int board[11][11],int have[],int x_choice,int y_choice,int x_put,int y_put)        //2p金
{
    int i, j, around[3] = {-1, 0, 1};
    int loop1,loop2,number;

    if(board[x_put][y_put] >= 15 && board[x_put][y_put] <= 28)                            //入力した場所に自分の駒があるとき
    {
        printf("味方のコマが置いてあります.\n指し直してください.");
        return 1;
    }
    else if(x_put == 0 || x_put == 10 || y_put == 0 || y_put == 10)                      //盤面外に指した場合
    {
        printf("盤面外です.\n指し直してください.");
        return 1;
    }
    else if(x_choice == x_put && y_choice == y_put)                                      //駒が動かない入力をしたとき
    {
        printf("動いてません.\n指し直してください.");
        return 1;
    }
    else if((x_put == x_choice -1 || x_put == x_choice + 1) && (y_put == y_choice + 1))  //動けない位置に指した場合
    {
        printf("不正な入力です.\n指し直してください.");
        return 1;
    }
    else
    {
        for(i = 0;i < 3;i++)
        {
            for(j = 0;j < 3;j++)
            {
                if(x_put == x_choice + around[i] && y_put == y_choice + around[j])
                {
                    if(board[x_choice][y_choice] == 20)           //金
                    {
                        board[x_put][y_put] = 20;
                    }
                    else if(board[x_choice][y_choice] == 22)      //裏銀
                    {
                        board[x_put][y_put] = 22;
                    }
                    else if(board[x_choice][y_choice] == 24)      //裏桂馬
                    {
                        board[x_put][y_put] = 24;
                    }
                    else if(board[x_choice][y_choice] == 26)      //裏香車
                    {
                        board[x_put][y_put] = 26;
                    }
                    else if(board[x_choice][y_choice] == 28)      //裏歩
                    {
                        board[x_put][y_put] = 28;
                    }
                    board[x_choice][y_choice] = 0;
                    return 2;
                }
            }
        }
    }
        /*以下の処理をするときは動けることが確定している、ここでコマの成りを判定する。*/
	/*相手のコマを自分のコマの番号に直し保存する処理*/
	if(board[x_put][y_put] >= 15)
	{
		for (loop2 = 0; loop2 <= 39; loop2++)
		{
			if (have[loop2] == 0)
			{
				number = loop2;
				have[loop2] = board[x_put][y_put] - 14;	/*自分の対応する番号に修正し保存*/
				loop2 = 40;	/*ループから出るために代入*/
			}
		}

		/*成りコマは元のコマに直して保存する*/
		for (loop1 = 17;loop1 <= 19; loop1 = loop1 + 2)
		{
			if(board[x_put][y_put] == loop1)
			{
				have[number]--;
			}
		}
		for (loop1 = 22; loop1 <= 28; loop1 = loop1 + 2)
		{
			if(board[x_put][y_put] == loop1)
			{
				have[number]--;
			}
		}
	}
}
//------------------------------------------------------------------------------------------------------------------------------------------------
int kyousya_1(int board[11][11],int have[],int x_choice,int y_choice,int x_put,int y_put)      //1p香車
{
    int i,j,loop1,loop2,number;

    if(board[x_put][y_put] >= 1 && board[x_put][y_put] <= 14)                            //入力した場所に自分の駒があるとき
    {
        printf("味方のコマが置いてあります.\n指し直してください.");
        return 1;
    }
    else if(x_put == 0 || x_put == 10 || y_put == 0 || y_put == 10)                      //盤面外に指した場合
    {
        printf("盤面外です.\n指し直してください.");
        return 1;
    }
    else if(x_choice == x_put && y_choice == y_put)                                      //駒が動かない入力をしたとき
    {
        printf("動いてません.\n指し直してください.");
        return 1;
    }
    else if(x_put != x_choice)                               //動けない位置に指した場合1
    {
        printf("不正な入力です.\n指し直してください.");
        return 1;
    }
    else if(y_put <= y_choice)                               //動けない位置に指した場合2
    {
        printf("不正な入力です.\n指し直してください.");
        return 1;
    }
    else                                                     //動けない位置に指した場合3
    {
        for(i = 1;i < 9;i++)
        {
            if(board[x_choice][y_choice + i] > 0)
            {
                if(y_put < y_choice + i)
                {
                    printf("不正な入力です.\n指し直してください.");
                    return 1;
                }
            }
        }    
    }
    if(x_put == 1)                                           //強制成り
    {
        board[x_put][y_put] = 12;
        board[x_choice][y_choice] = 0;
        return 2;
    }
    else if(x_put == 2 || x_put == 3)                        //選択成り
    {
        printf("1:成る\n2:成らない");
        scanf("%d",&j);
        while(j != 1 || j != 2)
        {
            if(j == 1)
            {
                 board[x_put][y_put] = 12;
                 board[x_choice][y_choice] = 0;
                 return 2;
            }
             else if(j == 2)
            {
                 board[x_put][y_put] = 11;
                 board[x_choice][y_choice] = 0;
                 return 2;
            }
            printf("1:成る\n2:成らない");
            scanf("%d",&j);
        }
    }
    else if(4 <= x_put && x_put <= 8)                         //成れない位置に置いたとき
    {
        board[x_put][y_put] = 11;
        board[x_choice][y_choice] = 0;
        return 2;
    }
        /*以下の処理をするときは動けることが確定している、ここでコマの成りを判定する。*/
	/*相手のコマを自分のコマの番号に直し保存する処理*/
	if(board[x_put][y_put] >= 15)
	{
		for (loop2 = 0; loop2 <= 39; loop2++)
		{
			if (have[loop2] == 0)
			{
				number = loop2;
				have[loop2] = board[x_put][y_put] - 14;	/*自分の対応する番号に修正し保存*/
				loop2 = 40;	/*ループから出るために代入*/
			}
		}

		/*成りコマは元のコマに直して保存する*/
		for (loop1 = 17;loop1 <= 19; loop1 = loop1 + 2)
		{
			if(board[x_put][y_put] == loop1)
			{
				have[number]--;
			}
		}
		for (loop1 = 22; loop1 <= 28; loop1 = loop1 + 2)
		{
			if(board[x_put][y_put] == loop1)
			{
				have[number]--;
			}
		}
	}
}
//------------------------------------------------------------------------------------------------------------------------------------------------
int kyousya_2(int board[11][11],int have[],int x_choice,int y_choice,int x_put,int y_put)    //2p香車
{
    int i,j,loop1,loop2,number;

    if(board[x_put][y_put] >= 15 && board[x_put][y_put] <= 28)                            //入力した場所に自分の駒があるとき
    {
        printf("味方のコマが置いてあります.\n指し直してください.");
        return 1;
    }
    else if(x_put == 0 || x_put == 10 || y_put == 0 || y_put == 10)                      //盤面外に指した場合
    {
        printf("盤面外です.\n指し直してください.");
        return 1;
    }
    else if(x_choice == x_put && y_choice == y_put)                                      //駒が動かない入力をしたとき
    {
        printf("動いてません.\n指し直してください.");
        return 1;
    }
    else if(x_put != x_choice)                               //動けない位置に指した場合1
    {
        printf("不正な入力です.\n指しなしてください.");
        return 1;
    }
    else if(y_put >= y_choice)                               //動けない位置に指した場合2
    {
        printf("不正な入力です.\n指し直してください.");
        return 1;
    }
    else                                                     //動けない位置に指した場合3
    {
        for(i = 1;i < 9;i++)
        {
            if(board[x_choice][y_choice - i] > 0)
            {
                if(y_put > y_choice - i)
                {
                    printf("不正な入力です.\n指し直してください.");
                    return 1;
                }
            }
        }    
    }
    if(x_put == 9)                                            //強制成り
    {
        board[x_put][y_put] == 26;
        board[x_choice][y_choice] = 0;
        return 2;
    }
    else if(x_put == 8 || x_put == 7)                         //選択成り
    {
        printf("1:成る\n2:成らない");
        scanf("%d",&j);
        while(j != 1 || j != 2)
        {
            if(j == 1)
            {
                 board[x_put][y_put] = 26;
                 board[x_choice][y_choice] = 0;
                 return 2;
            }
             else if(j == 2)
            {
                 board[x_put][y_put] = 25;
                 board[x_choice][y_choice] = 0;
                 return 2;
            }
            printf("1:成る\n2:成らない");
            scanf("%d",&j);
        }
    }
    else if(2 <= x_put && x_put <= 6)                         //成れない位置に置いたとき
    {
        board[x_put][y_put] = 25;
        board[x_choice][y_choice] = 0;
        return 2;
    }
        /*以下の処理をするときは動けることが確定している、ここでコマの成りを判定する。*/
	/*相手のコマを自分のコマの番号に直し保存する処理*/
	if(board[x_put][y_put] >= 15)
	{
		for (loop2 = 0; loop2 <= 39; loop2++)
		{
			if (have[loop2] == 0)
			{
				number = loop2;
				have[loop2] = board[x_put][y_put] - 14;	/*自分の対応する番号に修正し保存*/
				loop2 = 40;	/*ループから出るために代入*/
			}
		}

		/*成りコマは元のコマに直して保存する*/
		for (loop1 = 17;loop1 <= 19; loop1 = loop1 + 2)
		{
			if(board[x_put][y_put] == loop1)
			{
				have[number]--;
			}
		}
		for (loop1 = 22; loop1 <= 28; loop1 = loop1 + 2)
		{
			if(board[x_put][y_put] == loop1)
			{
				have[number]--;
			}
		}
	}
}
//------------------------------------------------------------------------------------------------------------------------------------------------
/*飛車の動き*/
int hisha_1(int board[11][11],int have[], int x_choice, int y_choice, int x_put, int y_put)
{
	int loop1;
	int loop2;
	int number;
	int option_nari;

	/*動けないマスが選択されたときは動かない*/
	if (((x_choice != x_put) && (y_choice != y_put)) || ((x_choice == x_put) && (y_choice == y_put)) || (board[x_choice][y_choice] == 0) || (board[x_put][y_put] == -1))
	{
		printf("そこには動けません。\n指し直してください。\n");
		return 1;
	}

	/*動くマスに味方のコマがあったら動かない*/
	if (((board[x_choice][y_choice] <= 14) && (board[x_put][y_put] <= 14)))
	{
		printf("味方のコマが置いてあります。\n差し直してください。");
		return 1;
	}
	
	/*縦に動く場合*/
	if (x_choice == x_put)
	{
		if (y_choice > y_put)
		{
			/*動くマスと今いるマスの間に何もないかの確認の処理*/
			for (loop1 = y_put + 1;loop1 < y_choice;loop1++)
			{
				if (board[x_choice][loop1] > 0)
				{
					printf("通り道にコマがあるため動けません。\n差し直してください。\n");
					return 1;		/*何かあったら動けないので1を返す*/
				}
			}
		}
		else
		{
			/*動くマスと今いるマスの間に何もないかの確認の処理*/
			for (loop1 = y_choice + 1; loop1 < y_put; loop1++)
			{
				if (board[x_choice][loop1] > 0)
				{
					printf("通り道にコマがあるため動けません。\n差し直してください。\n");
					return 1;		/*何かあったら動けないので1を返す*/
				}
			}
		}
	}

	/*横の動くとき*/
	if (y_choice == y_put)
	{
		if (x_choice > x_put)
		{
			/*動くマスと今いるマスの間に何もないかの確認の処理*/
			for (loop1 = x_put + 1; loop1 < x_choice; loop1++)
			{
				if (board[loop1][y_choice] > 0)
				{
					printf("通り道にコマがあるため動けません。\n差し直してください。\n");
					return 1;		/*何かあったら動けないので1を返す*/
				}
			}
		}
		else
		{
			/*動くマスと今いるマスの間に何もないかの確認の処理*/
			for (loop1 = x_choice + 1; loop1 < x_put; loop1++)
			{
				if (board[loop1][y_choice] > 0)
				{
					printf("通り道にコマがあるため動けません。\n差し直してください。\n");
					return 1;		/*何かあったら動けないので1を返す*/
				}
			}
		}
	}

	/*以下の処理をするときは動けることが確定している、ここでコマの成りを判定する。*/
	/*相手のコマを自分のコマの番号に直し保存する処理*/
	if(board[x_put][y_put] >= 15)
	{
		for (loop2 = 0; loop2 <= 39; loop2++)
		{
			if (have[loop2] == 0)
			{
				number = loop2;
				have[loop2] = board[x_put][y_put] -14;	/*自分の対応する番号に修正し保存*/
				loop2 = 40;	/*ループから出るために代入*/
			}
		}

		/*成りコマは元のコマに直して保存する*/
		for (loop1 = 17;loop1 <= 19; loop1 = loop1 + 2)
		{
			if(board[x_put][y_put] == loop1)
			{
				have[number]--;
			}
		}
		for (loop1 = 22; loop1 <= 28; loop1 = loop1 + 2)
		{
			if(board[x_put][y_put] == loop1)
			{
				have[number]--;
			}
		}
	}

	/*成りの判定、及び動く処理*/
	if ((board[x_put][y_put] <= 3) || (board[x_choice][y_choice] <= 3))
	{
		while (1)
		{
			printf("1:成る\n2:成らない\n");
			scanf("%d", &option_nari);
			
			if (option_nari == 1)
			{
		
				board[x_put][y_put] = 3;
				board[x_choice][y_choice] = 0;
				return 2;
			}
			if (option_nari == 2)
			{
				board[x_put][y_put] = board[x_choice][y_choice];
				board[x_choice][y_choice] = 0;
				return 2;
			}
		}
	}
	else
	{
		board[x_put][y_put] = board[x_choice][y_choice];
		board[x_choice][y_choice] = 0;
		return 2;
	}
}
//------------------------------------------------------------------------------------------------------------------------------------------------
int hisha_2(int board[11][11],int have[], int x_choice, int y_choice, int x_put, int y_put)
{
	int loop1;
	int loop2;
	int number;
	int option_nari;

	/*動けないマスが選択されたときは動かない*/
	if (((x_choice != x_put) && (y_choice != y_put)) || ((x_choice == x_put) && (y_choice == y_put)) || (board[x_choice][y_choice] == 0) || (board[x_put][y_put] == -1))
	{
		printf("そこには動けません。\n指し直してください。\n");
		return 1;
	}

	/*動くマスに味方のコマがあったら動かない*/
	if (((board[x_choice][y_choice] >= 15) && (board[x_put][y_put] >= 15)))
	{
		printf("味方のコマが置いてあります。\n差し直してください。");
		return 1;
	}
	
	/*縦に動く場合*/
	if (x_choice == x_put)
	{
		if (y_choice > y_put)
		{
			/*動くマスと今いるマスの間に何もないかの確認の処理*/
			for (loop1 = y_put + 1;loop1 < y_choice;loop1++)
			{
				if (board[x_choice][loop1] > 0)
				{
					printf("通り道にコマがあるため動けません。\n差し直してください。\n");
					return 1;		/*何かあったら動けないので1を返す*/
				}
			}
		}
		else
		{
			/*動くマスと今いるマスの間に何もないかの確認の処理*/
			for (loop1 = y_choice + 1; loop1 < y_put; loop1++)
			{
				if (board[x_choice][loop1] > 0)
				{
					printf("通り道にコマがあるため動けません。\n差し直してください。\n");
					return 1;		/*何かあったら動けないので1を返す*/
				}
			}
		}
	}

	/*横の動くとき*/
	if (y_choice == y_put)
	{
		if (x_choice > x_put)
		{
			/*動くマスと今いるマスの間に何もないかの確認の処理*/
			for (loop1 = x_put + 1; loop1 < x_choice; loop1++)
			{
				if (board[loop1][y_choice] > 0)
				{
					printf("通り道にコマがあるため動けません。\n差し直してください。\n");
					return 1;		/*何かあったら動けないので1を返す*/
				}
			}
		}
		else
		{
			/*動くマスと今いるマスの間に何もないかの確認の処理*/
			for (loop1 = x_choice + 1; loop1 < x_put; loop1++)
			{
				if (board[loop1][y_choice] > 0)
				{
					printf("通り道にコマがあるため動けません。\n差し直してください。\n");
					return 1;		/*何かあったら動けないので1を返す*/
				}
			}
		}
	}

	/*以下の処理をするときは動けることが確定している、ここでコマの成りを判定する。*/
	if(board[x_put][y_put] <= 14)
	{
		for (loop2 = 0; loop2 <= 39; loop2++)
		{
			if (have[loop2] == 0)
			{
				number = loop2;
				have[loop2] = board[x_put][y_put] +14;	/*自分の対応する番号に修正し保存*/
				loop2 = 40;	/*ループから出るために代入*/
			}
		}

		/*成りコマは元のコマに直して保存する*/
		for (loop1 = 3;loop1 <= 5; loop1 = loop1 + 2)
		{
			if(board[x_put][y_put] == loop1)
			{
				have[number]++;
			}
		}
		for (loop1 = 8; loop1 <= 14; loop1 = loop1 + 2)
		{
			if(board[x_put][y_put] == loop1)
			{
				have[number]++;
			}
		}
	}
	
	/*成りの判定、及び移動の処理*/
	if ((board[x_choice][y_choice] >= 8) || (board[x_put][y_put] >= 8))
	{
		/*成るかどうか決めるまでループ*/
		while (1)
		{
			printf("1:成る\n2:成らない\n");
			scanf("%d" ,&option_nari);
			
			if (option_nari == 1)
			{
				board[x_put][y_put] = 17;
				board[x_choice][y_choice] = 0;
				return 2;
			}
			
			if (option_nari == 2)
			{
				board[x_put][y_put] = board[x_choice][y_choice];
				board[x_choice][y_choice] = 0;
				return 2;
			}
		}
	}
	else		/*成れない場合移動の処理をする*/
	{
		board[x_put][y_put] = board[x_choice][y_choice];
		board[x_choice][y_choice] = 0;
		return 2;		
	}
}
//------------------------------------------------------------------------------------------------------------------------------------------------
int oushou_1(int board[11][11],int have[40],int x_choise,int y_choise,int x_put,int y_put,int king[2][2])
{
	int k=0;
    if(1 <= board[x_put][y_put] && board[x_put][y_put] <=14)
    {//味方コマが置いてあるとき
        printf("味方のコマが置いてあります.\n指し直してください.");
        return 1;
    }
    if(x_put == 0 || x_put == 10 || y_put == 0 || y_put == 10)
    {//盤面外の配置のとき
        printf("盤面外です.\n指し直してください.");
        return 1;
    }
    if(x_put == x_choise && y_put == y_choise)
    {//同じ位置のとき
        printf("動いてません.\n指し直してください.");
        return 1;
    }
	if(x_put-x_choise<2&&x_put-x_choise>-2&&y_put-y_choise<2&&y_put-y_choise>-2)
	{
		while(have[k] != 0)
		{//空欄まで進む
			k++;
		}
		have[k] = board[x_put][y_put]-14;
		board[x_put][y_put] = 1;
		king[0][0]=x_put;
		king[0][1]=y_put;
		return 2;
	}
    printf("そこには,動けません.\n指し直してください.");
    return 1;
}
//------------------------------------------------------------------------------------------------------------------------------------------------
int oushou_2(int board[11][11],int  have[40], int x_choise,int y_choise,int x_put,int y_put,int king[2][2])
{
	int k=0;
    if(15 <= board[x_put][y_put] && board[x_put][y_put] <= 28)
    {//味方コマが置いてあるとき
        printf("味方のコマが置いてあります.\n指し直してください.");
        return 1;
    }
    if(x_put == 0 || x_put == 10 || y_put == 0 || y_put == 10)
    {//盤面外の配置のとき
        printf("盤面外です.\n指し直してください.");
        return 1;
    }
    if(x_put == x_choise && y_put == y_choise)
    {//同じ位置のとき
        printf("動いてません.\n指し直してください.");
        return 1;
    }
    if(x_put-x_choise<2&&x_put-x_choise>-2&&y_put-y_choise<2&&y_put-y_choise>-2)
	{
		while(have[k] != 0)
		{//空欄まで進む
			k++;
		}
		have[k] = board[x_put][y_put]+14;
		board[x_put][y_put] = 15;
		king[1][0]=x_put;
		king[1][1]=y_put;
		return 2;
	}
    printf("そこには,動けません.\n指し直してください.");
    return 1;
}
//------------------------------------------------------------------------------------------------------------------------------------------------
int hu_1(int board[11][11],int have[40],int x_choice,int y_choice,int x_put,int y_put)
{
    int naru;
	int i=0;
    if(1 <= board[x_put][y_put] && board[x_put][y_put] <=14)
    {//味方コマが置いてあるとき
        printf("味方のコマが置いてあります.\n指し直してください.");
        return 1;
    }
    if(x_put == 0 || x_put == 10 || y_put == 0 || y_put == 10)
    {//盤面外の配置のとき
        printf("盤面外です.\n指し直してください.");
        return 1;
    }
    if(x_put == x_choice && y_put == y_choice)
    {//同じ位置のとき
        printf("動いてません.\n指し直してください.");
        return 1;
    }
    if(y_choice - 1 == y_put)
    {//置ける位置のとき
        if(y_put==1)
		{//最奥のとき
			while(have[i] != 0)
			{//空欄まで進む
				i++;
			}
			have[i] = board[x_put][y_put]+14;
			board[x_put][y_put]=14;
			return 2;
		}
		if(y_put<=3)
        {//裏になれるとき
            while(naru!=1&&naru!=2)
            {
                printf("1:成る\n2:成らない");
                scanf("%c",&naru);
            }
            if(naru==1)
            {
                while(have[i]!=0)
				{//空欄まで進む
					i++;
				}
				have[i] = board[x_put][y_put]+14;
				board[x_put][y_put] = 14;
                return 2;
            }
            else
            {
                while(have[i]!=0)
				{//空欄まで進む
					i++;
				}
				have[i] = board[x_put][y_put]+14;
				board[x_put][y_put] = 13;
                return 2;
            }
        }
    }
    printf("そこには,動けません.\n指し直してください.");
    return 1;
}
//------------------------------------------------------------------------------------------------------------------------------------------------
int hu_2(int board[11][11],int have[40],int x_choice,int y_choice,int x_put,int y_put)
{
    int naru;
	int i=0;
    if(15 <= board[x_put][y_put] && board[x_put][y_put] <=28)
    {//味方コマが置いてあるとき
        printf("味方のコマが置いてあります.\n指し直してください.");
        return 1;
    }
    if(x_put == 0 || x_put == 10 || y_put == 0 || y_put == 10)
    {//盤面外の配置のとき
        printf("盤面外です.\n指し直してください.");
        return 1;
    }
    if(x_put == x_choice && y_put == y_choice)
    {//同じ位置のとき
        printf("動いてません.\n指し直してください.");
        return 1;
    }
    if(y_choice + 1 == y_put)
    {//置ける位置のとき
        if(y_put==9)
		{//最奥のとき
			while(have[i] != 0)
			{//空欄まで進む
				i++;
			}
			have[i] = board[x_put][y_put]-14;
			board[x_put][y_put]=28;
			return 2;
		}
		if(y_put>=7)
        {//裏になるとき
          while(naru!=1&&naru!=2)
            {
                printf("1:成る\n2:成らない");
                scanf("%c",&naru);
            }
            if(naru==1)
            {
                while(have[i]!=0)
				{//空欄まで進む
					i++;
				}
				have[i] = board[x_put][y_put]-14;
				board[x_put][y_put] = 28;
                return 2;
            }
            else
            {
                while(have[i]!=0)
				{//空欄まで進む
					i++;
				}
				have[i] = board[x_put][y_put]-14;
				board[x_put][y_put] = 27;
                return 2;
            }
        }  
    }
    printf("そこには,動けません.\n指し直してください.");
    return 1;
}
//------------------------------------------------------------------------------------------------------------------------------------------------
int keima_1(int board[][], int have[], int x_choice, int y_choice, int x_put, int y_put)
{
	int i = 0;
	char num = '0';

	if ((1 <= board[x_put][y_put]) && (board[x_put][y_put] <= 14))
	{//味方の駒がある
		printf("味方の駒が置いてあります.\n指し直してください.\n");
		return 1;
	}
	if ((x_put <= 0) || (x_put >= 10) || (y_put <= 0) || (y_put >= 10))
	{//盤面外
		printf("盤面外です.\n指し直してください.\n");
		return 1;
	}
	if ((x_put == x_choice) && (y_put == y_choice))
	{//動いていない
		printf("動いていません.\n指し直してください.\n");
		return 1;
	}
	if ((x_choice - 2 == x_put) && ((y_choice - 1 == y_put)||(y_choice + 1 == y_put))
	{//動いた
		if ((15 <= board[x_put][y_put]) && (board[x_put][y_put] <= 28))
		{//相手の駒がある
			i=board[x_put][y_put]-14;
			if((i==3)||(i==5)||(i==8)||(i==10)||(i==12)||(i==14))
			{
				i=i-3;
			}
			else
			{
				i=i-2;
			}
			have[i]++;
		}
		if (x_put <= 3)
		{//裏になりうる
			if (x_put == 3)
			{
				while (num != '1' && num != '2')
				{
					printf("成る＝1,成らない＝2\n");
					scanf("%c", &num);
					if (num == '1')
					{//裏になる
						board[x_put][y_put] = 10;
						return 2;
					}
					if(num=='2')
					{//裏にならない
						board[x_put][y_put] = 9;
						return 2;
					}
				}
			}
			if (x_put == 1)
			{//最奥までいったら裏になる
				board[x_put][y_put] = 10;
				return 2;
			}
		}
		else
		{//裏になれない
			board[x_put][y_put] = 9;
			return 2;
		}
	}
	printf("そこには動けません.\n指し直してください.\n");
	return 1;
}
//------------------------------------------------------------------------------------------------------------------------------------------------
int keima_2(int board[][], int have[], int x_choice, int y_choice, int x_put, int y_put)
{
	int i = 0;
	char num = '0';

	if ((15 <= board[x_put][y_put]) && (board[x_put][y_put] <= 28))
	{
		printf("味方の駒が置いてあります.\n指し直してください.\n");
		return 1;
	}
	if ((x_put <= 0) || (x_put >= 10) || (y_put <= 0) || (y_put >= 10))
	{
		printf("盤面外です.\n指し直してください.\n");
		return 1;
	}
	if ((x_put == x_choice) && (y_put == y_choice))
	{
		printf("動いていません.\n指し直してください.\n");
		return 1;
	}
	if ((x_choice + 2 == x_put) && (y_choice + 1 == y_put))
	{
		if (x_put >= 7)
		{
			if (x_put == 7)
			{
				while (num != '1' && num != '2')
				{
					printf("成る＝1,成らない＝2\n");
					scanf("%c", &num);
					if (num == '1')
					{
						board[x_put][y_put] = 24;
						return 2;
					}
				}
			}
			if (x_put == 9)
			{
				board[x_put][y_put] = 24;
				return 2;
			}
		}
		else
		{
			board[x_put][y_put] = 23;
			return 2;
		}
		if ((1 <= board[x_put][y_put]) && (board[x_put][y_put] <= 14))
		{
			while (have[i] != 0)
			{
				i++;
			}
			have[i] = board[x_put][y_put] + 14;
		}
	}
	printf("そこには動けません.\n指し直してください.\n");
	return 1;
}
//------------------------------------------------------------------------------------------------------------------------------------------------
int silver_1(int board[][], int have[], int x_choice, int y_choice, int x_put, int y_put)
{
	int i, j, k = 0, front[3] = { -1, 0, 1 };
	char num = '0';

	if ((1 <= board[x_put][y_put]) && (board[x_put][y_put] <= 14))
	{
		printf("味方の駒が置いてあります.\n指し直してください.\n");
		return 1;
	}
	if ((x_put <= 0) || (x_put >= 10) || (y_put <= 0) || (y_put >= 10))
	{
		printf("盤面外です.\n指し直してください.\n");
		return 1;
	}
	if ((x_put == x_choice) && (y_put == y_choice))
	{
		printf("動いていません.\n指し直してください.\n");
		return 1;
	}
	for (i = 0; i < 3; i++)
	{
		if ((x_choice - 1 == x_put) && (y_choice + front[i] == y_put))
		{
			if (x_put <= 3)
			{
				while (num != '1' && num != '2')
				{
					printf("成る＝1,成らない＝2\n");
					scanf("%c", &num);
					if (num == '1')
					{
						board[x_put][y_put] = 8;
						return 2;
					}
				}
			}
			else
			{
				board[x_put][y_put] = 7;
				return 2;
			}
			if ((15 <= board[x_put][y_put]) && (board[x_put][y_put] <= 28))
			{
				while (have[k] != 0)
				{
					k++;
				}
				have[k] = board[x_put][y_put] + 14;
			}
		}
	}
	for (j = 0; j < 2; j++)
	{
		if ((x_choice + 1 == x_put) && (y_choice + front[j] == y_put))
		{
			if (x_put <= 3)
			{
				while (num != '1' && num != '2')
				{
					printf("成る＝1,成らない＝2\n");
					scanf("%c", &num);
					if (num == '1')
					{
						board[x_put][y_put] = 8;
						return 2;
					}
				}
			}
			else
			{
				board[x_put][y_put] = 7;
				return 2;
			}
			if ((15 <= board[x_put][y_put]) && (board[x_put][y_put] <= 28))
			{
				while (have[k] != 0)
				{
					k++;
				}
				have[k] = board[x_put][y_put] + 14;
			}
		}
	}
	if (x_choice == 3 && x_put == 4)
	{
		while (num != '1' && num != '2')
		{
			printf("成る＝1,成らない＝2\n");
			scanf("%c", &num);
			if (num == '1')
			{
				board[x_put][y_put] = 8;
				return 2;
			}
		}
		if ((15 <= board[x_put][y_put]) && (board[x_put][y_put] <= 28))
		{
			while (have[k] != 0)
			{
				k++;
			}
			have[k] = board[x_put][y_put] + 14;
		}
	}
	printf("そこには動けません.\n指し直してください.\n");
	return 1;
}
//------------------------------------------------------------------------------------------------------------------------------------------------
int silver_2(int board[][], int have[], int x_choice, int y_choice, int x_put, int y_put)
{
	int i, j, k = 0, front[3] = { -1, 0, 1 };
	char num = '0';

	if ((15 <= board[x_put][y_put]) && (board[x_put][y_put] <= 28))
	{
		printf("味方の駒が置いてあります.\n指し直してください.\n");
		return 1;
	}
	if ((x_put <= 0) || (x_put >= 10) || (y_put <= 0) || (y_put >= 10))
	{
		printf("盤面外です.\n指し直してください.\n");
		return 1;
	}
	if ((x_put == x_choice) && (y_put == y_choice))
	{
		printf("動いていません.\n指し直してください.\n");
		return 1;
	}
	for (i = 0; i < 3; i++)
	{
		if ((x_choice - 1 == x_put) && (y_choice + front[i] == y_put))
		{
			if (x_put >= 7)
			{
				while (num != '1' && num != '2')
				{
					printf("成る＝1,成らない＝2\n");
					scanf("%c", &num);
					if (num == '1')
					{
						board[x_put][y_put] = 22;
						return 2;
					}
				}
			}
			else
			{
				board[x_put][y_put] = 21;
				return 2;
			}
			if ((1 <= board[x_put][y_put]) && (board[x_put][y_put] <= 14))
			{
				while (have[k] != 0)
				{
					k++;
				}
				have[k] = board[x_put][y_put] + 14;
			}
		}
	}
	for (j = 0; j < 2; j++)
	{
		if ((x_choice + 1 == x_put) && (y_choice + front[j] == y_put))
		{
			if (x_put >= 7)
			{
				while (num != '1' && num != '2')
				{
					printf("成る＝1,成らない＝2\n");
					scanf("%c", &num);
					if (num == '1')
					{
						board[x_put][y_put] = 22;
						return 2;
					}
				}
			}
			else
			{
				board[x_put][y_put] = 21;
				return 2;
			}
			if ((1 <= board[x_put][y_put]) && (board[x_put][y_put] <= 14))
			{
				while (have[k] != 0)
				{
					k++;
				}
				have[k] = board[x_put][y_put] + 14;
			}
		}
	}
	if (x_choice == 7 && x_put == 6)
	{
		while (num != '1' && num != '2')
		{
			printf("成る＝1,成らない＝2\n");
			scanf("%c", &num);
			if (num == '1')
			{
				board[x_put][y_put] = 8;
				return 2;
			}
		}
		if ((1 <= board[x_put][y_put]) && (board[x_put][y_put] <= 14))
		{
			while (have[k] != 0)
			{
				k++;
			}
			have[k] = board[x_put][y_put] + 14;
		}
	}
	printf("そこには動けません.\n指し直してください.\n");
	return 1;
}
//------------------------------------------------------------------------------------------------------------------------------------------------
/*角の動き*/
int kaku_1(int board[11][11],int have[], int x_choice, int y_choice, int x_put, int y_put)
{
	int xloop;
	int yloop;
	int loop1;
	int number;
	int option_nari;

	if ((x_choice == x_put) || (y_put == y_choice))
	{
		printf("そこには,動けません.\n指し直してください.\n");
		return 1;
	}

	/*上方向に動くとき*/
	if (y_put <= y_choice)
	{
		/*左上方向に動く時の動けるかどうかの確認*/
		if (x_put <= x_choice)
		{
			for (xloop = x_put + 1; xloop < x_choice; xloop++)
			{
				for (yloop = y_put + 1; yloop < y_put;yloop++ )
				{
					if (board[xloop][yloop] > 0)
					{
						printf("通り道にコマがあるため動けません。\n差し直してください。\n");
						return 1;
					}
				}
			}
		}
		/*右上方向に動く時の動けるかどうかの確認*/
		if (x_put >= x_choice)
		{
			for (xloop = x_put -1; x_choice < xloop; xloop--)
			{
				for (yloop = yloop + 1; yloop > y_choice;yloop--)
				{
					if(board[xloop][yloop] > 0)
					{
						printf("通り道にコマがあるため動けません。\n差し直してください。\n");
						return 1;
					}
				}
			}
		}
	}
	/*下方向に動くとき*/
	if(y_put > y_choice)
	{
		/*左下方向に動くとき*/
		if(x_put < x_choice)
		{
			for (xloop = x_put + 1; xloop < x_choice ; xloop++)
			{
				for (yloop = y_put - 1; yloop < y_choice; yloop--)
				{
					if (board[xloop][yloop] > 0)
					{
						printf("通り道にコマがあるため動けません。\n差し直してください。\n");
						return 1;
					}
				}
			}
		}
		/*右下に動くときの確認*/
		if (x_put > x_choice)
		{
			for (xloop = x_put - 1; xloop > x_choice ; xloop--)
			{
				for (yloop = y_put - 1; yloop > y_choice; yloop--)
				{
					if (board[xloop][yloop])
					{
						printf("通り道にコマがあるため動けません。\n差し直してください。\n");
						return 1;
					}
				}
			}
		}
	}

	/*移動した先に味方のコマがないかの確認*/
	if (board[x_put][y_put] <= 14)
	{
		printf("味方のコマが置いてあります.\n指し直してください.");
		return 1;
	}

	/*以下コマの移動、コマを取る処理*/
	/*相手のコマを取る処理*/
	if (board[x_put][y_put] >= 15)
	{
		for (loop1 = 0; loop1 < 39; loop1++)
		{
			if (have[loop1] == 0)
			{
				number = loop1;		/*コマを入れた配列を記録しておく*/
				have[loop1] = board[x_put][y_put] - 14;
				loop1 = 40;
			}
		}
		/*成りコマを取った場合元のコマに戻し手持ちに入れる*/
		for (loop1 = 17;loop1 <= 19; loop1 = loop1 + 2)
		{
			if(board[x_put][y_put] == loop1)
			{
				have[number]--;
			}
		}
		for (loop1 = 22; loop1 <= 28; loop1 = loop1 + 2)
		{
			if(board[x_put][y_put] == loop1)
			{
				have[number]--;
			}
		}
	}
	/*成り及び移動する処理*/
	if ((board[x_put][y_put] <= 3) || (board[x_choice][y_choice] <= 3))
	{
		while (1)
		{
			printf("1:成る\n2:成らない\n");
			scanf("%d", &option_nari);
			
			if (option_nari == 1)
			{
		
				board[x_put][y_put] = 5;
				board[x_choice][y_choice] = 0;
				return 2;
			}
			if (option_nari == 2)
			{
				board[x_put][y_put] = board[x_choice][y_choice];
				board[x_choice][y_choice] = 0;
				return 2;
			}
		}
	}
	else
	{
		board[x_put][y_put] = board[x_choice][y_choice];
		board[x_choice][y_choice] = 0;
		return 2;
	}
}
//------------------------------------------------------------------------------------------------------------------------------------------------
/*角の動き,preyer2*/
int kaku_2(int board[11][11],int have[], int x_choice, int y_choice, int x_put, int y_put)
{
	int xloop;
	int yloop;
	int loop1;
	int number;
	int option_nari;

	if ((x_choice == x_put) || (y_put == y_choice))
	{
		printf("そこには,動けません.\n指し直してください.\n");
		return 1;
	}

	/*上方向に動くとき*/
	if (y_put <= y_choice)
	{
		/*左上方向に動く時の動けるかどうかの確認*/
		if (x_put <= x_choice)
		{
			for (xloop = x_put + 1; xloop < x_choice; xloop++)
			{
				for (yloop = y_put + 1; yloop < y_choice;yloop++ )
				{
					if (board[xloop][yloop] > 0)
					{
						printf("通り道にコマがあるため動けません。\n差し直してください。\n");
						return 1;
					}
				}
			}
		}
		/*右上方向に動く時の動けるかどうかの確認*/
		if (x_put >= x_choice)
		{
			for (xloop = x_put -1; x_choice < xloop; xloop--)
			{
				for (yloop = yloop + 1; yloop > y_choice;yloop--)
				{
					if(board[xloop][yloop] > 0)
					{
						printf("通り道にコマがあるため動けません。\n差し直してください。\n");
						return 1;
					}
				}
			}
		}
	}
	/*下方向に動くとき*/
	if(y_put > y_choice)
	{
		/*左下方向に動くとき*/
		if(x_put < x_choice)
		{
			for (xloop = x_put + 1; xloop < x_choice ; xloop++)
			{
				for (yloop = y_put - 1; yloop < y_choice; yloop--)
				{
					if (board[xloop][yloop] > 0)
					{
						printf("通り道にコマがあるため動けません。\n差し直してください。\n");
						return 1;
					}
				}
			}
		}
		/*右下に動くときの確認*/
		if (x_put > x_choice)
		{
			for (xloop = x_put - 1; xloop > x_choice ; xloop--)
			{
				for (yloop = y_put - 1; yloop > y_choice; yloop--)
				{
					if (board[xloop][yloop])
					{
						printf("通り道にコマがあるため動けません。\n差し直してください。\n");
						return 1;
					}
				}
			}
		}
	}

	/*移動した先に味方のコマがないかの確認*/
	if (board[x_put][y_put] >= 15)
	{
		printf("味方のコマが置いてあります.\n指し直してください.");
		return 1;
	}

	/*以下コマの移動、コマを取る処理*/
	/*相手のコマを取る処理*/
	if (board[x_put][y_put] <= 14)
	{
		for (loop1 = 0; loop1 < 39; loop1++)
		{
			if (have[loop1] == 0)
			{
				number = loop1;		/*コマを入れた配列を記録しておく*/
				have[loop1] = board[x_put][y_put] + 14;
				loop1 = 40;
			}
		}
		/*成りコマを取った場合元のコマに戻し手持ちに入れる*/
		for (loop1 = 3;loop1 <= 5; loop1 = loop1 + 2)
		{
			if(board[x_put][y_put] == loop1)
			{
				have[number]++;
			}
		}
		for (loop1 = 8; loop1 <= 14; loop1 = loop1 + 2)
		{
			if(board[x_put][y_put] == loop1)
			{
				have[number]++;
			}
		}
	}
	/*成り及び移動する処理*/
	if ((board[x_put][y_put] <= 3) || (board[x_choice][y_choice] <= 3))
	{
		while (1)
		{
			printf("1:成る\n2:成らない\n");
			scanf("%d", &option_nari);
			
			if (option_nari == 1)
			{
		
				board[x_put][y_put] = 19;
				board[x_choice][y_choice] = 0;
				return 2;
			}
			if (option_nari == 2)
			{
				board[x_put][y_put] = board[x_choice][y_choice];
				board[x_choice][y_choice] = 0;
				return 2;
			}
		}
	}
	else
	{
		board[x_put][y_put] = board[x_choice][y_choice];
		board[x_choice][y_choice] = 0;
		return 2;
	}
}
//------------------------------------------------------------------------------------------------------------------------------------------------
/*裏角の動き 1*/
int urakaku_1(int board[11][11],int have[], int x_choice, int y_choice, int x_put, int y_put)
{
	int xloop;
	int yloop;
	int loop1;
	int number;

	if ((x_choice == x_put) || (y_put == y_choice) || ((x_put != x_choice - 1) || (x_put != x_choice) || (x_put != x_choice + 1)) && ((y_put != y_choice) || (y_put != y_choice + 1) || (y_put != y_choice - 1)))
	{
		printf("そこには,動けません.\n指し直してください.\n");
		return 1;
	}

	/*上方向に動くとき*/
	if (y_put <= y_choice)
	{
		/*左上方向に動く時の動けるかどうかの確認*/
		if (x_put <= x_choice)
		{
			for (xloop = x_put + 1; xloop < x_choice; xloop++)
			{
				for (yloop = y_put + 1; yloop < y_choice;yloop++ )
				{
					if (board[xloop][yloop] > 0)
					{
						printf("通り道にコマがあるため動けません。\n差し直してください。\n");
						return 1;
					}
				}
			}
		}
		/*右上方向に動く時の動けるかどうかの確認*/
		if (x_put >= x_choice)
		{
			for (xloop = x_put -1; x_choice < xloop; xloop--)
			{
				for (yloop = yloop + 1; yloop > y_choice; yloop--)
				{
					if(board[xloop][yloop] > 0)
					{
						printf("通り道にコマがあるため動けません。\n差し直してください。\n");
						return 1;
					}
				}
			}
		}
	}
	/*下方向に動くとき*/
	if(y_put > y_choice)
	{
		/*左下方向に動くとき*/
		if(x_put < x_choice)
		{
			for (xloop = x_put + 1; xloop < x_choice ; xloop++)
			{
				for (yloop = y_put - 1; yloop < y_choice; yloop--)
				{
					if (board[xloop][yloop] > 0)
					{
						printf("通り道にコマがあるため動けません。\n差し直してください。\n");
						return 1;
					}
				}
			}
		}
		/*右下に動くときの確認*/
		if (x_put > x_choice)
		{
			for (xloop = x_put - 1; xloop > x_choice ; xloop--)
			{
				for (yloop = y_put - 1; yloop > y_choice; yloop--)
				{
					if (board[xloop][yloop])
					{
						printf("通り道にコマがあるため動けません。\n差し直してください。\n");
						return 1;
					}
				}
			}
		}
	}

	/*移動した先に味方のコマがないかの確認*/
	if (board[x_put][y_put] <= 14)
	{
		printf("味方のコマが置いてあります.\n指し直してください.");
		return 1;
	}

	/*以下コマの移動、コマを取る処理*/
	/*相手のコマを取る処理*/
	if (board[x_put][y_put] >= 15)
	{
		for (loop1 = 0; loop1 < 39; loop1++)
		{
			if (have[loop1] == 0)
			{
				number = loop1;		/*コマを入れた配列を記録しておく*/
				have[loop1] = board[x_put][y_put] - 14;
				loop1 = 40;
			}
		}
		/*成りコマを取った場合元のコマに戻し手持ちに入れる*/
		for (loop1 = 17;loop1 <= 19; loop1 = loop1 + 2)
		{
			if(board[x_put][y_put] == loop1)
			{
				have[number]--;
			}
		}
		for (loop1 = 22; loop1 <= 28; loop1 = loop1 + 2)
		{
			if(board[x_put][y_put] == loop1)
			{
				have[number]--;
			}
		}
	}
	/*移動する処理*/
	board[x_put][y_put] = board[x_choice][y_choice];
	board[x_choice][y_choice] = 0;
	return 2;
}
//------------------------------------------------------------------------------------------------------------------------------------------------
/*裏角の動き 2*/
int urakaku_2(int board[11][11],int have[], int x_choice, int y_choice, int x_put, int y_put)
{
	int xloop;
	int yloop;
	int loop1;
	int number;

	if ((x_choice == x_put) || (y_put == y_choice) || ((x_put != x_choice - 1) || (x_put != x_choice) || (x_put != x_choice + 1)) && ((y_put != y_choice) || (y_put != y_choice + 1) || (y_put != y_choice - 1)))
	{
		printf("そこには,動けません.\n指し直してください.\n");
		return 1;
	}

	/*上方向に動くとき*/
	if (y_put <= y_choice)
	{
		/*左上方向に動く時の動けるかどうかの確認*/
		if (x_put <= x_choice)
		{
			for (xloop = x_put + 1; xloop < x_choice; xloop++)
			{
				for (yloop = y_put + 1; yloop < y_choice;yloop++ )
				{
					if (board[xloop][yloop] > 0)
					{
						printf("通り道にコマがあるため動けません。\n差し直してください。\n");
						return 1;
					}
				}
			}
		}
		/*右上方向に動く時の動けるかどうかの確認*/
		if (x_put >= x_choice)
		{
			for (xloop = x_put -1; x_choice < xloop; xloop--)
			{
				for (yloop = yloop + 1; yloop > y_choice;yloop--)
				{
					if(board[xloop][yloop] > 0)
					{
						printf("通り道にコマがあるため動けません。\n差し直してください。\n");
						return 1;
					}
				}
			}
		}
	}
	/*下方向に動くとき*/
	if(y_put > y_choice)
	{
		/*左下方向に動くとき*/
		if(x_put < x_choice)
		{
			for (xloop = x_put + 1; xloop < x_choice ; xloop++)
			{
				for (yloop = y_put - 1; yloop < y_choice; yloop--)
				{
					if (board[xloop][yloop] > 0)
					{
						printf("通り道にコマがあるため動けません。\n差し直してください。\n");
						return 1;
					}
				}
			}
		}
		/*右下に動くときの確認*/
		if (x_put > x_choice)
		{
			for (xloop = x_put - 1; xloop > x_choice ; xloop--)
			{
				for (yloop = y_put - 1; yloop > y_choice; yloop--)
				{
					if (board[xloop][yloop])
					{
						printf("通り道にコマがあるため動けません。\n差し直してください。\n");
						return 1;
					}
				}
			}
		}
	}

	/*移動した先に味方のコマがないかの確認*/
	if (board[x_put][y_put] >= 15)
	{
		printf("味方のコマが置いてあります.\n指し直してください.");
		return 1;
	}

	/*以下コマの移動、コマを取る処理*/
	/*相手のコマを取る処理*/
	if (board[x_put][y_put] <= 14)
	{
		for (loop1 = 0; loop1 < 39; loop1++)
		{
			if (have[loop1] == 0)
			{
				number = loop1;		/*コマを入れた配列を記録しておく*/
				have[loop1] = board[x_put][y_put] + 14;
				loop1 = 40;
			}
		}
		/*成りコマを取った場合元のコマに戻し手持ちに入れる*/
		for (loop1 = 3;loop1 <= 5; loop1 = loop1 + 2)
		{
			if(board[x_put][y_put] == loop1)
			{
				have[number]++;
			}
		}
		for (loop1 = 8; loop1 <= 14; loop1 = loop1 + 2)
		{
			if(board[x_put][y_put] == loop1)
			{
				have[number]++;
			}
		}
	}
	/*移動する処理*/
	board[x_put][y_put] = board[x_choice][y_choice];
	board[x_choice][y_choice] = 0;
	return 2;
}
//------------------------------------------------------------------------------------------------------------------------------------------------
/*裏飛車の動き 1*/
int urahisha_1(int board[11][11],int have[], int x_choice, int y_choice, int x_put, int y_put)
{
	int loop1;
	int loop2;
	int number;
	int option_nari;

	/*動けないマスが選択されたときは動かない*/
	/*周囲８マスも調べる*/
	if (((x_choice != x_put) && (y_choice != y_put)) || ((x_choice == x_put) && (y_choice == y_put)) || ((x_put != x_choice - 1) || (x_put != x_choice) || (x_put != x_choice + 1)) && ((y_put != y_choice) || (y_put != y_choice + 1) || (y_put != y_choice - 1))||(board[x_choice][y_choice] == 0) || (board[x_put][y_put] == -1))
	{
		printf("そこには動けません。\n指し直してください。\n");
		return 1;
	}
	/*動いていなかったらだめ*/
	if ((x_put == x_choice) && (y_put == y_choice))
	{
		printf("そこには動けません。\n指し直してください。\n");
		return 1;
	}

	/*動くマスに味方のコマがあったら動かない*/
	if (((board[x_choice][y_choice] <= 14) && (board[x_put][y_put] <= 14)))
	{
		printf("味方のコマが置いてあります。\n差し直してください。");
		return 1;
	}

	/*縦に動く場合*/
	if (x_choice == x_put)
	{
		if (y_choice > y_put)
		{
			/*動くマスと今いるマスの間に何もないかの確認の処理*/
			for (loop1 = y_put + 1;loop1 < y_choice;loop1++)
			{
				if (board[x_choice][loop1] > 0)
				{
					printf("通り道にコマがあるため動けません。\n差し直してください。\n");
					return 1;		/*何かあったら動けないので1を返す*/
				}
			}
		}
		else
		{
			/*動くマスと今いるマスの間に何もないかの確認の処理*/
			for (loop1 = y_choice + 1; loop1 < y_put; loop1++)
			{
				if (board[x_choice][loop1] > 0)
				{
					printf("通り道にコマがあるため動けません。\n差し直してください。\n");
					return 1;		/*何かあったら動けないので1を返す*/
				}
			}
		}
	}

	/*横の動くとき*/
	if (y_choice == y_put)
	{
		if (x_choice > x_put)
		{
			/*動くマスと今いるマスの間に何もないかの確認の処理*/
			for (loop1 = x_put + 1; loop1 < x_choice; loop1++)
			{
				if (board[loop1][y_choice] > 0)
				{
					printf("通り道にコマがあるため動けません。\n差し直してください。\n");
					return 1;		/*何かあったら動けないので1を返す*/
				}
			}
		}
		else
		{
			/*動くマスと今いるマスの間に何もないかの確認の処理*/
			for (loop1 = x_choice + 1; loop1 < x_put; loop1++)
			{
				if (board[loop1][y_choice] > 0)
				{
					printf("通り道にコマがあるため動けません。\n差し直してください。\n");
					return 1;		/*何かあったら動けないので1を返す*/
				}
			}
		}
	}

	/*以下の処理をするときは動けることが確定している、ここでコマの成りを判定する。*/
	/*相手のコマを自分のコマの番号に直し保存する処理*/
	if(board[x_put][y_put] >= 15)
	{
		for (loop2 = 0; loop2 <= 39; loop2++)
		{
			if (have[loop2] == 0)
			{
				number = loop2;
				have[loop2] = board[x_put][y_put] -14;	/*自分の対応する番号に修正し保存*/
				loop2 = 40;	/*ループから出るために代入*/
			}
		}

		/*成りコマは元のコマに直して保存する*/
		for (loop1 = 17;loop1 <= 19; loop1 = loop1 + 2)
		{
			if(board[x_put][y_put] == loop1)
			{
				have[number]--;
			}
		}
		for (loop1 = 22; loop1 <= 28; loop1 = loop1 + 2)
		{
			if(board[x_put][y_put] == loop1)
			{
				have[number]--;
			}
		}
	}
	/*動く処理*/
	board[x_put][y_put] = board[x_choice][y_choice];
	board[x_choice][y_choice] = 0;
	return 2;
}
//------------------------------------------------------------------------------------------------------------------------------------------------
/*裏飛車の動き 2*/
int urahisha_2(int board[11][11],int have[], int x_choice, int y_choice, int x_put, int y_put)
{
	int loop1;
	int loop2;
	int number;
	int option_nari;

	/*動けないマスが選択されたときは動かない*/
	/*周囲８マスをまずも調べる*/
	if (((x_choice != x_put) && (y_choice != y_put)) || ((x_choice == x_put) && (y_choice == y_put)) || ((x_put != x_choice - 1) || (x_put != x_choice) || (x_put != x_choice + 1)) && ((y_put != y_choice) || (y_put != y_choice + 1) || (y_put != y_choice - 1))|| (board[x_choice][y_choice] == 0) || (board[x_put][y_put] == -1))
	{
		printf("そこには動けません。\n指し直してください。\n");
		return 1;
	}
	/*動いていなかったらだめ*/
	if ((x_put == x_choice) && (y_put == y_choice))
	{
		printf("そこには動けません。\n指し直してください。\n");
		return 1;
	}

	/*動くマスに味方のコマがあったら動かない*/
	if (((board[x_choice][y_choice] >= 15) && (board[x_put][y_put] >= 15)))
	{
		printf("味方のコマが置いてあります。\n差し直してください。");
		return 1;
	}

	/*縦に動く場合*/
	if (x_choice == x_put)
	{
		if (y_choice > y_put)
		{
			/*動くマスと今いるマスの間に何もないかの確認の処理*/
			for (loop1 = y_put + 1;loop1 < y_choice;loop1++)
			{
				if (board[x_choice][loop1] > 0)
				{
					printf("通り道にコマがあるため動けません。\n差し直してください。\n");
					return 1;		/*何かあったら動けないので1を返す*/
				}
			}
		}
		else
		{
			/*動くマスと今いるマスの間に何もないかの確認の処理*/
			for (loop1 = y_choice + 1; loop1 < y_put; loop1++)
			{
				if (board[x_choice][loop1] > 0)
				{
					printf("通り道にコマがあるため動けません。\n差し直してください。\n");
					return 1;		/*何かあったら動けないので1を返す*/
				}
			}
		}
	}

	/*横の動くとき*/
	if (y_choice == y_put)
	{
		if (x_choice > x_put)
		{
			/*動くマスと今いるマスの間に何もないかの確認の処理*/
			for (loop1 = x_put + 1; loop1 < x_choice; loop1++)
			{
				if (board[loop1][y_choice] > 0)
				{
					printf("通り道にコマがあるため動けません。\n差し直してください。\n");
					return 1;		/*何かあったら動けないので1を返す*/
				}
			}
		}
		else
		{
			/*動くマスと今いるマスの間に何もないかの確認の処理*/
			for (loop1 = x_choice + 1; loop1 < x_put; loop1++)
			{
				if (board[loop1][y_choice] > 0)
				{
					printf("通り道にコマがあるため動けません。\n差し直してください。\n");
					return 1;		/*何かあったら動けないので1を返す*/
				}
			}
		}
	}

	/*以下の処理をするときは動けることが確定している、ここでコマの成りを判定する。*/
	/*相手のコマを自分のコマの番号に直し保存する処理*/
	if(board[x_put][y_put] <= 14)
	{
		for (loop2 = 0; loop2 <= 39; loop2++)
		{
			if (have[loop2] == 0)
			{
				number = loop2;
				have[loop2] = board[x_put][y_put] +14;	/*自分の対応する番号に修正し保存*/
				loop2 = 40;	/*ループから出るために代入*/
			}
		}

		/*成りコマは元のコマに直して保存する*/
		for (loop1 = 3;loop1 <= 5; loop1 = loop1 + 2)
		{
			if(board[x_put][y_put] == loop1)
			{
				have[number]++;
			}
		}
		for (loop1 = 8; loop1 <= 14; loop1 = loop1 + 2)
		{
			if(board[x_put][y_put] == loop1)
			{
				have[number]++;
			}
		}
	}
	/*動く処理*/
	board[x_put][y_put] = board[x_choice][y_choice];
	board[x_choice][y_choice] = 0;
	return 2;
}
//------------------------------------------------------------------------------------------------------------------------------------------------
int main (void)
{
    int board[11][11];//盤
	int i,j;
	char player_1[1024],player_2[1024];//プレイヤーの名前
	int have_1[12],have_2[12];//手持ち
	int turn=1;//ターンカウンタ
	int oute=0;//王手ポイント
	int x_choice;
	int y_choice;
	int x_put;
	int y_put;
	int discrimination;//1:置き直し,2:問題なし,3:負け
	int king[2][2]={{9,5},{1,5}};//王の位置・[プレイヤー][x,y]
	int conNum;//何をするかを決める番号(controlnum)
	//--------------------------------
	//boardの初期化
	for(i=0;i<10;i++)
	{
		if(i==0||i==10)
		{
			for(j=0;j<10;j++)
			{
				board[i][j]=99;
			}
		}
		else
		{
			if(j==0||j==10)
			{
				board[i][j]=99;
			}
			else
			{
				board[i][j]=0;
			}
			
		}
		
	}
	//--------------------------------
	//名前登録
	char player_1[1024],player_2[1024];//プレイヤーの名前
	int have_1[40],have_2[40];//手持ち
	int have_choice;
	int player_num;//プレイヤー番号
	printf("先攻・プレイヤー1さんの名前を登録してください:");
    scanf("%s",player_1);
    printf("後攻・プレイヤー2さんの名前を登録してください:");
    scanf("%s",player_2);
	display(board[11][11],have_1[12],have_2[12]);
	while(discrimination!=3)
	{
		if(turn%2==1&&discrimination!=1)
		{//先攻			
			printf("%sさんどの操作をするか入力してください.\n1:駒の移動, 2:持駒を置く, 3:投了:",player_1);
			scanf("%d",conNum);
			if(conNum==1)
			{
				printf("%sさんどこの駒(行　列)をどこのマス(行　列)に置くか入力してください.\n行　列　行　列:",player_1);
				scanf("%d %d %d %d",&x_choice,&y_choice,&x_put,&y_put);
				switch(board[x_choice][y_choice])
				{
					case 1:
						discrimination=oushou_1(board[11][11],have_1[12],x_choice,y_choice,x_put,y_put,king[2][2]);
						break;
					case 2:
						discrimination=hisha_1(board[11][11],have_1[12],x_choice,y_choice,x_put,y_put);
						break;
					case 3:
						discrimination=urahisha_1(board[11][11],have_1[12],x_choice,y_choice,x_put,y_put);
						break;
					case 4:
						discrimination=kaku_1(board[11][11],have_1[12],x_choice,y_choice,x_put,y_put);
						break;
					case 5:
						discrimination=urakaku_1(board[11][11],have_1[12],x_choice,y_choice,x_put,y_put);
						break;
					case 6:
						discrimination=kin_1(board[11][11],have_1[12],x_choice,y_choice,x_put,y_put);
						break;
					case 7:
						discrimination=silver_1(board[11][11],have_1[12],x_choice,y_choice,x_put,y_put);
						break;
					case 8:
						discrimination=kin_1(board[11][11],have_1[12],x_choice,y_choice,x_put,y_put);
						break;
					case 9:
						discrimination=keima_1(board[11][11],have_1[12],x_choice,y_choice,x_put,y_put);
						break;
					case 10:
						discrimination=kin_1(board[11][11],have_1[12],x_choice,y_choice,x_put,y_put);
						break;
					case 11:
						discrimination=kyousya_1(board[11][11],have_1[12],x_choice,y_choice,x_put,y_put);
						break;
					case 12:
						discrimination=kin_1(board[11][11],have_1[12],x_choice,y_choice,x_put,y_put);
						break;
					case 13:
						discrimination=hu_1(board[11][11],have_1[12],x_choice,y_choice,x_put,y_put);
						break;
					case 14:
						discrimination=kin_1(board[11][11],have_1[12],x_choice,y_choice,x_put,y_put);
						break;
				}	
				oute=scope_2(board[11][11],king[0][0],king[0][1]);
				if(oute==0)
				{
					oute=scope_1(board[11][11],king[1][0],king[1][1]);
					if(oute=>1)
					{
						printf("王手");
						for(i=1;i<=oute;i++)
						{
							printf("!");
						}
						printf("\n");
					}
				}
				else
				{
					discrimination=3;
					oute=2;//プレイヤー2
				}	
			}
			elseif(conNum==2)
			{
				printf("%sさんどの駒をどこのマス(行　列)に置くか入力してください.\n駒種類 行 列:",player_1);
				scanf("%d %d %d",&have_choice,&x_put,&y_put);
				player_num=1;
				discrimination=have_put(board,have_1,have_choice,x_put,y_put,player_num);
				oute=scope_2(board[11][11],king[0][0],king[0][1]);
				if(oute==0)
				{
					oute=scope_1(board[11][11],king[1][0],king[1][1]);
					if(oute=>1)
					{
						printf("王手");
						for(i=1;i<=oute;i++)
						{
							printf("!");
						}
						printf("\n");
					}
				}
				else
				{
					discrimination=3;
					oute=2;//プレイヤー2
				}
			}
			else
			{
				discrimination=3;
			}
			
		}

		if(turn%2==0&&discrimination!=1)
		{//後攻
			printf("%sさんどの操作をするか入力してください.\n1:駒の移動, 2:持駒を置く, 3:投了:",player_2);
			scanf("%d",conNum);
			if(conNum==1)
			{
				printf("%sさんどこのコマ(行　列)をどこのマス(行　列)に置くか入力してください./n",player_2);
				scanf("%d %d %d %d",&x_choice,&y_choice,&x_put,&y_put);
				switch(board[x_choice][y_choice])
				{
					case 15:
					discrimination=oushou_2(board[11][11],have_2[12],x_choice,y_choice,x_put,y_put,king[2][2]);
						break;
					case 16:
					discrimination=hisha_2(board[11][11],have_2[12],x_choice,y_choice,x_put,y_put);
						break;
					case 17:
						discrimination=urahisha_2(board[11][11],have_2[12],x_choice,y_choice,x_put,y_put);
						break;
					case 18:
						discrimination=kaku_2(board[11][11],have_2[12],x_choice,y_choice,x_put,y_put);
						break;
					case 19:
						discrimination=urakaku_2(board[11][11],have_2[12],x_choice,y_choice,x_put,y_put);
						break;
					case 20:
						discrimination=kin_2(board[11][11],have_2[12],x_choice,y_choice,x_put,y_put);
						break;
					case 21:
						discrimination=silver_2(board[11][11],have_2[12],x_choice,y_choice,x_put,y_put);
						break;
					case 22:
						discrimination=kin_2(board[11][11],have_2[12],x_choice,y_choice,x_put,y_put);
						break;
					case 23:
						discrimination=keima_2(board[11][11],have_2[12],x_choice,y_choice,x_put,y_put);
						break;
					case 24:
						discrimination=kin_2(board[11][11],have_2[12],x_choice,y_choice,x_put,y_put);
						break;
					case 25:
						discrimination=kyousya_2(board[11][11],have_2[12],x_choice,y_choice,x_put,y_put);
						break;
					case 26:
						discrimination=kin_2(board[11][11],have_2[12],x_choice,y_choice,x_put,y_put);
						break;
					case 27:
						discrimination=hu_2(board[11][11],have_2[12],x_choice,y_choice,x_put,y_put);
						break;
					case 28:
						discrimination=kin_2(board[11][11],have_2[12],x_choice,y_choice,x_put,y_put);
						break;
				}
				oute=scope_1(board[11][11],king[1][0],king[1][1]);
				if(oute==0)
				{
					oute=scope_2(board[11][11],king[0][0],king[0][1]);
					if(oute=>1)
					{
						printf("王手");
						for(i=1;i<=oute;i++)
						{
							printf("!");
						}
						printf("\n");
					}
				}
				else
				{
					discrimination=3;
					oute=1;//プレイヤー1
				}
			}
			elseif(conNum==2)
			{
				printf("%sさんどの駒をどこのマス(行　列)に置くか入力してください.\n駒種類 行 列:",player_2);
				scanf("%d %d %d",&have_choice,&x_put,&y_put);
				player_num=2;
				discrimination=have_put(board,have_2,have_choice,x_put,y_put,player_num);
				oute=scope_1(board[11][11],king[1][0],king[1][1]);
				if(oute==0)
				{
					oute=scope_2(board[11][11],king[0][0],king[0][1]);
					if(oute=>1)
					{
						printf("王手");
						for(i=1;i<=oute;i++)
						{
							printf("!");
						}
						printf("\n");
					}
				}
				else
				{
					discrimination=3;
					oute=1;//プレイヤー1
				}
			}
			else
			{
				discrimination = 3;
				oute = 1;//プレイヤー1
			}

		}
		if(discrimination!=1)
		{
			turn++;
		}
	}
	if(oute=1)
	{
		printf("%sさんが勝ちました!",player_1);
	}
	else
	{
		printf("%sさんが勝ちました!",player_2);
	}
    return 0;
}
