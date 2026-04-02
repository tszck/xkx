// Room: /d/baituo/tuitang.c
// Last Modified by winder on May. 15 2001
inherit ROOM;

#include <ansi.h>


void create()
{
	set("short", "退堂");
	set("long", @LONG
這間退堂不大，只放有兩個茶几，掛了兩副字畫。西邊的屋子掛着
重簾，看不清裏面有什麼。東邊隔着重簾似乎是個小院子。往北就是一
給大花園了。
LONG);
	set("exits", ([
		"south" : __DIR__"tangwu",
		"north" : __DIR__"huayuan",
		"west"  : __DIR__"danfang",
		"east"  : __DIR__"yuanzi",
	]));
	set("objects", ([
		__DIR__"npc/jiren1" : 2,
	]));
	set("coor/x", -50010);
	set("coor/y", 20055);
	set("coor/z", 30);
	setup(); 
	replace_program(ROOM);
}
