// Room: /d/lingxiao/bridge.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
void create()
{
	set("short","小橋");
	set("long",@LONG 
這是一座江南園林似的小橋，橋下蓮葉田田，清波盪漾，水滑欄碧，
池魚自得。城外雖有雪花飛舞之姿，朔風呼號之勢，此處卻得地氣溫暖
之潤，得天獨厚，有如江南之景，現於雪域大地。
LONG);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
		"south"  : __DIR__"houyuan2",  
		"north"  : __DIR__"book", 
	]));
	set("no_clean_up", 0);
	set("coor/x", -31000);
	set("coor/y", -8840);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);

}

