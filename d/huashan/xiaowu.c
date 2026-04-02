// Room: /d/huashan/xiaowu.c
// Last Modified by winder on Aug. 1 2002

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "林間小屋");
	set("long", @LONG
這裏就是華山劍宗的的根本之地。二十五年來，劍宗弟子臥薪嚐膽，
只是為了奪回華山門派掌門，為此，付出了極大犧牲。
    屋裏陳設極為簡陋。這麼多年來一直沒有長久隱匿的念頭使得劍宗
弟子能忍辱負重，只待重開生天。
LONG );
	set("exits", ([ /* sizeof() == 4 */
		"west": __DIR__"pingdi",
	]));
	set("objects", ([
		CLASS_D("huashan") + "/feng-buping": 1,
	]));
	set("valid_startroom","1");

	set("coor/x", -920);
	set("coor/y", 170);
	set("coor/z", 50);
	setup();
	"/clone/board/jianzong_b"->foo();
	replace_program(ROOM);
}
