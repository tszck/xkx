// Room: /d/nanshaolin/sengshe4.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "西僧舍");
	set("long", @LONG
這裏是僧舍中待客的地方，靠牆左右兩側擺着一溜太師椅。牆角一
幾，放着幾個茶壺。有個茶壺壺身上題了“碧螺春”三個篆字，壺嘴熱
氣騰騰，似乎是剛沏的新茶。
LONG );
	set("exits", ([
		"east"  : __DIR__"celang1",
		"south" : __DIR__"sengshe6",
		"north" : __DIR__"sengshe5",
	]));
	set("resource/water",1);
	set("objects",([
		__DIR__"npc/xiao-tong" : 1,
	]));
	set("coor/x", 1800);
	set("coor/y", -6230);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

