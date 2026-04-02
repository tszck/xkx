// Room: /yangzhou/beimendajie.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short", "北門大街");
	set("long", @LONG
北門街寬約二十丈，中間以槐樹隔開，行人分行左右。街邊有排水
溝直接通向官河。街西是大虹橋，街東通向瓊花街。北邊是揚州的北門
「鎮淮門」。街東邊是名揚天下的崇雅書院，隱隱可以聽到朗朗的讀書
聲。
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"west"  : __DIR__"hongqiao",
		"east"  : __DIR__"qionghuajie",
		"south" : __DIR__"shilijie1",
		"north" : __DIR__"beimen",
	]));
	set("objects", ([
		__DIR__"npc/geji" : 1,
	]));
	set("coor/x", 10);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}