// Room: /yangzhou/qiqifang.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","江氏漆器工坊");
	set("long",@LONG
這裏是名噪揚州的漆工藝人江千里的作坊。江千里製作的漆器器皿，
異常精緻，形神俱美。揚州人莫不以有一套江千里的漆器器皿為傲，揚
州城裏「杯盤處處江秋水」。作坊內幾個客人正和江千里商量些什麼，
邊上的一個帳房模樣的人執筆記着。對於你的進來，似乎沒人在意。
LONG );
	set("exits", ([
		"south" : __DIR__"dashixijie",
	]));
	set("objects", ([
		__DIR__"npc/jiangqianli" : 1,
	]));
	set("coor/x", 55);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}