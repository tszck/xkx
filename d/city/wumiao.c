// Room: /city/wumiao.c
// YZC 1995/12/04 

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "武廟");
	set("long", @LONG
這裏是嶽王廟的正殿，內有嶽飛像，像上方懸掛嶽飛手書“還我河
山”的橫匾。殿兩側壁上嵌着“精忠報國”四個大字。武人到此，都放
下武器，畢恭畢敬地上香禮拜。旁邊似乎有一道側門。
LONG );
	set("no_fight", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");

	set("valid_startroom","1");
	set("objects", ([
		__DIR__"obj/box" : 1,
	]));

	set("exits", ([
		"east" : __DIR__"shilijie3",
		"up"   : __DIR__"wumiao2",
		"northwest": "/d/wizard/guest_room",
	]));
        create_door("northwest", "竹門", "southeast", DOOR_CLOSED);
	set("coor/x", 0);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
        "/clone/board/wiz2_b"->foo();
}

void init()
{
	object me;
	me=this_player();
	if (!wizardp(me)) me->set("startroom",base_name(environment(me)));
	if (!wizardp(me)) me->save();
	return;
}