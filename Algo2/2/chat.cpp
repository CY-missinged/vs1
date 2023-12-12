#include <iostream>

using namespace std;

const int MAXN = 1024;
int board[MAXN][MAXN]; // ��������
int tile = 0;          // ��¼��ǰʹ�õĹ��Ʊ��

void ChessBoard(int tr, int tc, int dr, int dc, int size)
{
    if (size == 1) // ������̴�СΪ1����ֱ�ӷ���
        return;
    int t = ++tile;   // ��ȡ��ǰʹ�õĹ��Ʊ�ţ�����������
    int s = size / 2; // �����̷ֳ��ĸ������̣�ÿ�������̵Ĵ�СΪԭ����һ��
    // �ж����ⷽ����������
    if (dr < tr + s && dc < tc + s)    // ���ж����ⷽ���Ƿ������Ͻ���������
        ChessBoard(tr, tc, dr, dc, s); // ���ǣ���ݹ鴦�����Ͻ�������
    else
    {
        board[tr + s - 1][tc + s - 1] = t;             // ���������½��������з���һ������
        ChessBoard(tr, tc, tr + s - 1, tc + s - 1, s); // �ݹ鴦�����Ͻ�������
    }
    if (dr < tr + s && dc >= tc + s)       // �ж����ⷽ���Ƿ������Ͻ���������
        ChessBoard(tr, tc + s, dr, dc, s); // ���ǣ���ݹ鴦�����Ͻ�������
    else
    {
        board[tr + s - 1][tc + s] = t;                 // ���������½��������з���һ������
        ChessBoard(tr, tc + s, tr + s - 1, tc + s, s); // �ݹ鴦�����Ͻ�������
    }
    if (dr >= tr + s && dc < tc + s)       // �ж����ⷽ���Ƿ������½���������
        ChessBoard(tr + s, tc, dr, dc, s); // ���ǣ���ݹ鴦�����½�������
    else
    {
        board[tr + s][tc + s - 1] = t;                 // ���������Ͻ��������з���һ������
        ChessBoard(tr + s, tc, tr + s, tc + s - 1, s); // �ݹ鴦�����½�������
    }
    if (dr >= tr + s && dc >= tc + s)          // �ж����ⷽ���Ƿ������½���������
        ChessBoard(tr + s, tc + s, dr, dc, s); // ���ǣ���ݹ鴦�����½�������
    else
    {
        board[tr + s][tc + s] = t;                     // ���������Ͻ��������з���һ������
        ChessBoard(tr + s, tc + s, tr + s, tc + s, s); // �ݹ鴦�����½�������
    }
}

int main()
{
    int size, dr, dc;
    cout << "���������̴�Сsize(size=2^k,k=1,2,3������):";
    cin >> size; // �������̴�С
    cout << "���������λ��(��dr,��dc):";
    cin >> dr >> dc;                // �������ⷽ���λ��
    ChessBoard(0, 0, dr, dc, size); // ʹ�÷����㷨��������
    cout << "���̱��Ϊ��\n";
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << board[i][j] << "\t"; // ������̱��
        }
        cout << endl;
    }
    return 0;
}