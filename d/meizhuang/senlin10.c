// /d/meizhuang/senlin2.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "百木園");
	set("long", @LONG
這裏是梅莊的百木園，你一走到這裏，就象走到了一個連綿無盡的
小森林一樣，這裏無數的松樹，柏樹，白楊，還有很多叫不出來名字的
異種苗木，你走在其中，只想把這片樹林盡情的欣賞一遍，永不出去才
好。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		"west"  : __DIR__"senlin3",
		"east"  : __DIR__"senlin6",
		"south" : __DIR__"senlin9",
		"north" : __DIR__"senlin7",
	]));
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/jiading" : 1,
	]));
	set("outdoors", "meizhuang");

	set("coor/x", 3500);
	set("coor/y", -1430);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
