// Room: /d/chengdu/beijie1.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "北大街");
	set("long", @LONG
這是一條寬闊的青石街道，向南北兩頭延伸。北邊是北城門通向城
外。南邊顯得很繁華熱鬧。東邊是一座兩層的樓閣，掛着“陳麻婆豆腐”
的招簾，門額上懸掛一方橫匾“麻到爲止”四字擦得閃閃發亮，乃是蘇
大鬍子的手筆。陣陣辣椒香味撲鼻而來，讓你垂涎欲滴。
    西南方有個如畫的小潭。
LONG	);
	set("exits", ([
		"east"      : __DIR__"chenmapo",
		"north"     : __DIR__"beijie",
		"south"     : __DIR__"beijie2",
		"southwest" : __DIR__"huanhuaxi2",
	]));
	set("outdoors", "chengdu");
	set("coor/x", -8050);
	set("coor/y", -2980);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}


