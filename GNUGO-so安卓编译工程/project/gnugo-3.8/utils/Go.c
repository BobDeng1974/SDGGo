#include "gnugo.h"
#include "board.h"
#include "liberty.h"

#include "gg-getopt.h"
#include "gg_utils.h"
#include "winsocket.h"

#include "sgftree.h"
#include "random.h"

const int sdg_memory = 8; // gnugoռ���ڴ�����
int resign = 0;
float value = 0;

// 0:���� 1������
int getColor(int c){
	return c % 2 == 0 ? WHITE : BLACK;
}

// ��ʼ��gnugo��sdg_boardsizeΪ���̹�ģ�����׼�ģ�19��19x19��
void SDGGoInit(int sdg_boardsize)
{
	init_gnugo(8, 1);
	board_size = sdg_boardsize;
}

//0:���� 1 : ���� - 1 : ����
int SDGBoardStat(int i, int j){
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
		stat = -1;
		break;
	}
	return stat;
}

// ��ȡ��ǰ���̵Ĵ������������������ȣ�������������
float SDGGetScore(){
	return gnugo_estimate_score(&white_score,&black_score);
}

// ���ӺϷ���
int SDGIsAllowedMove(int i, int j, int color){
	int mycolor = getColor(color);
	if (is_allowed_move(POS(i, j), mycolor)){
		return 1;
	}
	else
	{
		return 0;
	}
}
// ��ָ��λ������ָ����ɫ�����ӣ���Ҫע��i,j�����ת����gnugo������ԭ�������Ͻǣ�i���������£�j���ң�
int SDGPlayMove(int i, int j, int color){
	int mycolor = getColor(color);
	gnugo_play_move(POS(i, j), mycolor);
	return 1;
}

// ����n��
int SDGUndoMove(int n){
	return undo_move(n);
}

// GNUGo AI����ǰ���̣���gnugo���������ɫΪcolor���������ŵ�����λ�ã�����AI����
int SDGGenComputerMove(int color) {
	return genmove(getColor(color), &value, &resign);
}

float SDGGetWhiteScore(){
	return white_score;
}

int SDGGetBoardSize(){
	return board_size;
}

int SDGGetLevel(){
	return get_level();
}
void SDGSetLevel(int new_level){
	set_level(new_level);
}
void SDGSetMaxLevel(new_max){
	set_max_level(new_max);
}
void SDGSetMinLevel(new_min){
	set_min_level(new_min);
}