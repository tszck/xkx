// Room: /d/henshan/zhurongdian.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
	set("short", "祝融殿");
	set("long", @LONG
祝融殿，又名老聖殿，祠火神祝融。花崗石砌牆，鐵瓦覆頂，殿宇
凌空傲雪，巍然屹立在衡山絕頂。殿門石楹上刻有:  "寅賓日出，峻極
於天" ，殿上有"聖德重華"的楣額。現在這裏是衡山派掌門行在。
LONG);
	set("exits", ([ /* sizeof() == 4 */
	   "southdown"  : __DIR__"wangritai",
	   "northdown"  : __DIR__"wangyuetai",
	   "westup"     : __DIR__"zhurongfeng",
	]));
	set("objects", ([
		CLASS_D("henshan")+"/moda":1,
		CLASS_D("henshan")+"/first":1,
	]));
	set("valid_startroom", 1);
	set("coor/x", -310);
	set("coor/y", -990);
	set("coor/z", 50);
	setup();
	"/clone/board/henshan_b"->foo();
	replace_program(ROOM);
}

