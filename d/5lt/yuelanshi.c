// Room: /d/5lt/yuelanshi.c

inherit ROOM;

void create()
{
	set("short", "閱覽室");
	set("long", @LONG
這裏是村支部的閱覽室。自從配置了先進的多媒體設備，這兒就常
常座無虛席。
LONG );
	set("exits", ([
		"south" : __DIR__"chuandashi",
	]));
	set("no_fight", 1);
	set("coor/x", -170);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}