// DemoGo.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
using namespace std;

// ���ͺ�GNUGo����ɫö�ٵ�ת�������򴫲ζԽӻ�������
colors getColor(int c){
	return c % 2 == 0 ? WHITE : BLACK;
}

// ��ȡ����ĳ��λ�õ�״̬
int boardstat(int i, int j){
	int stat = -1;
	switch (BOARD(i, j))
	{
	case BLACK:
		stat = 1;
		break;
	case WHITE:
		stat = 0;
		break;
	default:
		break;
	}
	return stat;
}

// ��������״̬
void displayboard(){
	for (int i = 0; i < board_size; i++)
	{ 
		for (int j = 0; j < board_size; j++)
		{
			cout << " " << boardstat(i, j);
		}
		cout << endl;
	}
}

// ���Ӳ���
bool playmove(int i, int j, int c){
	colors mycolor = getColor(c);

	if (is_legal(POS(i, j), mycolor)){
		gnugo_play_move(POS(i, j), mycolor);
		showboard(0);
		//displayboard();
		float res =gnugo_estimate_score(&white_score,&black_score);
		cout << "score" << res << endl;
		return true;
	}
	return false;
}

// �������
void ClearBoard(int boardsize){
	gnugo_clear_board(boardsize);
}

// ����һ������
int UndoMove(){
	return undo_move(1);
}

// ��ʼ��
void GoInit(int boardSize){
	init_gnugo(8, 1);
	board_size = boardSize;
	showboard(0);
}

int _tmain(int argc, _TCHAR* argv[])
{
	GoInit(19);
	
	int i, j, c;
	while (std::cin >> i >> j)
	{
		// ����
		if (i==-1)
		{
			if (UndoMove() == 1)
				showboard(0);
			continue;
		}

		if (playmove(i, j, 1)){
			showboard(0);
		}
		else{
			cout << "����ʧ�ܣ�" << endl;
		}
		
		int resign = 0;
		float value = 0;
		int genm = genmove(WHITE, &value , &resign);
		cout << "gennerate:" << genm << endl;
		cout << "resign:" << resign << "  value:" << value << endl;

		if (playmove(I(genm), J(genm), 0)){
			showboard(0);
		}
		else{
			cout << "AI����ʧ�ܣ�" << endl;
		}
	}

	return 0;
}