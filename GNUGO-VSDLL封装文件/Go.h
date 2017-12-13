
#if defined (EXPORTBUILD)  
# define _DLLExport __declspec (dllexport)  
# else  
# define _DLLExport __declspec (dllimport)  
#endif  

extern "C"{
#include "gnugo.h"
#include "liberty.h"

#include "gg-getopt.h"
#include "gg_utils.h"
#include "winsocket.h"

#include "sgftree.h"
#include "random.h"
}
extern "C" int   _DLLExport Add(int x,int y);

extern "C" void  _DLLExport SDGGoInit(int sdg_boardsize);              // ��ʼ��GNUGo
extern "C" int   _DLLExport SDGBoardStat(int i, int j);                // ��������״̬ 0:���� 1:���� -1:����
extern "C" float _DLLExport SDGGetScore();                             // ��ȡ��ǰ�Ʒ�
extern "C" int   _DLLExport SDGIsAllowedMove(int i, int j, int color); // ���ӺϷ���
extern "C" int   _DLLExport SDGPlayMove(int i, int j, int color);      // ָ����������
extern "C" int   _DLLExport SDGUndoMove(int n);                        // ����n��
extern "C" int   _DLLExport SDGGenComputerMove(int color);             // AI�Զ����ɵ�ǰ��������һά����