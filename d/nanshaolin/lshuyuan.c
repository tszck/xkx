// Room: /d/nanshaolin/lshuyuan.c
// Last Modified by winder on May. 29 2001

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", HIM"龍樹院"NOR);
	set("long", @LONG
這是一處偏僻的小院，院中栽着兩株高大的槐樹，顯得極是寧靜幽
深。這裏是少林武僧們領取武器和防具之地，彙集了天下各派慣用的各
類兵刃。少林武技天下馳名，為防止練功受傷，這裏也一併供給各類防
具。院門口站着兩名僧兵，手持戒刀，嚴密的守護着這裏。
LONG );
	set("exits", ([
		"east"  : __DIR__ "huaishu5",
		"north" : __DIR__ "wuqiku",
		"south" : __DIR__ "fangjuku",
	]));
	set("outdoors","nanshaolin");
	set("objects",([
		__DIR__"npc/seng-bing3" : 2,
	]));
	set("coor/x", 1790);
	set("coor/y", -6200);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}



