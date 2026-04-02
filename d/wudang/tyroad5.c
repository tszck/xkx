// tyroad5.c 崎嶇山路
// by Marz 

inherit ROOM;

#include "feng.h"

void create()
{
	set("short", "崎嶇山路");
	set("long", @LONG
你走在一條崎嶇狹窄的山路上，一邊是峭壁，一邊是懸崖，高高的
天柱峯(feng)在雲霧中隱約可見。身旁的進香客和遊人都仔細地盯着自
己的腳下，不敢抬頭望一眼，惟恐一不小心摔下去。更有強人趁機打劫，
行人無不噤聲閉氣，只求快點趕路。
LONG );
	set("outdoors", "wudang");
	set("exits", ([
		"northup" : __DIR__"tyroad4",
		"eastdown" : __DIR__"tyroad6",
	]));
	set("item_desc", ([
		"feng" : (:look_feng:),
	]));
	set("no_clean_up", 0);
	set("coor/x", -2010);
	set("coor/y", -920);
	set("coor/z", 60);
	setup();
}

void init()
{
        add_action("look_feng", "look");
}
