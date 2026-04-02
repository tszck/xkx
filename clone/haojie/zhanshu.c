// Last Modified by winder on Apr. 25 2001
// zhanshu.c

#include <ansi.h>
inherit ITEM;
int is_zhanshu() {return 1;}

void create()
{
	set_name( HIR"挑戰書"NOR,({ "zhan shu","shu","book"}));
	set_weight(200);
	seteuid(getuid());
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long","這是一張七殺門首領天殺星的挑戰書(kan)。\n");
		set("value", 5000);
		set("material", "paper");
	}
}

void init()
{
	add_action("do_kan","kan");
}

int do_kan(string arg)
{
	if ( !id(arg) )
		return notify_fail("你想看什麼？\n");
	write(HIR"            《生死之約》\n\n"NOR);
	write(WHT"    限你在十分鐘之內北京天安門廣場與我決\n");
	write(WHT"一死戰，不來者就是狗熊！\n\n");
	write(WHT"                      七殺門首領："HIR"天殺星\n"NOR);
	return 1;
}
