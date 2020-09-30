//戻り値 1 配置不可
//戻り値 2 配置可
#include <stdio.h>
int oushou(int board[11][11],int x_choise,int y_choise,int x_put,int y_put)
{
    int i, j, around[3] = {-1, 0, 1};
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
                board[x_put][y_put] = 1;
                return 2;
            }
        }
    }
    printf("そこには,動けません.\n指し直してください.");
    return 1;
}
int gyokushou(int board[11][11],int x_choise,int y_choise,int x_put,int y_put)
{
    int i, j, around[3] = {-1, 0, 1};
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
                board[x_put][y_put] = 15;
                return 2;
            }
        }
    }
    printf("そこには,動けません.\n指し直してください.");
    return 1;
}
int hu_1(int board[11][11],int x_choise,int y_choise,int x_put,int y_put)
{
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
        if(y_put<=3)
        {//裏になるとき
            board[x_put][y_put] = 14;
            return 2;
        }
        else
        {//そのままのとき
            board[x_put][y_put] = 13;
            return 2;
        }
    }
    printf("そこには,動けません.\n指し直してください.");
    return 1;
}
int hu_2(int board[11][11],int x_choise,int y_choise,int x_put,int y_put)
{
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
        if(y_put>=7)
        {//裏になるとき
            board[x_put][y_put] = 28;
            return 2;
        }
        else
        {//そのままのとき
            board[x_put][y_put] = 27;
            return 2;
        }
    }
    printf("そこには,動けません.\n指し直してください.");
    return 1;
}
int main (void)
{
    int board[11][11];
    return 0;
}