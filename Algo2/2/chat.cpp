#include <iostream>

using namespace std;

const int MAXN = 1024;
int board[MAXN][MAXN]; // 定义棋盘
int tile = 0;          // 记录当前使用的骨牌编号

void ChessBoard(int tr, int tc, int dr, int dc, int size)
{
    if (size == 1) // 如果棋盘大小为1，则直接返回
        return;
    int t = ++tile;   // 获取当前使用的骨牌编号，并将其自增
    int s = size / 2; // 将棋盘分成四个子棋盘，每个子棋盘的大小为原来的一半
    // 判断特殊方格所在区域
    if (dr < tr + s && dc < tc + s)    // 先判断特殊方格是否在左上角子棋盘中
        ChessBoard(tr, tc, dr, dc, s); // 若是，则递归处理左上角子棋盘
    else
    {
        board[tr + s - 1][tc + s - 1] = t;             // 否则，在右下角子棋盘中放置一个骨牌
        ChessBoard(tr, tc, tr + s - 1, tc + s - 1, s); // 递归处理左上角子棋盘
    }
    if (dr < tr + s && dc >= tc + s)       // 判断特殊方格是否在右上角子棋盘中
        ChessBoard(tr, tc + s, dr, dc, s); // 若是，则递归处理右上角子棋盘
    else
    {
        board[tr + s - 1][tc + s] = t;                 // 否则，在左下角子棋盘中放置一个骨牌
        ChessBoard(tr, tc + s, tr + s - 1, tc + s, s); // 递归处理右上角子棋盘
    }
    if (dr >= tr + s && dc < tc + s)       // 判断特殊方格是否在左下角子棋盘中
        ChessBoard(tr + s, tc, dr, dc, s); // 若是，则递归处理左下角子棋盘
    else
    {
        board[tr + s][tc + s - 1] = t;                 // 否则，在右上角子棋盘中放置一个骨牌
        ChessBoard(tr + s, tc, tr + s, tc + s - 1, s); // 递归处理左下角子棋盘
    }
    if (dr >= tr + s && dc >= tc + s)          // 判断特殊方格是否在右下角子棋盘中
        ChessBoard(tr + s, tc + s, dr, dc, s); // 若是，则递归处理右下角子棋盘
    else
    {
        board[tr + s][tc + s] = t;                     // 否则，在左上角子棋盘中放置一个骨牌
        ChessBoard(tr + s, tc + s, tr + s, tc + s, s); // 递归处理右下角子棋盘
    }
}

int main()
{
    int size, dr, dc;
    cout << "请输入棋盘大小size(size=2^k,k=1,2,3···):";
    cin >> size; // 输入棋盘大小
    cout << "单个方格的位置(行dr,列dc):";
    cin >> dr >> dc;                // 输入特殊方格的位置
    ChessBoard(0, 0, dr, dc, size); // 使用分治算法构造棋盘
    cout << "棋盘编号为：\n";
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << board[i][j] << "\t"; // 输出棋盘编号
        }
        cout << endl;
    }
    return 0;
}