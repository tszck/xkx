//ROOM: /d/yanziwu/changlang.c

inherit ROOM;

void create()
{
	set("short", "長廊");
	set("long",@LONG
只見紅欄碧瓦，一派富貴氣象，不時有幾隻燕子靈巧的從廊間飛過，
長廊的盡頭有一座大花園。長廊上似乎還有一層，你忍不住想爬上去看
看。
LONG );
	set("exits", ([
		"east"  : __DIR__"huizhen",
		"west"  : __DIR__"lixiang",
		"north" : __DIR__"shijian",
		"south" : __DIR__"huayuan",
	]));
	set("no_clean_up", 0);
	set("coor/x", 840);
	set("coor/y", -1520);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
