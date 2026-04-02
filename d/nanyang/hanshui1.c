// Room: /d/nanyang/hanshui1.c
// Last Modified by winder on Nov. 20 2001

inherit RIVER;

void create()
{
	::create();
	set("short", "漢水南岸");
	set("long", @LONG
面前是一條波濤翻滾的大江 (river)。濁流滾滾，萬舟競發。兩岸
渡船來來往往，江邊一長溜擺滿了魚攤，漁家就將船泊在岸邊，幾個破
籮筐支一塊木板，板上擺滿了活蹦亂跳的漢江鯉魚。過去不遠，是有名
的老河口，不少過江客都在這裏等待渡船擺渡。
LONG );
	set("exits", ([
		"south" : __DIR__"yidao2",
	]));
	set("no_clean_up", 0);
	set("outdoors", "nanyang");
	set("coor/x", 10);
	set("coor/y", 320);
	set("coor/z", 0);
	set("to",__DIR__"hanshui2");
	setup();
}


