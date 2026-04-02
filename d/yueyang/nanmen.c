// Room: /d/yueyang/nanmen.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "嶽陽南門");
	set("long", @LONG
這裏是嶽陽城的南門。青石築成兩層樓臺堅固異常，巍峨寬闊的拱
形城門上方，鏤着「嶽陽」兩個紅漆大字。南面是一條林蔭大道，通向
衡陽。
LONG );
	set("outdoors", "yueyang");
	set("no_clean_up", 0);
	set("objects", ([
		CLASS_D("gaibang")+"/bangzhong" : 3,
		CLASS_D("gaibang")+"/li-chunlai" : 1,
	]));
	set("exits", ([
		"north"     : __DIR__"nanjie",
		"southeast" : "/d/henshan/hsroad8",
	]));
	set("coor/x", -1410);
	set("coor/y", -2290);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
