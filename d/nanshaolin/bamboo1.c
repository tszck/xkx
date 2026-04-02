// Room: /d/nanshaolin/bamboo1.c
// Last Modified by winder on May. 29 2001
// 這裏也是去達摩洞的地方。南少林也不要。

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "竹林");
	set("long", @LONG
這是一片密密的竹林。這裏人跡罕至，惟聞足底叩擊路面，有僧敲木魚
聲；微風吹拂竹葉，又如簌簌禪唱。令人塵心為之一滌，真是絕佳的禪修所
在。
LONG );

	set("exits", ([
		"east"  : __FILE__,
		"west"  : __FILE__,
		"north" : __FILE__,
		"south" : __FILE__,
/*
		"northeast" : __DIR__"bamboo"+(random(13)+1),
		"southwest" : __DIR__"bamboo2",
		"northwest" : __DIR__"bamboo"+(random(13)+1),
		"southeast" : __DIR__"bamboo"+(random(13)+1),
		"south" : __DIR__"shanroad6",
*/
	]));
	set("outdoors", "nanshaolin");
	set("no_clean_up", 0);
	set("coor/x", 1810);
	set("coor/y", -6020);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}

