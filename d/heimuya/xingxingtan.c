// Room: /d/heimuya/xingxingtan.c
// Last Modified by winder on Apr. 10 2000

inherit ROOM;

void create()
{
	set("short", "猩猩灘");
	set("long", @LONG
只見一片長灘，山石殷紅如血，水流湍急，這便是有名的猩猩灘。
一葉小舟隱藏在蘆葦中，要過對面就要靠這幾艘小船了。
LONG );
	set("outdoors", "heimuya");
	set("objects", ([
//		CLASS_D("heimuya")+"/first" : 1,
	]));
	set("exits", ([
		"eastup" : __DIR__"shidao2",
		"enter"  : __DIR__"duchuan1",
	]));
	set("coor/x", -3060);
	set("coor/y", 4040);
	set("coor/z", -10);
	setup();
}

int valid_leave(object me, string dir)
{
	if( dir != "enter" ) me->set_temp("hmy_ship/xxt", 1);
	else me->delete_temp("hmy_ship");
	return ::valid_leave(me, dir);
}
