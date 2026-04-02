// Room: /d/chengdu/xijie2.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "西大街");
	set("long", @LONG
這裏是西大街，熙熙攘攘，熱鬧非凡，兩邊是鱗立櫛比的店鋪，五
顏六色的幌子滿街飄蕩煞是鮮豔。南面有個木匠鋪，聽說那裏的木匠手
藝很是了得。北邊則是個雜貨鋪。
LONG	);
	set("outdoors", "chengdu");
	set("exits", ([
		"east"  : __DIR__"guangchang",
		"west"  : __DIR__"xijie1",
		"south" : __DIR__"mujiangpu",
		"north" : __DIR__"zahuopu",
	]));
	set("objects", ([
		__DIR__"npc/flowergirl" : 1,
		__DIR__"npc/chike" : 1,
	]));

	set("coor/x", -8060);
	set("coor/y", -3000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

