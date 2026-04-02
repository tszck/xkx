// /d/city/obj/bing6.c 狀元餅

inherit ITEM;
#include <ansi.h>

mapping attr = ([
	"str" : "膂力",
	"con" : "根骨",
	"dex" : "身法",
	"sta" : "耐力",
	"kar" : "福緣",
	"cps" : "定力",
	"per" : "容貌"
]);
	
void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(RED "狀元餅" NOR, ({"bing6", "zhuangyuanbing"}));
	set("unit", "個");
	set("long", "這是一個唯一的狀元餅。\n");
	set("no_get", 1);
	set("no_drop", 1);
	set("no_put", 1);
	set("no_beg", 1);
	set("no_steal", 1);
	setup();
}

int do_eat(string arg)
{
	int i;
	object me=this_player();
	
	if (!id(arg))  return notify_fail("你要喫什麼？\n");
/*
	if (!wizardp(me) && query("owner") != me->query("id"))
	{
		write(HIR"你只能喫自個贏來的餅。\n"NOR);
		return 1;
	}
	
*/
	if(arg=="bing6"||arg=="zhuangyuanbing")
	{
		me->add("combat_exp",1968);
		me->add("potential",88);
		i = random(4);
		me->add(keys(attr)[i], 1);
		message_vision(HIY "$N三口兩口吃下一塊$n。\n" NOR, this_player(), this_object());
		tell_object(me, "你的"HIY + values(attr)[i] + NOR"提升了。\n");
		log_file("gift/tianfu",
		        sprintf("%-20s 喫下%-10s增加了%s(%s) [%s]\n",
		        me->query("name")+"("+me->query("id")+")",
		        base_name(this_object()),
		        values(attr)[i],keys(attr)[i],ctime(time())));
		destruct(this_object());
	}
	return 1;
}
void owner_is_killed()
{
        destruct(this_object());
}

