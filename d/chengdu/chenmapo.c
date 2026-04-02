// Room: /d/chengdu/chenmapo.c
// Modifyed by Sir on Dec. 4 2001
// Last Modifyed by Winder on Dec. 24 2001

inherit ROOM;

void create()
{
	set("short", "麻婆豆腐店");
	set("long", @LONG
這裏就是聞名天下的陳麻婆豆腐店。店堂裏整齊的擺放着十幾張紅
漆方桌，一般客人就在這裏品嚐陳麻婆豆腐。幾個夥計忙的是暈頭轉向
。櫃枱上擺着兩壇“老媽紅”和一把算盤，後面端坐着的就是陳麻婆。
LONG	);
	set("exits", ([
		"east" : __DIR__"chufang",				
		"west" : __DIR__"beijie1",				
	]));
	set("objects", ([
		__DIR__"npc/mapo" : 1,
	]));
	set("coor/x", -8040);
	set("coor/y", -2980);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

 
