// Room: /d/lingxiao/laolang.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short", "監獄走廊");
	set("long", @LONG
這是凌霄城監獄的走廊，兩邊關的都是凌霄城犯了門規的弟子。此
處地下高低不平，兩邊都是巨石築成，一旦被關進來，就別想逃得出去。
牆上點着一支支火把，火光照得四周牆上的影子象要擇人而噬的怪物一
樣，看起來這種地方還是快走比較好。
LONG );
	set("exits", ([
		"up" : __DIR__"jianyuting",
		"west" : __DIR__"jianyusun",
		"east" : __DIR__"jianyuzhu",
		"down" : __DIR__"didi",
	]));
	set("objects", ([ 
		__DIR__"npc/dizi" : 1,
	])); 
	set("coor/x", -30990);
	set("coor/y", -8900);
	set("coor/z", 130);
	setup(); 
	replace_program(ROOM);
}

