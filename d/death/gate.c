// gate.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", HIW "鬼門關" NOR);
	set("long", HIW
"這裏就是著名的陰間入口「鬼門關」，在你面前矗立著一座高大的\n"
"黑色城樓，許多亡魂正哭哭啼啼地列隊前進，因爲一進鬼門關就無法再\n"
"回陽間了。\n"NOR);
        set("no_fight", 1);
        set("exits", ([
		"north" : __DIR__"difu1",
		"south" : __DIR__"yellow3",
	]) );
	set("objects", ([
		__DIR__"npc/wgargoyle" : 1,
	]) );
	setup();
}
void init()
{
	object me;
	me=this_player();
	if (!wizardp(me)) me->save();
	return;
}
 
