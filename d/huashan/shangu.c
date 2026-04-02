// Room: /d/huashan/shangu.c
// Last Modified by winder on Aug. 1 2002

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "山谷");
	set("long", @LONG
這裏是中條山的一個隱祕山谷。四周是高可及天的山峯，雲深林密，
一徑小溪潺潺流過，濺入坡下塘中。溪畔有一漢子舞劍正酣。不打擾的
爲妙。
LONG );
	set("exits", ([ /* sizeof() == 4 */
		"south"     : __DIR__"pingdi",
		"northdown" : __DIR__"jzroad7",
	]));
	set("objects", ([
		CLASS_D("huashan")+"/cong-buqi": 1,
	]));
	set("outdoors", "zhongtiao");
	set("coor/x", -930);
	set("coor/y", 180);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}
