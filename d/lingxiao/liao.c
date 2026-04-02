// Room: /d/lingxiao/liao.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
void create()
{
	set("short","居室");
	set("long",@LONG 
這是廖自勵的房間。四位長老中，以他最為生性多智，有人説若不
是當年先師仙去時，他不在凌霄城內，而等他回來之時，大局已定，那
這掌門之位必為他囊中之物。這房間內擺滿了書，從《孫子兵法》到《
史記》，盡皆是權謀爭鬥之書。
LONG);
	set("exits",([ /* sizeof() == 1 */
		"south" : __DIR__"zoulang3", 
	]));
	set("objects", ([  
		__DIR__"npc/liao" : 1,
	]));
	set("coor/x", -31010);
	set("coor/y", -8830);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}

