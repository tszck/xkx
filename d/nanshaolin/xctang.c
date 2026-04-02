// Room: /d/nanshaolin/xctang.c
// Last Modified by winder on May. 29 2001

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{ 
	set("short",HIR"心禪堂"NOR);
	set("long", @LONG
一座寬敞的禪室，並非用土木建成，而是依山而建，四壁如仞，都
是石壁。如此山間石室，若非渾然天成，定是有前輩高僧，以禪心智慧，
絕大佛力開山而致了。室內燭火通明，終年不息，正中供奉着我佛的法
像，與大殿不同的是做千手如來收萬寶勢。職事僧在殿內四處巡視，以
備所需。一位老僧瞑目跌坐，內視參禪。
LONG );
	set("exits", ([
		"west"  : __DIR__"xclang",
		"south" : __DIR__"xcping",
		"north" : __DIR__"duanya",
	]));
        set("objects",([
		CLASS_D("nanshaolin")+"/dabing" : 1,
        ]));
        set("coor/x", 1820);
	set("coor/y", -6090);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
