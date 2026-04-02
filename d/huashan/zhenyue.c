// zhenyue.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;

void create()
{
	set("short", "鎮嶽宮");
	set("long", @LONG
鎮嶽宮倚壁而構，四邊松林蔽日，景色幽美。宮前有玉井(jing)，相
傳井中曾生千葉白蓮。這裏地勢略爲平坦，上、下山的遊客多在此稍作休
息再繼續前行。附近有幾間簡陋的旅社，欲登東峯觀日出者，大都於頭晚
歇息於此。
LONG );
	set("exits", ([ /* sizeof() == 3 */
		"eastup"    : __DIR__"yunu",
		"northdown" : __DIR__"jinsuo",
		"southwest" : __DIR__"lianpath1",
	]));
	set("objects", ([
		__DIR__"npc/gao-genming" : 1,
	]));
	set("item_desc", ([
		"jing" : "井中水色碧透，掬手可飲。\n",
	]));

	set("outdoors", "huashan" );
	set("resource/water", 1);

	set("coor/x", -870);
	set("coor/y", 190);
	set("coor/z", 110);
	setup();
}
 
int valid_leave(object me, string dir)
{
	if (dir != "northdown" )
	{
		if(me->query("family/family_name") !="華山派")
		{
			if(me->query("combat_exp") >= 100)
			{
				if(present("gao genming", environment(me)) && living(present("gao genming", environment(me))))
				{
					return notify_fail("高根明喝道：後面是本派重地，這位" + RANK_D->query_respect(me) + "請止步。\n");
				} else return ::valid_leave(me, dir);
			} else return ::valid_leave(me, dir);
		} else return ::valid_leave(me, dir);
	} else return ::valid_leave(me, dir);
}
