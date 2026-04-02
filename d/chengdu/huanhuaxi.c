// Room: huanhuaxi.c
// Date: Feb.14 1998 by Java

inherit ROOM;

void create()
{
	set("short", "浣花溪");
	set("long", @LONG
你走在浣花溪岸的小路上，浣花溪水晶瑩剔透，岸草如茵，遠遠
就能聞到水氣的清香。許多睡蓮散佈在溪岸附近，水面飄著數不盡的
浮萍，浮萍下有不少豔紅錦鯉穿梭來去。溪岸小路隨溪流曲折盤繞，
芳草沒足，花飄似海，使人不飲自醉。古人所謂 "如行春郊" ，誠不
我欺。
LONG );
	set("outdoors", "chengdu");
	set("exits", ([
		"south" : __DIR__"huanhuaxi1",		
	]));
	set("no_clean_up", 0);
	set("coor/x", -8050);
	set("coor/y", -2950);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
