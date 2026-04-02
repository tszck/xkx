// Room: /d/nanshaolin/shiting7.c
// Last Modified by winder on May. 29 2001

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{ 
	set("short","石亭");
	set("long", @LONG
這裏是深藏地下的暗黑色的石亭，想是長年無光透入，一切都顯的
暗淡模糊。一盞忽明忽滅的油燈，幽靈般的吐着暗綠色的燈焰，一個面
無表情，無生命的石人，木然的站在這裏。
LONG );
	set("exits", ([
		"south" : __DIR__"shiting6",
	]));
	set("objects",([
		__DIR__"obj/mingchan" : 1,
	]));
	setup();
}
