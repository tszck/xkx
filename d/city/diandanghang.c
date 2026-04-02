// Room: /city/diandanghang.c
// Last Modified by Winder on Nov. 5 2000

#include <ansi.h>
inherit ROOM;

int do_quit();
void create()
{
	set("short", "典當行");
	set("long", @LONG
這是一家刻薄出名的典當行。一進門正中就是一幅潑墨中堂，“典
當”二字淋漓而下，出入此處的人客都氣爲之奪。高高的櫃檯上面開了
一個小窗口，僅容物品遞送和當銀交接之用。抬眼望進去，櫃檯上擺着
一個牌子 (paizi)，櫃檯後面卻是一個清清爽爽的女孩兒。你頓時全身
血液上衝：“東西當多少銀兩都值，只要能來多看她一眼”。
LONG
	);
	set("no_fight", 1);
	set("no_steal", 1);
	set("no_beg",1);
//	set("no_clean_up", 0);
	set("item_desc", ([
		"paizi" : "
pawn        當 
redeem      贖
value       估價

下面有兩個墨跡未乾的草體字    "HIR"停當\n"NOR,
	]));
	set("objects", ([
//		__DIR__"npc/ake" : 1,
	]));
	set("exits", ([
		"south" : __DIR__"caohebeijie",
	]));

	set("coor/x", -10);
	set("coor/y", 31);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
