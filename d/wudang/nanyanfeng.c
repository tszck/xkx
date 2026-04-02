//Room: nanyanfeng.c 南巖峯
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","南巖峯");
      set("long",@LONG
這裏是武當三十六巖之最，松樹翳天，木石爭奇，峭壁萬仞。在懸
崖之半築有一宮宇，下臨深淵，工程浩大。宮前有一石柱，自峭壁上橫
出。
LONG);
      set("objects", ([
	   CLASS_D("wudang") +"/mo": 1,
      ]));

      set("exits",([ /* sizeof() == 1 */
	  "eastdown" : __DIR__"langmeiyuan",
	  "southdown": __DIR__"shizhu",
	  "west"     : __DIR__"sheshenya",
      ]));
      set("outdoors", "wudang");
//      set("no_clean_up", 0);
	set("coor/x", -2040);
	set("coor/y", -940);
	set("coor/z", 110);
	setup();
}

int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ((!myfam || myfam["family_name"] != "武當派") &&
		dir == "southdown" &&
		objectp(present("mo shenggu", environment(me))))
		return notify_fail("莫聲谷攔住你說：此處乃本派禁地，請止步。\n");

	return ::valid_leave(me, dir);
}
