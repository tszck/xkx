// square.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;

void create()
{
	set("short", "練武場");
	set("long", @LONG
這裏是華山派的練武場，場上立着幾個木人，東邊是兵器庫，西邊
是個小店。通常有許多華山派弟子在此習武練劍。北邊的房屋門上掛着
一塊匾，上書「羣仙觀」，西北方似乎有條小道通往山上。
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"west"      : __DIR__"shop",
		"east"      : __DIR__"bingqifang",
		"south"     : __DIR__"yunu",
		"north"     : __DIR__"qunxianguan",
		"northwest" : __DIR__"chaopath1",
	]));
	set("objects", ([
		"/d/shaolin/npc/mu-ren" : 5,
	]));
	set("outdoors", "huashan" );

	set("coor/x", -860);
	set("coor/y", 200);
	set("coor/z", 120);
	setup();
}
 
int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam=(mapping)me->query("family");
	if ((!myfam ||myfam["family_name"] != "華山派") && (dir == "east"))
		return notify_fail("那邊是華山派的兵器庫，這位" + RANK_D->query_respect(me) + "請止步。\n");
	return ::valid_leave(me, dir);
}
 
