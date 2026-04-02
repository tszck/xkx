// Room: /d/heimuya/chengdedian.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short","成德殿");
	set("long", @LONG
這就是日月神教教主平日發號施令的地方，殿中無窗，殿口點着明
晃晃的蠟燭，大殿彼端高設一座，坐着一個英俊的中年人，自是名震江
湖的東方不敗的姘頭楊蓮亭了！ 
LONG );
	set("valid_startroom", 1);
	set("exits",([
		"north" : __DIR__"houting",
		"westdown":__DIR__"up4",
	]));
	set("objects",([
		CLASS_D("heimuya")+"/first" : 1,
		__DIR__"npc/dizi" : 2,
		__DIR__"npc/yang" : 1,
	]));
	set("coor/x", -3250);
	set("coor/y", 4200);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
	"/clone/board/riyue_b"->foo();
}