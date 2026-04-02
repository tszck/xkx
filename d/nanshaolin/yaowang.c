// Room: /d/nanshaolin/yaowang.c
// Last Modified by winder on May. 29 2001

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", GRN"藥王院"NOR);
	set("long", @LONG
一進藥王院，撲鼻而來的是濃鬱的藥香。房間內排滿了裝滿各類藥
材的大藥櫃，每個藥櫃都有上百個裝藥的抽屜貼滿了各類藥名。西邊是
一個巨大紅杉木櫃，櫃上貼着方丈印的封條。一位中年僧人正來回忙碌
着指點衆執役僧稱量藥品，熬藥煎湯。
LONG );
	set("exits", ([
		"west" : __DIR__ "songshu1",
	]));
	set("objects",([
		CLASS_D("nanshaolin") + "/fangji" : 1,
	]));
	set("coor/x", 1830);
	set("coor/y", -6200);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

