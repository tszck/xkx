// /d/meizhuang/lingmu.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "古皇陵");
	set("long", @LONG
你一走到這裏，突然一片明亮，原來這裏竟然是古代蠶叢王的陵墓，
中間停放着一具棺木，棺木的上方懸掛着一顆鵝蛋一般大小的夜明珠，
把這裏照得異常明亮，棺木的正中放着一本書，書看起來很陳舊，似乎
是一位前輩異人留下的。 
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"didao5",
		"out"   : __DIR__"shijie",
	]));
	set("objects", ([ /* sizeof() == 1 */
		BOOK_DIR"qunxing-tu.c" : 1,
	]));

	set("coor/x", 3490);
	set("coor/y", -1460);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
