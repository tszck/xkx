// Last Modified by Sir on 9/17/2001
// wg_guanmen.c

inherit ROOM;

void create()
{
	set("short", "武館大門");
	set("long", @LONG
這裏是一個大宅子，門口高懸一個大匾“揚州武館”，立了兩個石
獅，你從大門口瞧進去，好象裏面人來人往，都很繁忙的樣子，門口站
着兩個門衞，神情威嚴。
LONG);
	set("exits", ([
		"enter" : __DIR__"wg_dayuan",
		"west" : "/d/city/shilijie7",
	]));	
	set("objects", ([
		__DIR__"npc/wg_menwei" : 2,
	]));
	set("coor/x", 11);
	set("outdoors", "wuguan");
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir != "west" )
	{
		if(me->query("combat_exp") > 50000)
		{
			if(present("men wei", environment(me)) &&
				living(present("men wei", environment(me))))
			{
				return notify_fail("武館門衞喝道：本館只收留江湖新手，這位" + RANK_D->query_respect(me) + "請止步。\n");
			}
			else return ::valid_leave(me, dir);
		}
		else return ::valid_leave(me, dir);		
	}
	else return ::valid_leave(me, dir);
}

