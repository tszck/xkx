// Room: /d/baituo/danfang.c
// Last Modified by winder on May. 15 2001

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "丹房");
	set("long", @LONG
歐陽鋒既爲“西毒”，他在對藥理也當真十分精通。這丹房內上千
種醫藥、毒藥全用白瓷瓶子裝着，貼上標籤，分門別類地放在四周的藥
架上，令人一目瞭然，越也增加了一絲恐懼之心。
LONG);
	set("exits", ([
	      "east" : __DIR__"tuitang",
	]));
	set("objects", ([
		__DIR__"obj/grass" : 1,
	]));
	set("coor/x", -50020);
	set("coor/y", 20055);
	set("coor/z", 30);
	setup(); 
	replace_program(ROOM);
}
