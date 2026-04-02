// /d/taohua/liangongfang.c
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "練功房");
	set("long", @LONG
這是桃花島上的練功房。房中擺着幾個機關人，是給桃花島弟子練
功用的。這裏經常有弟子們在此練功，打得四處塵土飛揚。房後是桃花
島的試劍峯。
LONG );
	set("exits", ([
	    "south" :__DIR__"lianwuchang",
	    "north" :__DIR__"siguoshi" ,
	]));
	set("objects", ([
	      __DIR__"npc/jiguan" : 5,
	]) );
//	set("no_clean_up", 0);
	set("coor/x", 8980);
	set("coor/y", -3000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}