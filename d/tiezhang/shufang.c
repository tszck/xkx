// Room: /d/tiezhang/shufang.c
// Last Modified by winder on Nov. 17 2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"書房"NOR);
	set("long", @LONG
這裏是鐵掌幫內的書房。自從上代幫主上官劍南仙逝後，這個書房
就少有人來。靠牆壁的書架上滿是灰塵，窗戶也被一塊破簾子遮住一半
多，風颳着老動，也不見有多少光亮進來。
LONG	);
	set("exits", ([ 
		"south"      : __DIR__"zoulang2",
	]));
	set("objects", ([ 
		BOOK_DIR"spear_book" : random(2),
	]));
	set("no_clean_up", 0);
	set("coor/x", -2050);
	set("coor/y", -1950);
	set("coor/z", 30);
	setup();
	
}
