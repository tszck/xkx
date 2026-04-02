// Room: /d/baituo/tangwu.c
// Last Modified by winder on May. 15 2001

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "堂屋");
	set("long", @LONG
一間寬敞的堂屋，左右兩排太師椅都是檀香木製成。正中那把尺寸
大一倍的雕花太師椅更是不凡。堂上正中掛有一匾額(bian)。左右偏堂
的房門半掩，看不清裏面。
LONG);
	set("item_desc", ([
		"bian" : HIW"
	    ********************************************
	    ********　　　　　　　　　　　　　　********
	    ********    白    陀    山    莊    ********
	    ********　　　　　　　　　　　　　　********
	    ********************************************\n"NOR,
	]));
	set("exits", ([
		"south" : __DIR__"menlang",
		"west"  : __DIR__"zhailuo",
		"east"  : __DIR__"shuifang",
		"north" : __DIR__"tuitang",
	]));
	set("coor/x", -50010);
	set("coor/y", 20052);
	set("coor/z", 30);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
