// Room: /d/nanshaolin/guangchang.c
// Last Modified by winder on May. 29 2001

#include <ansi.h>
inherit ROOM;
void init();
int do_open();
int valid_leave();
string look_gate();

void create()
{
	set("short", "山門廣場");
	set("long", @LONG
這裏是南少林寺山門前的廣場，整個廣場由大塊的青石鋪成，極為
平坦。但因年代久遠，都有些破損。叢叢小草從石板的縫隙中長了出來。
廣場周圍都是密密的馬尾松林，四角上各放了幾塊石碑，字跡都甚為模
糊。正前方黃牆碧瓦，飛檐翹檁，正是南少林山門。
LONG);

	set("exits", ([
		"south" : __DIR__"shifang",
		"north" : __DIR__"shanmen",
	]));
	set("outdoors", "nanshaolin");
	set("no_clean_up", 0);
	set("coor/x", 1820);
	set("coor/y", -6310);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
