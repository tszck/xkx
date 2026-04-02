// Room: /yangzhou/shiliji6.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","十里長街");
	set("long",@LONG
這裏就是張佑詩中寫的「十里長街市井連，月明橋上望神仙」的十
裏長街。長街寬達三十丈，青磚鋪地，東邊一道泄水溝。街中心種有槐
樹，分行人以左右而行。西邊是官河，岸邊相間種有綠柳碧桃，倒影水
面，搖曳風中。東邊臨街的屋子掛有招牌，是一家老字號的藥鋪。西邊
是一家雜貨鋪。
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"west"  : __DIR__"zahuopu",
		"east"  : __DIR__"yaopu",
		"south" : __DIR__"shilijie7",
		"north" : __DIR__"shilijie5",
	]));
	set("objects", ([
		"/d/dali/npc/duanyu" : 1,
	]));
	set("coor/x", 10);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}