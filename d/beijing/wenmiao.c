#include <room.h>
inherit ROOM;

void create()
{
	set("short", "文廟");
	set("long", @LONG
這裏是文廟正殿，內有孔夫子像。歷代皇帝都懂得利用儒教思想來
鞏固自己的江山社稷，當朝皇帝自然也不例外。不論何人到此，都畢恭
畢敬地上香禮拜。
LONG );
	set("no_fight", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("objects", ([
		"/d/city/obj/box" : 1,
		"/d/taishan/npc/shu-sheng" : 1,
	]));
	set("exits", ([
		"west" : __DIR__"xisi",
	]));
	set("coor/x", -210);
	set("coor/y", 4070);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
