// /d/huashan/xiaofang.c 小木屋
// Last Modified by winder on Jul. 12 2002

inherit ROOM;

void create()
{
	set("short", "小木屋");
	set("long", @LONG
一所擺設簡單的小木屋。室內有一個香爐，牆上掛着一炳長劍。當
中坐着一位老者，穿著雖然樸素，卻令人不由得心生敬仰。
LONG
	);
	set("exits", ([
		"out" : __DIR__"luoyan",
	]));
	set("objects", ([
		CLASS_D("huashan") + "/feng" : 1,
	]));
	set("coor/x", -860);
	set("coor/y", 120);
	set("coor/z", 150);
	setup();
	replace_program(ROOM);
}
