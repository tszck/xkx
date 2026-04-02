// Room: /d/shaolin/gulou1.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "鼓樓一層");
	set("long", @LONG
這裏是塔樓的底層，一縷縷陽光從牆上的花磚縫隙裏透射
進來，在青磚地上投下別緻的光影，如同一格格棋盤相似。往
上看，長長的木樓梯盤繞而上，似乎永無盡頭。牆角，梯級都
相當潔淨，看來經常有僧人打掃。
LONG );
	set("exits", ([
		"up" : __DIR__"gulou2",
		"out" : __DIR__"gulou",
	]));
	set("objects",([
		__DIR__"npc/saodi-seng" : 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -20);
	set("coor/y", 830);
	set("coor/z", 110);
	setup();
	replace_program(ROOM);
}

