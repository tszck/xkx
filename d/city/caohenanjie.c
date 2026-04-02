// Room: /yangzhou/caohenanjie.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","草河南街");
	set("long",@LONG
這裏街道比草河東岸的長街窄的多，也乾淨平整的多，行人稀少，
河岸邊上的楊柳、碧桃倒影河中，搖曳多姿，整條街顯的極為幽靜。街
邊少有店鋪酒樓，大多門戶緊閉，兩邊伺立着一對石獅，看來這一帶住
的大多是官宦縉紳人家。
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"west"      : __DIR__"menting",
		"east"      : __DIR__"taipingqiao",
		"south"     : __DIR__"heyuan",
		"north"     : __DIR__"caohexiaojie",
		"northwest" : __DIR__"chanzhimenqian",
	]));
	set("no_clean_up", 0);
	set("coor/x", -10);
	set("coor/y", -50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}