// Last Modified by Sir on 9/17/2001
// wg_lang1.c

inherit ROOM;

void create()
{
	set("short", "長廊");
	set("long", @LONG
這是個長廊，通向北練武場，人們急衝衝的走過，不時有人被擡出
來，看樣子是練功脫力昏倒的。
LONG);
	set("exits", ([
		"north" : __DIR__"wg_wuchang1",
		"south" : __DIR__"wg_dayuan",
	]));
	set("outdoors", "wuguan");
	set("objects", ([
		__DIR__"npc/wg_mrdizi" : 1,
	]));
	set("coor/x", 11);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

