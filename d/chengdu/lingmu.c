// Room: /d/chengdu/lingmu.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "陵墓");
	set("long", @LONG
這裏有一座很大的陵墓，你走到這裏，感覺怪怪的，不知道有什麼
地方不對，也許是這裏的氣氛使人有些壓抑吧，有個掃墓人在那裏不停
地唉聲嘆氣。
LONG	);
	set("exits", ([
		"east" : __DIR__"wuhouci",
	]));
	set("objects",([
		 __DIR__"npc/saomuren" : 1,
	]));
	set("outdoors", "chengdu");
	set("coor/x", -8080);
	set("coor/y", -3020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

