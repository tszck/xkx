// Room: /d/nanshaolin/celang2
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "東禪房側廊");
	set("long", @LONG
這裏是禪房側廊。彩梁畫棟，連頂棚也用彩漆繪滿了各種飛天的圖
形，出自名家手筆，端的壯麗不凡。北望是一片槐樹林，鳥語花香隱隱
傳來令人心曠神怡。東面是僧人們休息用的僧舍。   
LONG );
	set("exits", ([
		"northeast" : __DIR__"songshu3",
		"south"     : __DIR__"stoneroad3",
		"east"      : __DIR__"sengshe1",   
	]));
	set("no_clean_up", 0);
	set("outdoors", "nanshaolin");
	set("coor/x", 1810);
	set("coor/y", -6230);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

