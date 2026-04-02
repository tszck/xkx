// Room: /city/huadian.c

inherit ROOM;

void create()
{
	set("short", "玉器店");
	set("long", @LONG
草河街上常見的店鋪之一。這裏是玉器店，店面不大，裝飾簡樸。
但這裏賣的貨物卻絕不簡單。通常你在這裏能買到你所要的各種檔次的
玉器，所以雖然這裏地方並不顯眼，遠近的客商都願到這裏來辦貨。
    玉器店的老闆正笑臉相迎。
LONG );
	set("objects", ([
		__DIR__"npc/yufan" : 1,
	]));
	set("exits", ([
		"west" : __DIR__"caohecexiang",
	]));
	set("coor/x", -25);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}