// Room: /d/jueqinggu/sanqingxuan.c
// Last Modified by winder on Feb. 17 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "三清軒");
	set("long", @LONG
這裏是絕情谷谷主會客的地方，軒內牆壁上掛了許多書法圖畫，門
窗皆浮雕紋飾，四周是迴廊。
LONG
	);

	set("exits", ([
		"north"    : __DIR__"shufang",
		"eastdown" : __DIR__"songtang",
		"south"    : __DIR__"jiantan",
		"southwest": __DIR__"huilang1",
	]));
	set("objects", ([
		__DIR__"npc/gongsunzhi" : 1,
	]));
	set("coor/x", -540);
	set("coor/y", -360);
	set("coor/z", 20);
	setup();
 
}
int valid_leave(object me, string dir)
{
	if (!me->query("jqg_pass") &&
		present("gongsun zhi", environment(me)) &&
		(dir =="south" || dir =="north" || dir=="southeast"))
		return notify_fail("公孫止怒斥到，你以爲你是小龍女啊，在我絕情谷裏亂跑？！\n");
	return ::valid_leave(me, dir);
}
