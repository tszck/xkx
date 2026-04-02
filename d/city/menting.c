// Room: /yangzhou/menting.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short", "門庭");
	set("long", @LONG
門庭北向，是一座高大的磨磚門樓，門楣上方嵌有「小玲瓏山館」
四字磚額。門內與穿廊相接，遊廊逶迤北去，廊盡而門。
LONG );
	set("outdoors", "yangzhouw");
	set("no_fight", 1);

	set("exits", ([
		"north" : __DIR__"chuanlang",
		"east"  : __DIR__"caohenanjie",
	]));
	set("objects", ([
		__DIR__"npc/jiading2" : 2,
	]));
	set("coor/x", -11);
	set("coor/y", -50);
	set("coor/z", 0);
	setup();
}
int valid_leave(object me, string dir)
{
	object ob;
	if ( dir == "north" && !me->query_temp("enter_yang") 
		&& objectp( ob = present ( "jia ding", environment( me )  ) )
		&& living(ob) )
	{
		message_vision("家丁對$N說道：未經老爺邀請，你不能進去。\n",me);
		return notify_fail("你被家丁攔住了去路。\n");
	}
	return ::valid_leave(me, dir);
}