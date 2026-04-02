// Last Modified by Sir on 9/17/2001
// wg_dayuan.c

inherit ROOM;

void create()
{
	set("short", "武館大院");
	set("long", @LONG
這是個大院子，南西兩邊都是練武場，不少人在這裏習武強身，這
裏很吵，亂哄哄的，你看見不時有扛着東西的，挑着水的匆匆而過。
LONG);
	set("exits", ([
		"out"  : __DIR__"wg_guanmen",
		"east" : __DIR__"wg_dayuan2",
		"south" : __DIR__"wg_lang2",
		"north" : __DIR__"wg_lang1",
	]));
	set("objects", ([
		__DIR__"npc/wg_songshandizi" : 1,
		__DIR__"npc/wg_shenlongdizi" : 1,
	]));
	set("outdoors", "wuguan");
	set("coor/x", 11);
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}


