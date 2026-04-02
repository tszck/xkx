//TOJMQ1.C

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
這裏是通往巨木旗的大道。道路開闊，大概可容十人並肩而行。現
在巨木旗是明教五旗中人數最多，機關構築最雜的。除了守護明教外圍，
還負責明教中所有房屋和棧橋的建造。
LONG );
	set("exits", ([
		"northwest" : __DIR__"tojmq2",
		"southeast" : __DIR__"lhqpaifang",
	]));
	set("no_clean_up", 0);
	set("outdoors", "mingjiao");
	set("coor/x", -52040);
	set("coor/y", 840);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}