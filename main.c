//戻り値 1 配置不可
//戻り値 2 配置可

//branch ouandho
#include <stdio.h>

int up_kin(int board[11][11],int temoti[],int x_choice,int y_choice,int x_put,int y_put)              //1p金
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
			if (temoti[loop2] == 0)
			{
				number = loop2;
				temoti[loop2] = board[x_put][y_put] - 14;	/*自分の対応する番号に修正し保存*/
				loop2 = 40;	/*ループから出るために代入*/
			}
		}

		/*成りコマは元のコマに直して保存する*/
		for (loop1 = 17;loop1 <= 19; loop1 = loop1 + 2)
		{
			if(board[xput][yput] == loop1)
			{
				temoti[number]--;
			}
		}
		for (loop1 = 22; loop1 <= 28; loop1 = loop1 + 2)
		{
			if(banmen[x_put][y_put] == loop1)
			{
				temoti[number]--;
			}
		}
	}
}
        

int down_kin(int board[11][11],int temoti[],int x_choise,int y_choise,int x_put,int y_put)        //2p金
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
        printf("不正な入力です.\n指しなしてください.");
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
			if (temoti[loop2] == 0)
			{
				number = loop2;
				temoti[loop2] = board[x_put][y_put] - 14;	/*自分の対応する番号に修正し保存*/
				loop2 = 40;	/*ループから出るために代入*/
			}
		}

		/*成りコマは元のコマに直して保存する*/
		for (loop1 = 17;loop1 <= 19; loop1 = loop1 + 2)
		{
			if(board[xput][yput] == loop1)
			{
				temoti[number]--;
			}
		}
		for (loop1 = 22; loop1 <= 28; loop1 = loop1 + 2)
		{
			if(banmen[x_put][y_put] == loop1)
			{
				temoti[number]--;
			}
		}
	}
}

int up_kyousya(int board[11][11],int temoti[],int x_choice,int y_choice,int x_put,int y_put)      //1p香車
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
        printf("成る:1\n成らない:2");
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
            printf("成る:1\n成らない:2");
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
			if (temoti[loop2] == 0)
			{
				number = loop2;
				temoti[loop2] = board[x_put][y_put] - 14;	/*自分の対応する番号に修正し保存*/
				loop2 = 40;	/*ループから出るために代入*/
			}
		}

		/*成りコマは元のコマに直して保存する*/
		for (loop1 = 17;loop1 <= 19; loop1 = loop1 + 2)
		{
			if(board[xput][yput] == loop1)
			{
				temoti[number]--;
			}
		}
		for (loop1 = 22; loop1 <= 28; loop1 = loop1 + 2)
		{
			if(banmen[x_put][y_put] == loop1)
			{
				temoti[number]--;
			}
		}
	}
}

int down_kyousya(int board[11][11],int temoti[],int x_choice,int y_choice,int x_put,int y_put)    //2p香車
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
        printf("成る:1\n成らない:2");
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
            printf("成る:1\n成らない:2");
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
			if (temoti[loop2] == 0)
			{
				number = loop2;
				temoti[loop2] = board[x_put][y_put] - 14;	/*自分の対応する番号に修正し保存*/
				loop2 = 40;	/*ループから出るために代入*/
			}
		}

		/*成りコマは元のコマに直して保存する*/
		for (loop1 = 17;loop1 <= 19; loop1 = loop1 + 2)
		{
			if(board[xput][yput] == loop1)
			{
				temoti[number]--;
			}
		}
		for (loop1 = 22; loop1 <= 28; loop1 = loop1 + 2)
		{
			if(banmen[x_put][y_put] == loop1)
			{
				temoti[number]--;
			}
		}
	}
}

