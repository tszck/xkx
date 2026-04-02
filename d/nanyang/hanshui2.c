// Room: /d/nanyang/hanshui2.c
// Last Modified by winder on Nov. 20 2001

inherit RIVER;

void create()
{
	::create();
	set("short", "漢水北岸");
	set("long", @LONG
漢水北岸也是相當熱鬧，自北岸渡口往北，一條筆直的官道直通南
陽。此地民風淳樸，路旁夾柳成陰，酒廝林立，且都有一面大大的「酒
」旗迎風飄揚，蔚為壯觀。也有不少小販沿路叫買，語多難辨，卻也令
人盛情難卻。
LONG );

	set("exits", ([
		"north" : __DIR__"nanmen",
	]));
	set("outdoors", "nanyang");
	set("no_clean_up", 0);
	set("coor/x", 10);
	set("coor/y", 400);
	set("coor/z", 0);
	set("to",__DIR__"hanshui1");
	setup();
}
