// /kaifeng/qianyuan.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "前院");
	set("long", @LONG
一帶粉成黃色的圍牆圈起這個院子，一條青石道通向北面的天王殿，
南面就是相國寺的大門，東邊一座高樓是鼓樓，西面是鐘樓。
LONG);
	set("no_clean_up", 0);
	set("exits", ([
		"south" : __DIR__"xiangguosi",
		"north" : __DIR__"tianwang",
		"east" : __DIR__"gulou",
		"west" : __DIR__"zhonglou",
	]));
	set("outdoors", "xiangguosi");

	setup();
	replace_program(ROOM);
}
