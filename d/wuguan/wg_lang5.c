// wg_lang5.c

inherit ROOM;

void create()
{
	set("short", "長廊");
	set("long", @LONG
這是個長廊，通向館主的臥室，這裏靜悄悄的，沒有什麼人來，
走廊兩邊爬滿了爬山虎，外面烈日，可是你走在走廊裏只覺得一陣
清涼。
LONG);
	set("exits", ([
		"out"   : __DIR__"wg_dating",
		"east"  : __DIR__"wg_woshi",
		"south" : __DIR__"wg_shufang",
	]));
	set("objects", ([
		__DIR__"npc/wg_yahuan" : 1,
	]));
	set("outdoors", "wuguan");
	set("coor/x", 31);
	set("coor/y", -40);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

