// Room: /yangzhou/caiyixijie.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","綵衣西街");
	set("long",@LONG
一入綵衣街，你才明白揚州爲何被稱爲「商賈如織」。只見綵衣街
兩面臨街開店，而且都是衣帛香粉鋪。店店相連，間有茶坊酒店。街面
狹窄，人流擁擠。各店客商進出頻繁，更有女子滿掛珠翠，進出店鋪，
購置自己喜歡的衣帛飾物。一入夜，各店鋪挑起燈籠，徹夜喧譁，燈火
不絕。見到此景，真是「九里三十步街中，珠翠闐咽，邈如仙境」。
LONG );
	set("outdoors", "yangzhoue");

	set("exits", ([
		"west"  : __DIR__"caiyijiekou",
		"east"  : __DIR__"caiyidongjie",
		"north" : __DIR__"caibopu",
		"south" : __DIR__"toujinpu",
	]));
	set("no_clean_up", 0);
	set("coor/x", 50);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}