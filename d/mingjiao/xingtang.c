// Room: /d/mingjiao/xingtang.c

#include <ansi.h>
#include <login.h>

inherit ROOM;

void create()
{
	set("short", "刑堂");
	set("long", @LONG
整個刑堂門戶緊閉，密不透風。即便是在白晝，也猶如黑夜一般，
每隔幾步的牆上，點燃着幾枝牛油巨燭。中間是一個大火盆，烈焰騰騰。
下方擺着一排排烙鐵、水牛皮鞭、穿孔竹板及狼牙棒等刑具。四周站滿
了手持兵刃的執法教衆。他們正用冷酷的眼神打量着你，令你不禁渾身
哆嗦起來。
    冷謙執掌明教刑堂。
LONG );
	set("no_fight", "1");
	set("exits", ([
		"west" : __DIR__"square",
	]));
	set("objects",([
		__DIR__"npc/lengqian" : 1
	]));
	set("no_clean_up", 0);
	set("coor/x", -52020);
	set("coor/y", 1050);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}