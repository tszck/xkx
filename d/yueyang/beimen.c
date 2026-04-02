// Room: /d/yueyang/beimen.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "嶽陽北門");
	set("long", @LONG
這裏是嶽陽城的北門。青石築成兩層樓臺堅固異常，巍峨寬闊的拱
形城門上方，鏤着「嶽陽」兩個紅漆大字。北面是一條黃土路，直通江
陵。
LONG );
	set("outdoors", "yueyang");
	set("no_clean_up", 0);
	set("exits", ([
		"south"     : __DIR__"beijie",
		"northwest" : "/d/jiangling/tulu2",
	]));
	set("objects", ([
		CLASS_D("gaibang")+"/bangzhong" : 1,
	]));
	set("coor/x", -1410);
	set("coor/y", -2250);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
