// Room: /d/nanshaolin/sengshe1.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "東僧舍");
	set("long", @LONG
這裏是僧舍待客的地方，靠牆左右兩側擺着一溜太師椅。牆角一幾，
放着幾個茶壺。有個茶壺壺身上題了“碧螺春”三個篆字，壺嘴熱氣騰
騰，似乎是剛沏的新茶。一位小沙彌在一邊垂手站立。
LONG );
	set("exits", ([
		"west"  : __DIR__"celang2",
		"south" : __DIR__"sengshe3",
		"north" : __DIR__"sengshe2",
	]));
	set("objects", ([
		__DIR__"npc/xiao-ku" : 1,
	]));
	set("coor/x", 1820);
	set("coor/y", -6230);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

