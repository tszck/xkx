// Room: /yangzhou/shiliji1.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","十里長街");
	set("long",@LONG
走在十里長街，見到街邊酒樓茶肆，重樓高閣，互相臨映，每當入
夜，各酒館茶樓都挑出燈籠，行人遊客緩緩而行，出入酒樓，更有女子
盛妝，進出茶肆，看到此情此景，不禁想起王建的詩句：「夜市千燈照
碧雲，高樓紅袖客紛紛」，見到如此繁華的揚州，不知盛唐的揚州更是
何種盛況。
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"west"  : __DIR__"xiaobaozhai",
		"east"  : __DIR__"chaguan",
		"south" : __DIR__"shilijie2",
		"north" : __DIR__"beimendajie",
	]));
	set("objects", ([
		CLASS_D("quanzhen") + "/youfang" : 1,
	]));
	set("coor/x", 10);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
