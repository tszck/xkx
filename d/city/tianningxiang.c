// Room: /yangzhou/tianningxiang.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","天寧巷");
	set("long",@LONG
這裏是一條僻靜的小巷，行人寥寥無幾，從此向南是綵衣街口，向
北是天寧寺，小巷的西邊掛着一塊烏木匾，上書“天寧書局”四個大字，
不過，由於地方過於偏僻，很少有人來這裏買書。
LONG );
	set("outdoors", "yangzhoue");

	set("exits", ([
		"northwest"  : __DIR__"tianningshuju",
		"northeast"  : __DIR__"yuelaoci",
		"south"      : __DIR__"caiyijiekou",
	]));
	set("no_clean_up", 0);
	set("coor/x", 40);
	set("coor/y", 40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}