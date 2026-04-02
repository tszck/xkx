// Room: /d/shaolin/andao1.c
// Date: YZC 96/02/06

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "暗道");
	set("long", @LONG
這是一個陰暗潮溼的地道，四壁用粗糙的片岩壘垛而成，一
顆顆水珠沿着牆壁滾下來，濺在地上。也許是因爲長時間無人通
行的緣故，整個地道瀰漫着一股腐屍般的惡臭。
LONG );
	set("exits", ([
		"south" : __DIR__"rukou",
		"north" : __DIR__"jianyu1",
	]));
	create_door("north","木門","south",DOOR_CLOSED);
	set("objects",([
		__DIR__"npc/ad-laoshu" : 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -20);
	set("coor/y", 787);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}