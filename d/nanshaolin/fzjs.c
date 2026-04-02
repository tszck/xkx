// Room: /d/nanshaolin/fzjs.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

#include <ansi.h>

void create()
{
	set("short", HIG"方丈精舍"NOR);
	set("long", @LONG
這裏的地上整整齊齊的排放着數十個黃布蒲團，北首有一個紅木講
壇，講壇上放着個竹製的木魚。東西邊各放着一對美輪美奐的大花瓶，
上插檀香數枝，香菸繚繞，氤氳芬芳，室內一片祥和之氣。看來這裏是
方丈對僧衆講經說法的地方。
LONG );
	set("exits", ([
		"up"   : __DIR__"fzjs1",
		"east" : __DIR__"xiaolu7",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1780);
	set("coor/y", -6150);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

