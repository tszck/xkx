// Room: /beijing/dongcha2.c

inherit ROOM;
void create()
{
	set("short", "東長安街");
	set("long", @LONG
你走在東長安街上，踩着堅實的青石板地面。東邊是東城門，可以
聽到守城官兵的吆喝聲。南邊是打鐵鋪，叮叮噹噹的聲音老遠就能聽到。
由於王府井大街就在北邊，許多人都往北去，那裏人聲鼎沸，似乎十分
熱鬧。西邊比這裏更熱鬧，從那兒往北可以去王府井。
LONG );
	set("outdoors", "beijing");
	set("exits", ([
		"east"  : __DIR__"dongmen",
		"west"  : __DIR__"dongcha1",
		"south" : __DIR__"datiepu",
		"north" : __DIR__"wangfu1",
	]));
	set("objects", ([
		"/d/city/npc/liumangtou" : 1,
		"/d/city/npc/liumang" : 2,
	]));
	set("coor/x", -180);
	set("coor/y", 4040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
