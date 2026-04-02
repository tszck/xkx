// Room: /d/chengdu/eastroad2.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "民居");
	set("long", @LONG
這裏是民居，門口掛着一串串風乾的紅辣椒和花椒，窗戶糊着幾層
花花紙。有幾個居民在燒火做飯。
LONG	);
	set("exits", ([
		"west" : __DIR__"nanjie1",
	]));
	set("objects", ([
		__DIR__"npc/poorman" : 1,
	]));
	set("coor/x", -8040);
	set("coor/y", -3010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

