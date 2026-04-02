// buwei1.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;

void create()
{
	set("short", "有所不爲軒");
	set("long", @LONG
這是華山掌門嶽不羣的居所「有所不爲軒」，此處是前廳，廳上掛
着「正氣堂」三字匾額。廳中很寬敞，卻沒什麼擺設，靠牆放着兩把交
椅，這裏是嶽不羣議事、授徒的地方，後面是寢室。
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"buwei2",
		"south" : __DIR__"qunxianguan",
		"west"  : __DIR__"garden",
		"east"  : __DIR__"buwei3",
	]));
	set("objects", ([
		 __DIR__"npc/dayou": 1,
		 __DIR__"npc/little_monkey": 1,
	]) );

	set("coor/x", -860);
	set("coor/y", 220);
	set("coor/z", 120);
	setup();
}
int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam=(mapping)me->query("family");
	if ((!myfam ||myfam["family_name"] != "華山派") && dir == "north" &&
		objectp(present("lu dayou", environment(me))))
		return notify_fail("陸大有喝道：後面是家師寢室，這位" + RANK_D->query_respect(me) + "請止步。\n");
	return ::valid_leave(me, dir);
}
 
