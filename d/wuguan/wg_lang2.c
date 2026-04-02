// wg_lang2.c

inherit ROOM;

void create()
{
	set("short", "長廊");
	set("long", @LONG
這是個長廊，通向東練武場，人來人往的，很是熱鬧。
LONG);
	set("exits", ([
		"south" : __DIR__"wg_wuchang2",
		"north" : __DIR__"wg_dayuan",
	]));
	set("objects", ([
		__DIR__"npc/wg_xiaohs" : 1,
	]));
	set("outdoors", "wuguan");
	set("coor/x", 11);
	set("coor/y", -50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

