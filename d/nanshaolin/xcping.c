// Room: /d/nanshaolin/xcping.c
// Last Modified by winder on May. 29 2001

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{ 
	set("short",HIG"心禪坪"NOR);
	set("long", @LONG
這裏是一片林間空地，三面環繞着千年古衫，生長的鬱鬱蔥蔥好不
茂盛。地面是一塊正方大青石，與寺內石徑頗為不類，疑是寺外移來。
不知前輩僧人勞心勞力，運來此物何用。石坪清掃的頗為潔淨，只是在
林邊有一塊小尖石，頗為醒目。北面有一座石坊，上書心禪堂三個大字。
一位老僧斜倚着石坊，似乎半夢半醒。
LONG );
	set("exits", ([
		"north" : __DIR__"xctang",
		"west"  : __DIR__"huilang8",
	]));
	set("outdoors", "nanshaolin");
	set("objects",([
		__DIR__"npc/zsseng1" : 1,
	]));
	set("coor/x", 1820);
	set("coor/y", -6100);
	set("coor/z", 20);
	setup();
}
void init()
{
	add_action("do_huadi", "huadi");
}       
int do_huadi()
{
	object me = this_player();
	if (((int)me->query("max_neili",1)>1000) &&
		((int)me->query("neili",1)>500))
	{
		message("vision", "\n只見"+me->query("name")+"彎腰在路旁撿起一塊尖石，\n在青石地上劃了起來，不多時便畫成了一個縱橫十九道的大圍棋盤，但見\n橫平豎直，端的是神乎其技。\n", environment(me), ({me}) );
		write("你在青石地上劃出了一個大棋盤。\n");
		me->add("neili", -500);
		me->set_temp("huadi",1);
	}
	else
	{
		message("vision",me->query("name")+"趴在地上劃的手都酸了，但石質堅硬，連一道紋都沒有。\n", environment(me), ({me}) );
		write("你劃了半天終因內力不夠，無法留下任何印記。\n");
	}    
	return 1;
}
int valid_leave(object me, string dir)
{
	if (dir == "north" && !me->query("pass_xin") &&
		objectp(present("zhishi seng", environment(me))))
		return notify_fail("執事僧伸手攔住你，心禪堂不可妄入。\n");
	return ::valid_leave(me, dir);
}

