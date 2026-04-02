// /d/wizard/guest_room.c

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", HIC "BUG留言室" NOR);
	set("long", @LONG
這裏是巫師處理玩家提出的bug的地方，為便於巫師統一管
理和玩家參看巫師解決後的反饋，這裏只能發表(post)有關遊
戲bug問題，以供巫師解決。玩家可以在此發表任何符合該主題
的文章，巫師也將盡力解決並回復之。
LONG
);

	set("exits", ([
		"east": __DIR__"guest_room",
]));
	set("no_fight", 1);
	setup();
	"/clone/board/bug_b"->foo();
  replace_program(ROOM);
}