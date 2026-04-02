// /clone/medicine/nostrum/binghuojiu.c 玄冰碧火酒
// Modified by Zeratul Jan 11 2001 force>特殊內功時喝酒增長內力，反之降內力

inherit ITEM;
inherit F_UNIQUE;
#include <ansi.h>

void init()
{
	add_action("do_drink", "drink");
	add_action("do_drink", "he");
}
void create()
{
	set_name(HIC "玄冰碧火酒" NOR, ({"xuanbingbihuo jiu", "jiu"}));
	set("unit", "壺");
	set("long", "這是一壺珍貴之極的玄冰碧火酒, 據説對內力修為有極大助益。\n");
	set("pour_type", "1");
	setup();
}
int do_drink(string arg)
{
	object me = this_player();
	mapping	skill_map = me->query_skill_map();
	int force_limit = me->query_skill( "force" ) * 10;
	int neili_limit = me->query( "max_neili" );
	
	if(!id(arg)) return notify_fail("你要喝什麼？\n");
	if(!present(this_object(), this_player()))
		return notify_fail("你要喝什麼？\n");
	if( me->is_busy() )
		return notify_fail("別急，慢慢喝，小心別嗆着了。\n");

	if(arg=="jiu")
	{
		tell_object(me, HIM"你仰起頭來，將壺中的酒盡數喝乾，登時腹痛如絞。當下運起內力，\n要將肚中這團害人之物化去。哪知這酒的毒性非同小可，這一發作\n出來，只痛得你全身抽搐，手足痙攣，立時便欲暈去。\n"NOR );
		if ( me->query_skill( "force", 1 ) < me->query_skill( skill_map["force"], 1 ) )
		{
			me->apply_condition( "scorpion_poison", 20 );
			me->apply_condition( "snake_poison", 20 );
			me->apply_condition( "flower_poison", 20 );
			me->add( "max_neili", -random(50) );
			tell_object(me, HIR"你抵擋不住猛烈的藥性，登時暈死過去。\n"NOR);
			me->unconcious();
		}
		else
			if ( (int)me->query_condition("binghuo" ) > 0 )
			{
				tell_object(me, HIR"你才喝此酒未久，還沒用內功化除淨盡，新酒入口，實難抵擋。\n"NOR);
				me->add( "max_neili", -random(20) );
				me->unconcious();
			}
			else
			{
				tell_object(me, HIG"你將以前學過、見過的諸般武功施展出來，亂打亂拍。只覺每發出\n一拳一掌，腹中的疼痛便隨內力的行走而帶了一些出來。使了一陣\n拳腳，腹內疼痛也隨之而減。直到劇毒盡數逼離肚腹，也就不再疼\n痛，內力修為似乎有了不小進益。\n"NOR);
				if ( neili_limit < force_limit )
					me->add("max_neili", 30 + random(30) );
			}
		me->apply_condition("binghuo", 500);
		destruct(this_object());
	}
	return 1;
}
