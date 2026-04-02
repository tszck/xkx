// Room: /d/5lt/houtai.c

inherit ROOM;

void create()
{
	set("short", "後臺");
	set("long", @LONG
這裏是演播廳的後臺，演員們得了空兒趕着跑來歇口氣。嘉賓室門
口的過道里擠滿了索要簽名的歌迷影迷。
LONG	);
	set("outdoors", "5lt");
	set("exits", ([
		"southwest" : __DIR__"yanboting",
	]));
        set("objects", ([
		__DIR__"npc/niu": 1,
	]));
	set("no_clean_up", 0);
	set("no_fight", 1);
	set("coor/x", -170);
	set("coor/y", 35);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
