// Room: /d/chengdu/chunxilu1.c
// Last Modifyed by Winder on Jan. 4 2002

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short",HIY "春熙路" NOR);
	set("long", 
"這裏便是成都府著名的商業中心，街上行人來來往往，兩旁店鋪林\n"
"立，熱鬧非凡，東面有個大酒樓，金色的錦旗迎風飄揚，只見上書四個\n"
"大字格外醒目"+BLINK HIR"“銀杏酒樓”"NOR"。西面看起來是個茶館，一個個衣着光鮮的\n人從那裏進進出出。\n"
      );

	set("outdoors", "chengdu");
	set("no_clean_up", 0);
	set("exits", ([
		"south" : __DIR__"chunxilu2",
		"north" : __DIR__"chunxilu",
		"east"  : __DIR__"jiulou1",
		"west"  : __DIR__"chaguan",
	]));
	set("coor/x", -8040);
	set("coor/y", -3020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);       
}


