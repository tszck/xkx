// Room: /d/huashan/qunxianguan.c
// Last Modified by winder on Aug. 1 2002

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "羣仙觀");
	set("long", @LONG
這裏是華山派歷來之根本重地，牆上掛着華山派歷代掌門人的畫像，
華山派一切重大禮儀都在這裏舉行。這裏也是華山弟子講武習劍之地。
北邊就是華山掌門嶽不羣的居所「有所不爲軒」。
LONG );
	set("exits", ([ /* sizeof() == 4 */
		"south": __DIR__"square",
		"north": __DIR__"buwei1",
	]));
	set("objects", ([
		CLASS_D("huashan") + "/yue-buqun": 1,
	]));

	set("coor/x", -860);
	set("coor/y", 210);
	set("coor/z", 120);
	setup();
	replace_program(ROOM);
}
