// wg_shufang.c

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "書房");
	set("long", @LONG
這是武館館主的書房，房內很靜，幾縷陽光從窗外的綠蔭中直射進
來，屋內靠窗放着一個大書架，顯然都是些主人常看的書。牆上高懸着
幾個大字“少壯不努力，老大徒傷悲”。
LONG);
	set("exits", ([
		"north" : __DIR__"wg_lang5",
	]));
	set("objects", ([
		__DIR__"npc/wg_lingxiaodizi" : 1,					
	]));	
	set("coor/x", 31);
	set("coor/y", -50);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
