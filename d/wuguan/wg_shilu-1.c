// wg_shilu-1.c

inherit ROOM;

void create()
{
	set("short", "石板路");
	set("long", @LONG
你走在一條石板路上，從這裏往南是物品房，你看見有不少人手裏
拿着各樣的工具，從那邊過來，北面是武館大廳。
LONG);
	set("exits", ([
		"south"   : __DIR__"wg_wupinfang",
		"east"    : __DIR__"wg_xuetang",
		"west"    : __DIR__"wg_zhangfang",
		"northup" : __DIR__"wg_dating",
	]));
	set("objects", ([
		__DIR__"npc/wg_xiaojh" : 1,
		__DIR__"npc/wg_xiaoyaodizi" : 1,
	]));
	set("outdoors", "wuguan");
	set("coor/x", 41);
	set("coor/y", -50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

