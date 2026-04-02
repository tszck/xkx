//Room: /d/dali/jisidawu1.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","祭祀大屋");
	set("long",@LONG
這是烏撒部的祭祀大屋，頗爲寬敞。屋子正中一張竹臺，臺上擺
放着一排竹製牌位，上書烏蠻族祖先之名。牌位後的牆上掛有大幅獸
皮，上繪龍形花紋，似是該族的圖騰。一位老祭司常年守在祭臺前，
負責全族的祭司活動。
LONG);
	set("objects", ([
	   __DIR__"npc/laojisi": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "out"      : __DIR__"wuyiminju3",
	]));
	set("coor/x", -90020);
	set("coor/y", -69990);
	set("coor/z", 10);
	setup();
}

void init()
{
	object me = this_player();
	if(me->query_temp("xuncheng"))
	{
		me->set_temp("dali_xc/jsdw",1);
	}
}