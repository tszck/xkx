// Room: /d/heimuya/changtan.c
// Last Modified by winder on Apr. 10 2000

inherit ROOM;

void create()
{
	set("short", "長灘");
	set("long", @LONG
這是一片長灘，不時有日月教教衆乘船往來。灘頭插着一面日月教
的旗幟，表明這裏是日月神教的地盤，儘管江面上往來的船隻很多，但
是並沒有船敢在這裏停留。岸邊正停靠着一尾日月教的小船。
LONG );
	set("exits", ([
		"westup" : __DIR__"shandao1",
		"enter"  : __DIR__"duchuan1",
	]));
	set("objects", ([
		CLASS_D("heimuya")+"/huang" : 1,
		__DIR__"npc/heiyiren" : 2,
	]));
	set("outdoors", "heimuya");
	set("coor/x", -3200);
	set("coor/y", 4200);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if( dir == "enter" ) me->set_temp("hmy_ship/ct", 1);
	else me->delete_temp("hmy_ship");
	return ::valid_leave(me, dir);
}

