// Room: /city/hangou2.c
// Last Modified by winder on Apr. 10 2000

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "古邗溝邊");
	set("long", @LONG
離開揚州北門，沿着古老的邗溝向北而行，就是上楚州轉汴京的大
路。這條大路和古邗溝是並行的，可以看到古邗溝中舟楫點點，往來穿
梭。揚州作為水陸交通的大都會，古邗溝是將其同南北大運河相連接的
重要渠道，所以溝中的船隻非常的稠密。
LONG );
	set("exits", ([
		"southwest" : __DIR__"beimen",
		"east"      : __DIR__"hangou1",
	]));
	set("outdoors", "yangzhouw");
	set("no_clean_up", 0);
	set("coor/x", 20);
	set("coor/y", 110);
	set("coor/z", -10);
	setup();
	replace_program(ROOM);
}