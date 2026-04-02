//Edited by fandog, 01/31/2000

inherit ROOM;
#include <ansi.h>
void create ()
{
	set ("short", "靈堂");
	set ("long", @LONG
這是一個靈堂，屋子裏燭光耀眼。桌子上點燃着兩根素燭，安放着
一塊靈牌(Pai)。桌旁懸掛一匹素幃。
LONG);
	set("item_desc", ([
		"pai" : HIW"愛女凌霜華之靈位\n"NOR,
	]));
	set("exits", ([ 
		"south" : __DIR__"feiyuan",
		"west"  : __DIR__"zoulang",
		"east"  : __DIR__"yongdao",
	]));
  
	set("no_clean_up", 0);
	set("coor/x", -1470);
	set("coor/y", -2029);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
