// Room: /d/lingxiao/liang.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
void create()
{
	set("short","居室");
	set("long",@LONG
這是梁自進的房間，他生性單純，與廖自勵正好相反。他從小就在
凌霄城中練功習武，連大雪山也未下過一步，所以他的武功在五代弟子
中，是僅次於白自在的。他的房間樸素自然，僅有一牀一桌。除此之外，
別無他物。 
LONG);
	set("exits",([ /* sizeof() == 1 */
		"north" : __DIR__"zoulang3", 
	]));
	set("objects", ([
		__DIR__"npc/liang" : 1,
	]));
	set("coor/x", -31010);
	set("coor/y", -8850);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}

