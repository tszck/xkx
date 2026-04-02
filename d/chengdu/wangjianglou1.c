// Room: /d/chengdu/wangjianglou1.c
// Last Modifyed by Winder on Jan. 4 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "望江樓");
	set("long",@LONG
這裏就是有名的望江樓了，樓外是成都的府南河。河面不寬，對岸
就是一片竹林，林裏有口井稱做薛濤井。是一帶才女葬身之地。樓上視
野遼闊可以遠眺錦官城。
LONG	);
	set("outdoors", "chengdu");
	set("exits", ([
		"up"    : __DIR__"wangjianglou2",
		"east"  : __DIR__"wanliqiao",
		"north" : __DIR__"funanhe3",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8030);
	set("coor/y", -3030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);       
}


