// wg_lang4.c

inherit ROOM;

void create()
{
	set("short", "長廊");
	set("long", @LONG
這是個長廊，東面是武館內的物品房，要在武館做雜事的人都得去
物品房領工具，西邊是南練武場。
LONG);
	set("exits", ([
		"east" : __DIR__"wg_wupinfang",
		"west" : __DIR__"wg_wuchang4",
	]));
	set("objects", ([
		__DIR__"npc/wg_thddizi" : 1,
	]));
	set("outdoors", "wuguan");
	set("coor/x", 31);
	set("coor/y", -60);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

