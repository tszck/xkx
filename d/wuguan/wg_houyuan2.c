// wg_houyuan2.c

inherit ROOM;

void create()
{
	set("short", "後院");
	set("long", @LONG
這裏仍然是後院，北面不時傳來馬嘶聲，你看過去，那裏是個馬房，
南面屋子裏也是吵吵的，好象是鋸木頭的聲音。
LONG);
	set("exits", ([
		"north" : __DIR__"wg_mafang",
		"south" : __DIR__"wg_mufang",
		"west"  : __DIR__"wg_houyuan",
		"east"  : __DIR__"wg_houyuan3",
	]));
	set("objects", ([
		__DIR__"npc/wg_xueshandizi" : 1,
		__DIR__"npc/wg_honghuabangzhong" : 1,
	]));
	set("outdoors", "wuguan");
	set("coor/x", 71);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

