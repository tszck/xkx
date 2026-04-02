//Room: /d/dali/taiheju2.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","太和居二樓");
	set("long",@LONG
這裏是太和居的二樓，樓梯邊上坐了些手持雲板，瑤琴的歌
女。富商土豪在這裏邊喫喝作樂，也有文人墨客在此飲酒清談，
從南面窗口望出，可以看到城外五華樓前的一波碧水。
LONG);
	set("objects", ([
	   __DIR__"npc/genu": 2,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "down"  : __DIR__"taiheju",
	]));
	set("coor/x", -39990);
	set("coor/y", -71020);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}