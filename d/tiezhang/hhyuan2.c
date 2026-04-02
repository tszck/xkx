// Room: /d/tiezhang/hhyuan2.c
// Last Modified by winder on Nov. 17 2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIR"花圃"NOR);
	set("long", @LONG
只見這裏擺滿了茉莉、素馨、麝香藤、朱槿、玉桂、紅蕉，都是夏
日盛開的香花。院牆上又掛了枷木蘭、真臘龍誕等香珠，但覺馨意襲人， 
清芬滿園。園中桌上放着幾盆新藕、甜瓜、枇杷、等鮮果，椅子上丟着
一把蒲扇，看來是幫主休息的地方。
LONG	);
	set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"hhyuan1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");
	set("coor/x", -2030);
	set("coor/y", -1940);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}