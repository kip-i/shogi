#include <stdio.h>
int up_kin(int board[11][11],int temoti[],int x_choise,int y_choise,int x_put,int y_put)              //1p金
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

int up_kyousya(int board[11][11],int temoti[],int x_choise,int y_choise,int x_put,int y_put)      //1p香車
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

int down_kyousya(int board[11][11],int temoti[],int x_choise,int y_choise,int x_put,int y_put)    //2p香車
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