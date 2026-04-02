// Room: /d/city/kuixingge.c
// Last Modified by winder on Apr. 10 2000

#include <room.h>
inherit ROOM;

void create()
{
	set("short","魁星閣");
	set("long",@LONG
一座三層的閣樓倚牆而建，二樓的檐上掛着一金字匾額「魁星閣」。
一樓塑着魁星，只見他手拿生花妙筆，悠然坐在閣臺上，面前的供桌擺
着一些個乾鮮果品，偶然有幾個書生進來跪拜魁星大人。
LONG    );

	set("outdoors", "yangzhouw");
	set("no_clean_up", 0);
	set("exits", ([
		"southeast" : __DIR__"caohebeijie",
	]));
	set("no_clean_up", 0);
	set("coor/x", -20);
	set("coor/y", 40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
