// Room: /d/wudujiao/huxue2.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "虎穴深處");
	set("long", @LONG
這裏是巖洞的深處，幾隻剛生下幾個月的小虎崽正在洞中嬉戲，洞
內角落裏有一堆白骨，你仔細一看，竟然是一具人類的遺骨。
LONG
	);

	set("exits", ([
		"north" : __DIR__"huxue1",
	]));
	set("objects", ([
		__DIR__"npc/laohu2": 3,
	]));

	set("coor/x", -45000);
	set("coor/y", -80010);
	set("coor/z", -10);
	setup();
}
void init()
{
	add_action("do_search","search");
	add_action("do_train","rain");
}

int do_search(string arg)
{
	object me=this_player();
	object ob;
	if( (!arg) ||!((arg == "bone") || (arg == "遺骨")))
		return notify_fail("你要搜索什麼？\n");

	if( !(ob = me->query_temp("weapon")) || ( (string)ob->query("skill_type"
)!="staff" && (string)ob->query("skill_type")!="blade" && (string)ob->query("ski
ll_type")!="sword" ) )
		return notify_fail("沒有工具怎麼幹活？\n");

	message_vision(HIR "\n$N輕輕撥動那堆白骨。\n\n" NOR, me);
/*
	if( "/d/wudujiao/obj/tongpai"->in_mud() )
	{
		message("vission",HIR"只聽呼啦一聲，從裏面竄出來一隻大老鼠。\n"NOR, me);
		return 1;
	}
*/
	if(query("not_tongpai"))
	{
		message("vission",HIR"只聽呼啦一聲，從裏面竄出來一隻大老鼠。\n"NOR,me);
		return 1;
	}
	ob=new(__DIR__"obj/tongpai.c");
	ob->move(environment(me));
	message_vision(HIR"只聽“噹啷..”一聲，從裏面滾出來一面銅牌。\n\n\n"NOR,me);
	set("not_tongpai", 1);
	call_out("regenerate", 86400);
	return 1;
}
int regenerate()
{
	set("not_tongpai", 0);
	return 1;
}

