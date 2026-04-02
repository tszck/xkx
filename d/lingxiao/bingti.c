// Room: /d/lingxiao/bingti.c
// Last Modified by Winder on Jul. 15 2001

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "冰梯");
	set("long", @LONG
這裏是一座晶瑩剔透的冰梯。此處地處萬裏雪山頂峯，連接凌霄城
的天險防線分天崖。懸在這裏，只覺罡風凜冽，如利刃割體，身側寒雲
渺渺，白煙氤氳。橋下萬載寒冰，在日光下閃爍生輝。山寒水冷，眾鳥
飛盡，惟有朵朵白雪，依舊飄零。這裏往往有傷心失意人跳崖自盡。
LONG );
	set("exits", ([
		"up"   : __DIR__"yuan",
		"down" : __DIR__"fentianya",
	]));
	set("outdoors", "lingxiao");
	set("no_clean_up", 0);
	set("coor/x", -31000);
	set("coor/y", -8940);
	set("coor/z", 130);
	setup();
}
void init()
{
	add_action("do_jump","jump");
}
int do_jump(object me)
{
	me = this_player();
	message_vision("$N看了看腳下悠悠白雲，一咬牙，眼一閉，縱身往冰橋下跳去\n", me);
	if (me->query_dex()>25)
	{
		me->move(__DIR__"juegu");
	}
	else if (me->query_dex()>20)
	{
		me->move(__DIR__"boot");
		me->unconcious();
	}
	else
	{
		me->move(__DIR__"juegu");
		me->die();
	}
	return 1;
}

