// Room: /d/taohua/mudao.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
    set("short", "墓道");
    set("long",@LONG
這是通往墓室的通道。通道十分寬敞，頂部懸掛着一顆大大的夜明
珠，照得整個墓道如同白晝。墓道盡頭便是墓室。
LONG);
	set("exits", ([
		"up"   : __DIR__"tomb",
		"down" : __DIR__"mushi",
	]));
	set("no_clean_up", 0);
	set("coor/x", 9010);
	set("coor/y", -3100);
	set("coor/z", -10);
	setup();
	replace_program(ROOM);
}
