//square.c
inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "總舵廣場");
	set("long", @LONG
你走進了明教總舵廣場，卻發現這裏人聲鼎沸，五散人羣聚於此，
看來有要事發生了。來往教衆匆匆忙忙。廣場左首是教衆飯堂；右首就
是教衆聞之變色的刑堂。向上走就是光明頂明教總舵了。
LONG );
	set("exits", ([
		"west"    : __DIR__"fangtang",
		"northup" : __DIR__"qiandian",
		"east"    : __DIR__"xingtang",
		"south"   : __DIR__"tianweitang",
	]));
	set("objects",([
		__DIR__"npc/shuobude":1,
		__DIR__"npc/zhangzhong":1,
		__DIR__"npc/pengyingyu":1,
		__DIR__"npc/zhoudian":1,
		CLASS_D("mingjiao")+"/first" :1,
	]));
	set("valid_startroom","1");
	set("outdoors", "mingjiao");
	set("coor/x", -52030);
	set("coor/y", 1050);
	set("coor/z", 100);
	setup();
	"/clone/board/mingjiao_b"->foo();
}

int valid_leave(object me, string dir)
{
	mapping mypar;
	me = this_player();
	mypar=(mapping)me->query("party");
	if ( !wizardp(me) && (!mypar || mypar["party_name"]!=HIG "明教" NOR) &&
		(dir!="south") &&
		((objectp(present("peng yinyu", environment(me)))) ||
		(objectp(present("zhang zhong", environment(me)))) ||
		(objectp(present("shuo bude", environment(me)))) ||
		(objectp(present("zhou dian", environment(me))))))
	return notify_fail("明教五散人攔住你說：此處乃明教重地，請止步。\n");
	return ::valid_leave(me, dir);
}