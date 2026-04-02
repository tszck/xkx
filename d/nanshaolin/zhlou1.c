// Room: /d/nanshaolin/guangchang2.c
// Last Modified by Winder on May. 29 2001

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "鐘樓一層");
	set("long", @LONG
這裏是塔樓的底層，一縷縷陽光從牆上的花磚縫隙裏透射進來，在
青磚地上投下別緻的光影，如同一格格棋盤相似。往上看，長長的木樓
梯盤繞而上，似乎永無盡頭。牆角，梯級都相當潔淨，看來經常有僧人
打掃。
LONG );
	set("exits", ([
		"up"  : __DIR__"zhlou2",
		"out" : __DIR__"zhonglou",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1840);
	set("coor/y", -6280);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
