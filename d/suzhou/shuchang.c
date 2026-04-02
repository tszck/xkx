// Room: /d/suzhou/shuchang.c
// Date: May 31, 98  Java
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "書場");
	set("long", @LONG
你走進書場，看見裏面熱熱鬧鬧的，場子裏都是聽書的，場子前面
有一位說書先生，他看上去四五十歲，手中拿着一塊響板，正在聚精會
神地說着評書--《楊家將》。你也逐漸被評書的內容所吸引，場中的人
們不時的發出驚歎和喝彩聲，時不時將銅板拋了上去。
LONG );
	set("outdoors", "suzhou");
	set("item_desc", ([
		"door" : "這是一扇通往後堂的小木門。\n"
	]));
	set("exits", ([
		"south" : __DIR__"xidajie2",
		"enter" : __DIR__"houtang",
	]));
	set("objects", ([
		__DIR__"npc/gongzi": 1,
	]));
	set("coor/x", 830);
	set("coor/y", -1000);
	set("coor/z", 0);
	create_door("enter", "小門", "out", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
