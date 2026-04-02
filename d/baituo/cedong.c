// Room: /d/baituo/cedong.c
// Last Modified by Winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short", "側洞");
	set("long", @LONG
這裏是一個小小的側洞，裏面有張梳妝檯，上邊擺放着一些女人的
用品。
LONG	);
	set("exits", ([
		"east" : __DIR__"dongnei",
	]));
	set("objects",([
		__DIR__"npc/jinhua" : 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -49970);
	set("coor/y", 20040);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