/*飛車の動き*/
/*飛車の動き*/
int hisha_1(int banmen[11][11],int temoti[], int xhaiti, int yhaiti, int xmuve, int ymuve)
{
	int loop1;
	int loop2;
	int number;
	int option_nari;

	/*動けないマスが選択されたときは動かない*/
	if (((xhaiti != xmuve) && (yhaiti != ymuve)) || ((xhaiti == xmuve) && (yhaiti == ymuve)) || (banmen[xhaiti][yhaiti] == 0) || (banmen[xmuve][ymuve] == -1))
	{
		printf("そこには動けません。\n指し直してください。\n");
		return 1;
	}

	/*動くマスに味方のコマがあったら動かない*/
	if (((banmen[xhaiti][yhaiti] <= 14) && (banmen[xmuve][ymuve] <= 14)))
	{
		printf("味方のコマが置いてあります。\n差し直してください。");
		return 1;
	}
	
	/*縦に動く場合*/
	if (xhaiti == xmuve)
	{
		if (yhaiti > ymuve)
		{
			/*動くマスと今いるマスの間に何もないかの確認の処理*/
			for (loop1 = ymuve + 1;loop1 < yhaiti;loop1++)
			{
				if (banmen[xhaiti][loop1] > 0)
				{
					printf("通り道にコマがあるため動けません。\n差し直してください。\n");
					return 1;		/*何かあったら動けないので1を返す*/
				}
			}
		}
		else
		{
			/*動くマスと今いるマスの間に何もないかの確認の処理*/
			for (loop1 = yhaiti + 1; loop1 < ymuve; loop1++)
			{
				if (banmen[xhaiti][loop1] > 0)
				{
					printf("通り道にコマがあるため動けません。\n差し直してください。\n");
					return 1;		/*何かあったら動けないので1を返す*/
				}
			}
		}
	}

	/*横の動くとき*/
	if (yhaiti == ymuve)
	{
		if (xhaiti > xmuve)
		{
			/*動くマスと今いるマスの間に何もないかの確認の処理*/
			for (loop1 = xmuve + 1; loop1 < xhaiti; loop1++)
			{
				if (banmen[loop1][yhaiti] > 0)
				{
					printf("通り道にコマがあるため動けません。\n差し直してください。\n");
					return 1;		/*何かあったら動けないので1を返す*/
				}
			}
		}
		else
		{
			/*動くマスと今いるマスの間に何もないかの確認の処理*/
			for (loop1 = xhaiti + 1; loop1 < xmuve; loop1++)
			{
				if (banmen[loop1][yhaiti] > 0)
				{
					printf("通り道にコマがあるため動けません。\n差し直してください。\n");
					return 1;		/*何かあったら動けないので1を返す*/
				}
			}
		}
	}

	/*以下の処理をするときは動けることが確定している、ここでコマの成りを判定する。*/
	/*相手のコマを自分のコマの番号に直し保存する処理*/
	if(banmen[xmuve][ymuve] >= 15)
	{
		for (loop2 = 0; loop2 <= 39; loop2++)
		{
			if (temoti[loop2] == 0)
			{
				number = loop2;
				temoti[loop2] = banmen[xmuve][ymuve] -14;	/*自分の対応する番号に修正し保存*/
				loop2 = 40;	/*ループから出るために代入*/
			}
		}

		/*成りコマは元のコマに直して保存する*/
		for (loop1 = 17;loop1 <= 19; loop1 = loop1 + 2)
		{
			if(banmen[xmuve][ymuve] == loop1)
			{
				temoti[number]--;
			}
		}
		for (loop1 = 22; loop1 <= 28; loop1 = loop1 + 2)
		{
			if(banmen[xmuve][ymuve] == loop1)
			{
				temoti[number]--;
			}
		}
	}

	/*成りの判定、及び動く処理*/
	if ((banmen[xmuve][ymuve] <= 3) || (banmen[xhaiti][yhaiti] <= 3))
	{
		while (1)
		{
			printf("成る:1\n成らない:2\n");
			scanf("%d", &option_nari);
			
			if (option_nari == 1)
			{
		
				banmen[xmuve][ymuve] = 3;
				banmen[xhaiti][yhaiti] = 0;
				return 2;
			}
			if (option_nari == 2)
			{
				banmen[xmuve][ymuve] = banmen[xhaiti][yhaiti];
				banmen[xhaiti][yhaiti] = 0;
				return 2;
			}
		}
	}
	else
	{
		banmen[xmuve][ymuve] = banmen[xhaiti][yhaiti];
		banmen[xhaiti][yhaiti] = 0;
		return 2;
	}
}
//------------------------------------------------------------------------------------------------------------------------------------------------
int hisha_2(int banmen[11][11],int temoti[], int xhaiti, int yhaiti, int xmuve, int ymuve)
{
	int loop1;
	int loop2;
	int number;
	int option_nari;

	/*動けないマスが選択されたときは動かない*/
	if (((xhaiti != xmuve) && (yhaiti != ymuve)) || ((xhaiti == xmuve) && (yhaiti == ymuve)) || (banmen[xhaiti][yhaiti] == 0) || (banmen[xmuve][ymuve] == -1))
	{
		printf("そこには動けません。\n指し直してください。\n");
		return 1;
	}

	/*動くマスに味方のコマがあったら動かない*/
	if (((banmen[xhaiti][yhaiti] >= 15) && (banmen[xmuve][ymuve] >= 15)))
	{
		printf("味方のコマが置いてあります。\n差し直してください。");
		return 1;
	}
	
	/*縦に動く場合*/
	if (xhaiti == xmuve)
	{
		if (yhaiti > ymuve)
		{
			/*動くマスと今いるマスの間に何もないかの確認の処理*/
			for (loop1 = ymuve + 1;loop1 < yhaiti;loop1++)
			{
				if (banmen[xhaiti][loop1] > 0)
				{
					printf("通り道にコマがあるため動けません。\n差し直してください。\n");
					return 1;		/*何かあったら動けないので1を返す*/
				}
			}
		}
		else
		{
			/*動くマスと今いるマスの間に何もないかの確認の処理*/
			for (loop1 = yhaiti + 1; loop1 < ymuve; loop1++)
			{
				if (banmen[xhaiti][loop1] > 0)
				{
					printf("通り道にコマがあるため動けません。\n差し直してください。\n");
					return 1;		/*何かあったら動けないので1を返す*/
				}
			}
		}
	}

	/*横の動くとき*/
	if (yhaiti == ymuve)
	{
		if (xhaiti > xmuve)
		{
			/*動くマスと今いるマスの間に何もないかの確認の処理*/
			for (loop1 = xmuve + 1; loop1 < xhaiti; loop1++)
			{
				if (banmen[loop1][yhaiti] > 0)
				{
					printf("通り道にコマがあるため動けません。\n差し直してください。\n");
					return 1;		/*何かあったら動けないので1を返す*/
				}
			}
		}
		else
		{
			/*動くマスと今いるマスの間に何もないかの確認の処理*/
			for (loop1 = xhaiti + 1; loop1 < xmuve; loop1++)
			{
				if (banmen[loop1][yhaiti] > 0)
				{
					printf("通り道にコマがあるため動けません。\n差し直してください。\n");
					return 1;		/*何かあったら動けないので1を返す*/
				}
			}
		}
	}

	/*以下の処理をするときは動けることが確定している、ここでコマの成りを判定する。*/
	if(banmen[xmuve][ymuve] <= 14)
	{
		for (loop2 = 0; loop2 <= 39; loop2++)
		{
			if (temoti[loop2] == 0)
			{
				number = loop2;
				temoti[loop2] = banmen[xmuve][ymuve] +14;	/*自分の対応する番号に修正し保存*/
				loop2 = 40;	/*ループから出るために代入*/
			}
		}

		/*成りコマは元のコマに直して保存する*/
		for (loop1 = 3;loop1 <= 5; loop1 = loop1 + 2)
		{
			if(banmen[xmuve][ymuve] == loop1)
			{
				temoti[number]++;
			}
		}
		for (loop1 = 8; loop1 <= 14; loop1 = loop1 + 2)
		{
			if(banmen[xmuve][ymuve] == loop1)
			{
				temoti[number]++;
			}
		}
	}
	
	/*成りの判定、及び移動の処理*/
	if ((banmen[xhaiti][yhaiti] >= 8) || (banmen[xmuve][ymuve] >= 8))
	{
		/*成るかどうか決めるまでループ*/
		while (1)
		{
			printf("成る:1\n成らない:2\n");
			scanf("%d" ,&option_nari);
			
			if (option_nari == 1)
			{
				banmen[xmuve][ymuve] = 17;
				banmen[xhaiti][yhaiti] = 0;
				return 2;
			}
			
			if (option_nari == 2)
			{
				banmen[xmuve][ymuve] = banmen[xhaiti][yhaiti];
				banmen[xhaiti][yhaiti] = 0;
				return 2;
			}
		}
	}
	else		/*成れない場合移動の処理をする*/
	{
		banmen[xmuve][ymuve] = banmen[xhaiti][yhaiti];
		banmen[xhaiti][yhaiti] = 0;
		return 2;		
	}
}
//------------------------------------------------------------------------------------------------------------------------------------------------
int oushou_1(int board[11][11],int have[40],int x_choise,int y_choise,int x_put,int y_put)
{
    int i, j, around[3] = {-1, 0, 1};
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
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            if(x_choise + around[i] == x_put && y_choise + around[j] == y_put)
            {
                while(have[k] != 0)
				{//空欄まで進む
					k++;
				}
				have[k] = board[x_put][y_put]+14;
				board[x_put][y_put] = 1;
                return 2;
            }
        }
    }
    printf("そこには,動けません.\n指し直してください.");
    return 1;
}
//------------------------------------------------------------------------------------------------------------------------------------------------
int oushou_2(int board[11][11],int  have[40], int x_choise,int y_choise,int x_put,int y_put)
{
    int i, j, around[3] = {-1, 0, 1};
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
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            if(x_choise + around[i] == x_put && y_choise + around[j] == y_put)
            {
                while(have[k] != 0)
				{//空欄まで進む
					k++;
				}
				have[k] = board[x_put][y_put]-14;
				board[x_put][y_put] = 15;
                return 2;
            }
        }
    }
    printf("そこには,動けません.\n指し直してください.");
    return 1;
}
//------------------------------------------------------------------------------------------------------------------------------------------------
int hu_1(int board[11][11],int have[40],int x_choise,int y_choise,int x_put,int y_put)
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
    if(x_put == x_choise && y_put == y_choise)
    {//同じ位置のとき
        printf("動いてません.\n指し直してください.");
        return 1;
    }
    if(y_choise - 1 == y_put)
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
                printf("成る:1\n成らない:2");
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
int hu_2(int board[11][11],int have[40],int x_choise,int y_choise,int x_put,int y_put)
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
    if(x_put == x_choise && y_put == y_choise)
    {//同じ位置のとき
        printf("動いてません.\n指し直してください.");
        return 1;
    }
    if(y_choise + 1 == y_put)
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
                printf("成る:1\n成らない:2");
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
int keima_1(int board[11][11], int have[40], int x_choice, int y_choice, int x_put, int y_put)
{
	int i = 0;
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
	if ((x_choice - 2 == x_put) && (y_choice - 1 == y_put))
	{
		if (x_put <= 3)
		{
			if (x_put == 3)
			{
				while (num != '1' && num != '2')
				{
					printf("成る＝1,成らない＝2\n");
					scanf("%c", &num);
					if (num == '1')
					{
						board[x_put][y_put] = 10;
						return 2;
					}
				}
			}
			if (x_put == 1)
			{
				board[x_put][y_put] = 10;
				return 2;
			}
		}
		else
		{
			board[x_put][y_put] = 9;
			return 2;
		}
		if ((15 <= board[x_put][y_put]) && (board[x_put][y_put] <= 28))
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
int keima_2(int board[11][11], int have[40], int x_choice, int y_choice, int x_put, int y_put)
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
int silver_1(int board[11][11], int have[40], int x_choice, int y_choice, int x_put, int y_put)
{
	int i, j, k = 0, front[3] = { -1, 0, 1 }, back[2] = { -1, 1 };
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
		if ((x_choice + 1 == x_put) && (y_choice + front[i] == y_put))
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
int silver_2(int board[11][11], int have[40], int x_choice, int y_choice, int x_put, int y_put)
{
	int i, j, k = 0, front[3] = { -1, 0, 1 }, back[2] = { -1, 1 };
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
		if ((x_choice + 1 == x_put) && (y_choice + front[i] == y_put))
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

/*角の動き*/
int kaku_1(int banmen[11][11],int temoti[], int xhaiti, int yhaiti, int xmuve, int ymuve)
{
	int xloop;
	int yloop;
	int loop1;
	int number;
	int option_nari;

	if ((xhaiti == xmuve) || (ymuve == yhaiti))
	{
		printf("そこには,動けません.\n指し直してください.\n");
		return 1;
	}

	/*上方向に動くとき*/
	if (ymuve <= yhaiti)
	{
		/*左上方向に動く時の動けるかどうかの確認*/
		if (xmuve <= xhaiti)
		{
			for (xloop = xmuve + 1; xloop < xhaiti; xloop++)
			{
				for (yloop = ymuve + 1; yloop < ymuve;yloop++ )
				{
					if (banmen[xloop][yloop] > 0)
					{
						printf("通り道にコマがあるため動けません。\n差し直してください。\n");
						return 1;
					}
				}
			}
		}
		/*右上方向に動く時の動けるかどうかの確認*/
		if (xmuve >= xhaiti)
		{
			for (xloop = xmuve -1; xhaiti < xloop; xloop--)
			{
				for (yloop = yloop + 1; yloop > yhaiti;yloop--)
				{
					if(banmen[xloop][yloop] > 0)
					{
						printf("通り道にコマがあるため動けません。\n差し直してください。\n");
						return 1;
					}
				}
			}
		}
	}
	/*下方向に動くとき*/
	if(ymuve > yhaiti)
	{
		/*左下方向に動くとき*/
		if(xmuve < xhaiti)
		{
			for (xloop = xmuve + 1; xloop < xhaiti ; xloop++)
			{
				for (yloop = ymuve - 1; yloop < yhaiti; yloop--)
				{
					if (banmen[xloop][yloop] > 0)
					{
						printf("通り道にコマがあるため動けません。\n差し直してください。\n");
						return 1;
					}
				}
			}
		}
		/*右下に動くときの確認*/
		if (xmuve > xhaiti)
		{
			for (xloop = xmuve - 1; xloop > xhaiti ; xloop--)
			{
				for (yloop = ymuve - 1; yloop > yhaiti; yloop--)
				{
					if (banmen[xloop][yloop])
					{
						printf("通り道にコマがあるため動けません。\n差し直してください。\n");
						return 1;
					}
				}
			}
		}
	}

	/*移動した先に味方のコマがないかの確認*/
	if (banmen[xmuve][ymuve] <= 14)
	{
		printf("味方のコマが置いてあります.\n指し直してください.");
		return 1;
	}

	/*以下コマの移動、コマを取る処理*/
	/*相手のコマを取る処理*/
	if (banmen[xmuve][ymuve] >= 15)
	{
		for (loop1 = 0; loop1 < 39; loop1++)
		{
			if (temoti[loop1] == 0)
			{
				number = loop1;		/*コマを入れた配列を記録しておく*/
				temoti[loop1] = banmen[xmuve][ymuve] - 14;
				loop1 = 40;
			}
		}
		/*成りコマを取った場合元のコマに戻し手持ちに入れる*/
		for (loop1 = 17;loop1 <= 19; loop1 = loop1 + 2)
		{
			if(banmen[xmuve][ymuve] == loop1)
			{
				temoti[number]--;
			}
		}
		for (loop1 = 22; loop1 <= 28; loop1 = loop1 + 2)
		{
			if(banmen[xmuve][ymuve] == loop1)
			{
				temoti[number]--;
			}
		}
	}
	/*成り及び移動する処理*/
	if ((banmen[xmuve][ymuve] <= 3) || (banmen[xhaiti][yhaiti] <= 3))
	{
		while (1)
		{
			printf("成る:1\n成らない:2\n");
			scanf("%d", &option_nari);
			
			if (option_nari == 1)
			{
		
				banmen[xmuve][ymuve] = 5;
				banmen[xhaiti][yhaiti] = 0;
				return 2;
			}
			if (option_nari == 2)
			{
				banmen[xmuve][ymuve] = banmen[xhaiti][yhaiti];
				banmen[xhaiti][yhaiti] = 0;
				return 2;
			}
		}
	}
	else
	{
		banmen[xmuve][ymuve] = banmen[xhaiti][yhaiti];
		banmen[xhaiti][yhaiti] = 0;
		return 2;
	}
}

/*角の動き,preyer2*/
int kaku_2(int banmen[11][11],int temoti[], int xhaiti, int yhaiti, int xmuve, int ymuve)
{
	int xloop;
	int yloop;
	int loop1;
	int number;
	int option_nari;

	if ((xhaiti == xmuve) || (ymuve == yhaiti))
	{
		printf("そこには,動けません.\n指し直してください.\n");
		return 1;
	}

	/*上方向に動くとき*/
	if (ymuve <= yhaiti)
	{
		/*左上方向に動く時の動けるかどうかの確認*/
		if (xmuve <= xhaiti)
		{
			for (xloop = xmuve + 1; xloop < xhaiti; xloop++)
			{
				for (yloop = ymuve + 1; yloop < yhaiti;yloop++ )
				{
					if (banmen[xloop][yloop] > 0)
					{
						printf("通り道にコマがあるため動けません。\n差し直してください。\n");
						return 1;
					}
				}
			}
		}
		/*右上方向に動く時の動けるかどうかの確認*/
		if (xmuve >= xhaiti)
		{
			for (xloop = xmuve -1; xhaiti < xloop; xloop--)
			{
				for (yloop = yloop + 1; yloop > yhaiti;yloop--)
				{
					if(banmen[xloop][yloop] > 0)
					{
						printf("通り道にコマがあるため動けません。\n差し直してください。\n");
						return 1;
					}
				}
			}
		}
	}
	/*下方向に動くとき*/
	if(ymuve > yhaiti)
	{
		/*左下方向に動くとき*/
		if(xmuve < xhaiti)
		{
			for (xloop = xmuve + 1; xloop < xhaiti ; xloop++)
			{
				for (yloop = ymuve - 1; yloop < yhaiti; yloop--)
				{
					if (banmen[xloop][yloop] > 0)
					{
						printf("通り道にコマがあるため動けません。\n差し直してください。\n");
						return 1;
					}
				}
			}
		}
		/*右下に動くときの確認*/
		if (xmuve > xhaiti)
		{
			for (xloop = xmuve - 1; xloop > xhaiti ; xloop--)
			{
				for (yloop = ymuve - 1; yloop > yhaiti; yloop--)
				{
					if (banmen[xloop][yloop])
					{
						printf("通り道にコマがあるため動けません。\n差し直してください。\n");
						return 1;
					}
				}
			}
		}
	}

	/*移動した先に味方のコマがないかの確認*/
	if (banmen[xmuve][ymuve] >= 15)
	{
		printf("味方のコマが置いてあります.\n指し直してください.");
		return 1;
	}

	/*以下コマの移動、コマを取る処理*/
	/*相手のコマを取る処理*/
	if (banmen[xmuve][ymuve] <= 14)
	{
		for (loop1 = 0; loop1 < 39; loop1++)
		{
			if (temoti[loop1] == 0)
			{
				number = loop1;		/*コマを入れた配列を記録しておく*/
				temoti[loop1] = banmen[xmuve][ymuve] + 14;
				loop1 = 40;
			}
		}
		/*成りコマを取った場合元のコマに戻し手持ちに入れる*/
		for (loop1 = 3;loop1 <= 5; loop1 = loop1 + 2)
		{
			if(banmen[xmuve][ymuve] == loop1)
			{
				temoti[number]++;
			}
		}
		for (loop1 = 8; loop1 <= 14; loop1 = loop1 + 2)
		{
			if(banmen[xmuve][ymuve] == loop1)
			{
				temoti[number]++;
			}
		}
	}
	/*成り及び移動する処理*/
	if ((banmen[xmuve][ymuve] <= 3) || (banmen[xhaiti][yhaiti] <= 3))
	{
		while (1)
		{
			printf("成る:1\n成らない:2\n");
			scanf("%d", &option_nari);
			
			if (option_nari == 1)
			{
		
				banmen[xmuve][ymuve] = 19;
				banmen[xhaiti][yhaiti] = 0;
				return 2;
			}
			if (option_nari == 2)
			{
				banmen[xmuve][ymuve] = banmen[xhaiti][yhaiti];
				banmen[xhaiti][yhaiti] = 0;
				return 2;
			}
		}
	}
	else
	{
		banmen[xmuve][ymuve] = banmen[xhaiti][yhaiti];
		banmen[xhaiti][yhaiti] = 0;
		return 2;
	}
}

/*裏角の動き 1*/
int urakaku_1(int banmen[11][11],int temoti[], int xhaiti, int yhaiti, int xmuve, int ymuve)
{
	int xloop;
	int yloop;
	int loop1;
	int number;

	if ((xhaiti == xmuve) || (ymuve == yhaiti) || ((xmuve != xhaiti - 1) || (xmuve != xhaiti) || (xmuve != xhaiti + 1)) && ((ymuve != yhaiti) || (ymuve != yhaiti + 1) || (ymuve != yhaiti - 1)))
	{
		printf("そこには,動けません.\n指し直してください.\n");
		return 1;
	}

	/*上方向に動くとき*/
	if (ymuve <= yhaiti)
	{
		/*左上方向に動く時の動けるかどうかの確認*/
		if (xmuve <= xhaiti)
		{
			for (xloop = xmuve + 1; xloop < xhaiti; xloop++)
			{
				for (yloop = ymuve + 1; yloop < yhaiti;yloop++ )
				{
					if (banmen[xloop][yloop] > 0)
					{
						printf("通り道にコマがあるため動けません。\n差し直してください。\n");
						return 1;
					}
				}
			}
		}
		/*右上方向に動く時の動けるかどうかの確認*/
		if (xmuve >= xhaiti)
		{
			for (xloop = xmuve -1; xhaiti < xloop; xloop--)
			{
				for (yloop = yloop + 1; yloop > yhaiti; yloop--)
				{
					if(banmen[xloop][yloop] > 0)
					{
						printf("通り道にコマがあるため動けません。\n差し直してください。\n");
						return 1;
					}
				}
			}
		}
	}
	/*下方向に動くとき*/
	if(ymuve > yhaiti)
	{
		/*左下方向に動くとき*/
		if(xmuve < xhaiti)
		{
			for (xloop = xmuve + 1; xloop < xhaiti ; xloop++)
			{
				for (yloop = ymuve - 1; yloop < yhaiti; yloop--)
				{
					if (banmen[xloop][yloop] > 0)
					{
						printf("通り道にコマがあるため動けません。\n差し直してください。\n");
						return 1;
					}
				}
			}
		}
		/*右下に動くときの確認*/
		if (xmuve > xhaiti)
		{
			for (xloop = xmuve - 1; xloop > xhaiti ; xloop--)
			{
				for (yloop = ymuve - 1; yloop > yhaiti; yloop--)
				{
					if (banmen[xloop][yloop])
					{
						printf("通り道にコマがあるため動けません。\n差し直してください。\n");
						return 1;
					}
				}
			}
		}
	}

	/*移動した先に味方のコマがないかの確認*/
	if (banmen[xmuve][ymuve] <= 14)
	{
		printf("味方のコマが置いてあります.\n指し直してください.");
		return 1;
	}

	/*以下コマの移動、コマを取る処理*/
	/*相手のコマを取る処理*/
	if (banmen[xmuve][ymuve] >= 15)
	{
		for (loop1 = 0; loop1 < 39; loop1++)
		{
			if (temoti[loop1] == 0)
			{
				number = loop1;		/*コマを入れた配列を記録しておく*/
				temoti[loop1] = banmen[xmuve][ymuve] - 14;
				loop1 = 40;
			}
		}
		/*成りコマを取った場合元のコマに戻し手持ちに入れる*/
		for (loop1 = 17;loop1 <= 19; loop1 = loop1 + 2)
		{
			if(banmen[xmuve][ymuve] == loop1)
			{
				temoti[number]--;
			}
		}
		for (loop1 = 22; loop1 <= 28; loop1 = loop1 + 2)
		{
			if(banmen[xmuve][ymuve] == loop1)
			{
				temoti[number]--;
			}
		}
	}
	/*移動する処理*/
	banmen[xmuve][ymuve] = banmen[xhaiti][yhaiti];
	banmen[xhaiti][yhaiti] = 0;
	return 2;
}
/*裏角の動き 1*/
int urakaku_1(int banmen[11][11],int temoti[], int xhaiti, int yhaiti, int xmuve, int ymuve)
{
	int xloop;
	int yloop;
	int loop1;
	int number;

	if ((xhaiti == xmuve) || (ymuve == yhaiti) || ((xmuve != xhaiti - 1) || (xmuve != xhaiti) || (xmuve != xhaiti + 1)) && ((ymuve != yhaiti) || (ymuve != yhaiti + 1) || (ymuve != yhaiti - 1)))
	{
		printf("そこには,動けません.\n指し直してください.\n");
		return 1;
	}

	/*上方向に動くとき*/
	if (ymuve <= yhaiti)
	{
		/*左上方向に動く時の動けるかどうかの確認*/
		if (xmuve <= xhaiti)
		{
			for (xloop = xmuve + 1; xloop < xhaiti; xloop++)
			{
				for (yloop = ymuve + 1; yloop < yhaiti;yloop++ )
				{
					if (banmen[xloop][yloop] > 0)
					{
						printf("通り道にコマがあるため動けません。\n差し直してください。\n");
						return 1;
					}
				}
			}
		}
		/*右上方向に動く時の動けるかどうかの確認*/
		if (xmuve >= xhaiti)
		{
			for (xloop = xmuve -1; xhaiti < xloop; xloop--)
			{
				for (yloop = yloop + 1; yloop > yhaiti;yloop--)
				{
					if(banmen[xloop][yloop] > 0)
					{
						printf("通り道にコマがあるため動けません。\n差し直してください。\n");
						return 1;
					}
				}
			}
		}
	}
	/*下方向に動くとき*/
	if(ymuve > yhaiti)
	{
		/*左下方向に動くとき*/
		if(xmuve < xhaiti)
		{
			for (xloop = xmuve + 1; xloop < xhaiti ; xloop++)
			{
				for (yloop = ymuve - 1; yloop < yhaiti; yloop--)
				{
					if (banmen[xloop][yloop] > 0)
					{
						printf("通り道にコマがあるため動けません。\n差し直してください。\n");
						return 1;
					}
				}
			}
		}
		/*右下に動くときの確認*/
		if (xmuve > xhaiti)
		{
			for (xloop = xmuve - 1; xloop > xhaiti ; xloop--)
			{
				for (yloop = ymuve - 1; yloop > yhaiti; yloop--)
				{
					if (banmen[xloop][yloop])
					{
						printf("通り道にコマがあるため動けません。\n差し直してください。\n");
						return 1;
					}
				}
			}
		}
	}

	/*移動した先に味方のコマがないかの確認*/
	if (banmen[xmuve][ymuve] >= 15)
	{
		printf("味方のコマが置いてあります.\n指し直してください.");
		return 1;
	}

	/*以下コマの移動、コマを取る処理*/
	/*相手のコマを取る処理*/
	if (banmen[xmuve][ymuve] <= 14)
	{
		for (loop1 = 0; loop1 < 39; loop1++)
		{
			if (temoti[loop1] == 0)
			{
				number = loop1;		/*コマを入れた配列を記録しておく*/
				temoti[loop1] = banmen[xmuve][ymuve] + 14;
				loop1 = 40;
			}
		}
		/*成りコマを取った場合元のコマに戻し手持ちに入れる*/
		for (loop1 = 3;loop1 <= 5; loop1 = loop1 + 2)
		{
			if(banmen[xmuve][ymuve] == loop1)
			{
				temoti[number]++;
			}
		}
		for (loop1 = 8; loop1 <= 14; loop1 = loop1 + 2)
		{
			if(banmen[xmuve][ymuve] == loop1)
			{
				temoti[number]++;
			}
		}
	}
	/*移動する処理*/
	banmen[xmuve][ymuve] = banmen[xhaiti][yhaiti];
	banmen[xhaiti][yhaiti] = 0;
	return 2;
}

/*裏飛車の動き 1*/
int urahisha_1(int banmen[11][11],int temoti[], int xhaiti, int yhaiti, int xmuve, int ymuve)
{
	int loop1;
	int loop2;
	int number;
	int option_nari;

	/*動けないマスが選択されたときは動かない*/
	/*周囲８マスも調べる*/
	if (((xhaiti != xmuve) && (yhaiti != ymuve)) || ((xhaiti == xmuve) && (yhaiti == ymuve)) || ((xmuve != xhaiti - 1) || (xmuve != xhaiti) || (xmuve != xhaiti + 1)) && ((ymuve != yhaiti) || (ymuve != yhaiti + 1) || (ymuve != yhaiti - 1))||(banmen[xhaiti][yhaiti] == 0) || (banmen[xmuve][ymuve] == -1))
	{
		printf("そこには動けません。\n指し直してください。\n");
		return 1;
	}
	/*動いていなかったらだめ*/
	if ((xmuve == xhaiti) && (ymuve == yhaiti))
	{
		printf("そこには動けません。\n指し直してください。\n");
		return 1;
	}

	/*動くマスに味方のコマがあったら動かない*/
	if (((banmen[xhaiti][yhaiti] <= 14) && (banmen[xmuve][ymuve] <= 14)))
	{
		printf("味方のコマが置いてあります。\n差し直してください。");
		return 1;
	}

	/*縦に動く場合*/
	if (xhaiti == xmuve)
	{
		if (yhaiti > ymuve)
		{
			/*動くマスと今いるマスの間に何もないかの確認の処理*/
			for (loop1 = ymuve + 1;loop1 < yhaiti;loop1++)
			{
				if (banmen[xhaiti][loop1] > 0)
				{
					printf("通り道にコマがあるため動けません。\n差し直してください。\n");
					return 1;		/*何かあったら動けないので1を返す*/
				}
			}
		}
		else
		{
			/*動くマスと今いるマスの間に何もないかの確認の処理*/
			for (loop1 = yhaiti + 1; loop1 < ymuve; loop1++)
			{
				if (banmen[xhaiti][loop1] > 0)
				{
					printf("通り道にコマがあるため動けません。\n差し直してください。\n");
					return 1;		/*何かあったら動けないので1を返す*/
				}
			}
		}
	}

	/*横の動くとき*/
	if (yhaiti == ymuve)
	{
		if (xhaiti > xmuve)
		{
			/*動くマスと今いるマスの間に何もないかの確認の処理*/
			for (loop1 = xmuve + 1; loop1 < xhaiti; loop1++)
			{
				if (banmen[loop1][yhaiti] > 0)
				{
					printf("通り道にコマがあるため動けません。\n差し直してください。\n");
					return 1;		/*何かあったら動けないので1を返す*/
				}
			}
		}
		else
		{
			/*動くマスと今いるマスの間に何もないかの確認の処理*/
			for (loop1 = xhaiti + 1; loop1 < xmuve; loop1++)
			{
				if (banmen[loop1][yhaiti] > 0)
				{
					printf("通り道にコマがあるため動けません。\n差し直してください。\n");
					return 1;		/*何かあったら動けないので1を返す*/
				}
			}
		}
	}

	/*以下の処理をするときは動けることが確定している、ここでコマの成りを判定する。*/
	/*相手のコマを自分のコマの番号に直し保存する処理*/
	if(banmen[xmuve][ymuve] >= 15)
	{
		for (loop2 = 0; loop2 <= 39; loop2++)
		{
			if (temoti[loop2] == 0)
			{
				number = loop2;
				temoti[loop2] = banmen[xmuve][ymuve] -14;	/*自分の対応する番号に修正し保存*/
				loop2 = 40;	/*ループから出るために代入*/
			}
		}

		/*成りコマは元のコマに直して保存する*/
		for (loop1 = 17;loop1 <= 19; loop1 = loop1 + 2)
		{
			if(banmen[xmuve][ymuve] == loop1)
			{
				temoti[number]--;
			}
		}
		for (loop1 = 22; loop1 <= 28; loop1 = loop1 + 2)
		{
			if(banmen[xmuve][ymuve] == loop1)
			{
				temoti[number]--;
			}
		}
	}
	/*動く処理*/
	banmen[xmuve][ymuve] = banmen[xhaiti][yhaiti];
	banmen[xhaiti][yhaiti] = 0;
	return 2;
}
/*裏飛車の動き 2*/
int urahisha_2(int banmen[11][11],int temoti[], int xhaiti, int yhaiti, int xmuve, int ymuve)
{
	int loop1;
	int loop2;
	int number;
	int option_nari;

	/*動けないマスが選択されたときは動かない*/
	/*周囲８マスをまずも調べる*/
	if (((xhaiti != xmuve) && (yhaiti != ymuve)) || ((xhaiti == xmuve) && (yhaiti == ymuve)) || ((xmuve != xhaiti - 1) || (xmuve != xhaiti) || (xmuve != xhaiti + 1)) && ((ymuve != yhaiti) || (ymuve != yhaiti + 1) || (ymuve != yhaiti - 1))|| (banmen[xhaiti][yhaiti] == 0) || (banmen[xmuve][ymuve] == -1))
	{
		printf("そこには動けません。\n指し直してください。\n");
		return 1;
	}
	/*動いていなかったらだめ*/
	if ((xmuve == xhaiti) && (ymuve == yhaiti))
	{
		printf("そこには動けません。\n指し直してください。\n");
		return 1;
	}

	/*動くマスに味方のコマがあったら動かない*/
	if (((banmen[xhaiti][yhaiti] >= 15) && (banmen[xmuve][ymuve] >= 15)))
	{
		printf("味方のコマが置いてあります。\n差し直してください。");
		return 1;
	}

	/*縦に動く場合*/
	if (xhaiti == xmuve)
	{
		if (yhaiti > ymuve)
		{
			/*動くマスと今いるマスの間に何もないかの確認の処理*/
			for (loop1 = ymuve + 1;loop1 < yhaiti;loop1++)
			{
				if (banmen[xhaiti][loop1] > 0)
				{
					printf("通り道にコマがあるため動けません。\n差し直してください。\n");
					return 1;		/*何かあったら動けないので1を返す*/
				}
			}
		}
		else
		{
			/*動くマスと今いるマスの間に何もないかの確認の処理*/
			for (loop1 = yhaiti + 1; loop1 < ymuve; loop1++)
			{
				if (banmen[xhaiti][loop1] > 0)
				{
					printf("通り道にコマがあるため動けません。\n差し直してください。\n");
					return 1;		/*何かあったら動けないので1を返す*/
				}
			}
		}
	}

	/*横の動くとき*/
	if (yhaiti == ymuve)
	{
		if (xhaiti > xmuve)
		{
			/*動くマスと今いるマスの間に何もないかの確認の処理*/
			for (loop1 = xmuve + 1; loop1 < xhaiti; loop1++)
			{
				if (banmen[loop1][yhaiti] > 0)
				{
					printf("通り道にコマがあるため動けません。\n差し直してください。\n");
					return 1;		/*何かあったら動けないので1を返す*/
				}
			}
		}
		else
		{
			/*動くマスと今いるマスの間に何もないかの確認の処理*/
			for (loop1 = xhaiti + 1; loop1 < xmuve; loop1++)
			{
				if (banmen[loop1][yhaiti] > 0)
				{
					printf("通り道にコマがあるため動けません。\n差し直してください。\n");
					return 1;		/*何かあったら動けないので1を返す*/
				}
			}
		}
	}

	/*以下の処理をするときは動けることが確定している、ここでコマの成りを判定する。*/
	/*相手のコマを自分のコマの番号に直し保存する処理*/
	if(banmen[xmuve][ymuve] <= 14)
	{
		for (loop2 = 0; loop2 <= 39; loop2++)
		{
			if (temoti[loop2] == 0)
			{
				number = loop2;
				temoti[loop2] = banmen[xmuve][ymuve] +14;	/*自分の対応する番号に修正し保存*/
				loop2 = 40;	/*ループから出るために代入*/
			}
		}

		/*成りコマは元のコマに直して保存する*/
		for (loop1 = 3;loop1 <= 5; loop1 = loop1 + 2)
		{
			if(banmen[xmuve][ymuve] == loop1)
			{
				temoti[number]++;
			}
		}
		for (loop1 = 8; loop1 <= 14; loop1 = loop1 + 2)
		{
			if(banmen[xmuve][ymuve] == loop1)
			{
				temoti[number]++;
			}
		}
	}
	/*動く処理*/
	banmen[xmuve][ymuve] = banmen[xhaiti][yhaiti];
	banmen[xhaiti][yhaiti] = 0;
	return 2;
}

int main (void)
{
    int board[11][11];
	printf("プルリクやってみる");
    return 0;
}