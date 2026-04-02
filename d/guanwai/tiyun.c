// /guanwai/tiyun.c

inherit ROOM;

void create()
{
	set("short", "梯雲峯");
	set("long", @LONG
玉柱峯北，有一山峯，峯脊出梯河瀑布，遠望如騰白如雲，縱列如
梯，故名梯雲峯。
LONG );
	set("exits", ([
		"south"      : __DIR__"yuzhu",
	]));
	set("no_clean_up", 0);
	set("outdoors", "changbai");
	set("coor/x", 6170);
	set("coor/y", 5170);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}