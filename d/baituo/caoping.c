// Room: /d/baituo/caoping.c
// Last Modified by winder on May. 15 2001

inherit ROOM;
void create()
{
	set("short","草坪");
	set("long", @LONG
這裏是一塊芳草坪，綠草茵茵，蝴蝶漫舞，讓人感到愜意。不過偶
爾也會碰到菜花蛇。
LONG	);
	set("exits", ([
		"west" : __DIR__"shijie",
	]));
	set("objects" , ([
		__DIR__"npc/caihuashe" : random(2),
	]));
	set("outdoors", "baituo");
//	set("no_clean_up", 0);
	set("coor/x", -50000);
	set("coor/y", 20000);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
