//RJQYUAN.C

inherit ROOM;

void create()
{
	set("short", "銳金旗大院");
	set("long", @LONG
你走進了銳金旗的大院，卻發現這裏人影稀疏，雖聽見叮叮咚咚的
打鐵聲，卻見不到打鐵鋪，那聲音似乎是從深遠的地下傳來的。向西走，
就要進入門樓了。院子左首可能是練武場，隱約傳來打鬥聲；右首是一
座大廳，象是銳金旗的議會場所。
LONG );
	set("exits", ([
		"west" : __DIR__"rjqmenlou1",
		"north" : __DIR__"rjqdating",
		"south" : __DIR__"rjqlwch",
		"out": __DIR__"rjqmen",
	]));
	set("outdoors", "mingjiao");
	set("no_clean_up", 0);
	set("coor/x", -52020);
	set("coor/y", 860);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}