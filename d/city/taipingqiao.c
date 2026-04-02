// Room: /yangzhou/taipingqiao.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","太平橋");
	set("long",@LONG
太平橋極為別緻，橋對稱二主拱，主拱間一小圓拱，兩邊各一肩拱，
富於不同一般的韻律。太平橋兩側圍石欄板，間以望柱，中間鑲石額「
太平橋」。太平橋橫臥於官河之上，遠望之如美人的兩彎柳眉；明月當
空時，兩拱之下各一月影，如美人之妙目顧盼流轉，為揚州一奇景。當
此時，你不禁對所謂“天下三分明月夜，無奈二分在揚州”感觸不已。
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"west"  : __DIR__"caohenanjie",
		"east"  : __DIR__"nanmendajie",
	]));
	set("objects", ([
		__DIR__"npc/geji" : 1,
	]));
	set("coor/x", 0);
	set("coor/y", -50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}