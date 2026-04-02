//room: xianchou.c
inherit ROOM;

void create()
{
	set("short","仙愁門");
	set("long",@LONG
這裏就快到縹緲峯絕頂了，越往上走，山勢越高，繚繞在你身邊的
白霧愈來愈濃，往南則是下山的路。沿着山道沒走幾步，在你眼前出現
一個石坊，上書『仙愁門』三個大字，蓋因上山之艱辛吧。
LONG );
	set("outdoors", "lingjiu");
	set("exits",([
		"eastup" : __DIR__"dadao1",
		"southdown" : __DIR__"jian",
	]));
	set("objects",([
		CLASS_D("lingjiu")+"/first" :1,
	]));
	set("coor/x", -51010);
	set("coor/y", 30100);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}