//Room: xuanyuegate.c 玄嶽門
//Date: Sep 22 1997

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short","玄嶽門");
	set("long",@LONG
你的面前是一座林木繁茂的高山，幾座山峯在雲霧中隱約可見，一條石
階向山上延伸，走着幾個進香客。一個四柱三間五樓式的石坊跨山而建，正
面鐫有“治世玄嶽”四個大字，原來這就是天下聞名的武當山。武當山一名
太和山，爲七十二福地之一，有二十七峯、三十六巖、二十四澗、五臺、五
井、三潭、三天門、三洞天和一福地，百里內密樹森羅，蔽日參天，景物幽
絕。
LONG);
	set("objects", ([
		CLASS_D("wudang") +"/zhike": 1,
		CLASS_D("wudang") +"/daotong": 2,
	]));
	set("outdoors", "wudang");
	set("exits",([ /* sizeof() == 1 */
		"east"     : __DIR__"slxl3",
		"southup"  : __DIR__"shijie1",
	]));
//	set("no_clean_up", 0);
	set("coor/x", -2050);
	set("coor/y", -800);
	set("coor/z", 20);
	setup();
}

int valid_leave(object me, string dir)
{
	if (me->query_temp("in_guard_wd") &&
		objectp(present("lingxu daozhang", environment(me))))
	return notify_fail("知客道長攔住你說：值守時辰未到，不能擅離職守。\n");

	me->delete_temp("in_guard_wd"); 
	me->delete("guard");
	remove_call_out("clone_meng");

	return ::valid_leave(me, dir);
}
