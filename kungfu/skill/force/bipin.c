// Last Modified by winder on Feb. 28 2001
// bipin.c 內力比拼
 
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int start_bipin(object me);

int exert(object me, string arg)
{
	object target;
	int myint,taint,mydex,tadex,mydodge,tadodge;
	int myexp,taexp,myneili,taneili;
	
	seteuid(getuid());

	if(!arg) return notify_fail("你想和誰比拼內力？\n");

	if(!objectp(target = present(arg, environment(me))))
		return notify_fail("這裏沒有這個人。\n"); 

	if( !target->is_fighting() ||
		!target->is_character() ||
		!me->is_fighting() )
		return notify_fail("內力比拼只能在戰鬥中使用。\n");

	if ( !living(target) || target->query_temp("noliving") )
		return notify_fail("你似乎不用再和"+target->name()+"比拼內力。\n"); 

	if(target==me) return notify_fail("想和自己比拼內力？\n"); 

	if(!me->is_fighting(target))
		return notify_fail("你必須在"+target->name()+"和你戰鬥的時候，才能使用內力比拼。\n");		

	if(me->query_temp("weapon") || target->query_temp("weapon"))
		return notify_fail("在雙方空手戰鬥的時候才能使用內力比拼。\n");

	myneili = me->query("neili");
	taneili = target->query("neili");

	if(me->query_skill("force", 1) < 50 )
		return notify_fail("你的內功修爲不足，無法和對手較量內力。\n");

	if(myneili < 500 )
		return notify_fail("你的真氣太弱，無法和對手較量內力。\n");

	if(myneili*2/3 >= taneili)
		return notify_fail("對手的內功修爲遠不如你，還用比拼什麼內力呢？\n");

	if((int)me->query("max_neili") < 500 )
		return notify_fail("你的內力修爲太弱，無法和對手較量內力。\n");

	if(me->query_temp("neili/bipin")) 
		return notify_fail("你正在和人比拼內力。\n");

	if(target->query_temp("neili/bipin")) 
		return notify_fail(target->name()+"正在和人比拼內力。\n");  

	myint = me->query_int();
	taint = target->query_int();
	mydex = me->query_dex();
	tadex = target->query_dex();
	myexp = me->query("combat_exp",1);
	taexp = target->query("combat_exp",1); 
	mydodge = me->query("dodge");
	tadodge = target->query("dodge");
	me->set_temp("bipin/target", target->query("id"));
	target->set_temp("bipin/target", me->query("id"));

	write(HIY"你凝聚畢生功力緩緩推出一掌，一股勁風已然壓向" + target->name() + "壓了過去。\n"NOR);
	tell_room( environment(me), HIY+me->name()+"運起畢生功力緩緩推出一掌，一股勁風已然向" + target->name() + "壓去。\n"NOR, ({ me })); 

	if (((myint*5+mydex*5+mydodge+myexp*2/100000) >= (taint*5+tadex*5+tadodge+taexp*2/100000)*2/3)&&(random(5)>=2))
	{
		message_combatd(HIW"$n駭然至極，連忙雙腿彈起，向後躍出數丈，才勉強躲開$N這兇猛一擊。\n"NOR, me, target);
		me->add("neili", -200);
		if( me->query("neili") < 0) me->set("neili", 0);
		me->start_busy(3);
		target->start_busy(2);
                return 0;
	} 
	else 
	{
	message_combatd(HIY"$n眼看無法躲閃，急忙運足真氣，硬接了$N的雙掌。\n"NOR, me, target);

	me->add("neili",-200);
	if( me->query("neili") < 0) me->set("neili", 0);
	target->add("neili",-200);
	if( target->query("neili") < 0) target->set("neili", 0);
	me->set_temp("neili/bipin",1);
	target->set_temp("neili/bipin",1);
	me->set_temp("bipin/target", target->query("id"));
	target->set_temp("bipin/target", me->query("id"));
	target->start_busy((: start_bipin :));
	me->start_busy((: start_bipin :));
	me->set_temp("bipin/period", 1);
	return 1;
        }
}
int start_bipin(object me)
{
	string tar;
	object target, *all;
	int myneili_lost, obneili_lost, period, neili, neili2, count, ok=1;

	if(!me) return 0;
	all = all_inventory(environment(me));
	for (count=0; count<sizeof(all); count++)
		if( all[count]->query("id") == me->query_temp("bipin/target"))
		{
			ok = 0;
			target = all[count];
		}
	if (ok == 1) return 0;

	neili = me->query("neili");
	neili2 = target->query("neili");
	myneili_lost = target->query("max_neili")/200 + target->query("force")/20 + random (3);
	obneili_lost = me->query("max_neili")/200 + me->query("force")/20 + random (3);
	period = (int)me->query_temp("bipin/period"); 

	me->add("neili", -myneili_lost);
	if( me->query("neili") < 0) me->set("neili", 0);
	me->receive_damage("jing", 3+random(target->query_skill("force")/10));	
	me->receive_damage("qi", target->query("jiali")/10);
	me->improve_skill("force", random(2));

	target->add("neili", -obneili_lost);
	if( target->query("neili") < 0) target->set("neili", 0);
	target->receive_damage("jing", 3+random(me->query_skill("force")/20));	
	target->receive_damage("qi", me->query("jiali")/10);
	target->improve_skill("force", random(2));

	if(me->is_ghost()) return 0;
	if(!target || target->is_ghost() ||
		environment(me)!=environment(target))
	{
		message_combatd(CYN"$N當下內勁一收，一雙衣袖便即垂下，搖搖幌幌地站了起來。\n"NOR, me);
		return 0;
	}

	if(neili < myneili_lost)
	{
		message_combatd(RED"$N只覺壓力越來越重，胸口煩惡，漸漸每喘一口氣都感艱難，突然身體一陣搖晃，暈到在一旁。\n"NOR, me);
		me->unconcious();
		me->add("max_neili",-5); 
		me->set_delete("bipin/target",);
		target->set_delete("bipin/target",);
		me->delete_temp("neili/bipin");
		target->delete_temp("neili/bipin");
		message_combatd(HIW"$N只覺得心神俱衰，深深吸了口氣，但臉色慘白如紙。\n"NOR,target);
		return 0;
	} 
	if( (!living(target) || target->query_temp("noliving") ) &&
		(living(me) && !me->query_temp("noliving")) )
	{
		message_combatd(RED"$N只覺壓力越來越重，胸口煩惡，漸漸每喘一口氣都感艱難，突然身體一陣搖晃，暈到在一旁。\n"NOR, target);
		target->unconcious();
		target->add("max_neili",-5);
		target->unconcious();
		message_combatd(HIW"$N深深吸了口氣，壓住散亂的真氣，臉色慘白如紙。\n"NOR,me);
		me->delete_temp("bipin/target",);
		target->delete_temp("bipin/target",);  
		me->delete_temp("neili/bipin");
		target->delete_temp("neili/bipin");  
		return 0;
	}
	if( (!living(target) || target->query_temp("noliving") ) &&
		(!living(me) || me->query_temp("noliving")) )
	{
		me->set_delete("bipin/target");
		target->set_delete("bipin/target");
		me->delete_temp("neili/bipin");
		target->delete_temp("neili/bipin");
		message_combatd(HIW"此時$N臉上都已無半點血色，看來已經到了油盡燈枯之時！\n"NOR, me);
		me->set_temp("last_damage_from","和"+target->name()+"同歸於盡");
		me->die();
		return 0;
	}

	switch(period)
	{
		case 3: 
		case 9:
		case 15:
		case 21: 
		case 27:
		case 33:
		case 39:
		case 45:
		case 51:
		case 57:
			if((neili+neili2) >=1500)
			{
				message_combatd(HIW"不一會，$N和$n頭頂都透出一縷縷的白氣，漸漸越來越濃，就如蒸籠一般。\n"NOR, me, target);
			}
			break;
		case 63:
		case 69:
		case 75:
		case 81:
		case 87:
		case 93:
		case 99:
		case 115:
		case 145:
		case 175:
		case 205:  
			if(neili > neili2)
			{
				message_combatd(HIR"$N催動內勁，頭頂白氣越聚越濃，雙掌緩緩的向$n推去。\n"NOR,me, target);
			}
			else
			{
				message_combatd(HIR"$N催動內勁，頭頂白氣越聚越濃，雙掌緩緩的向$n推去。\n"NOR,target,me);
			}
			break;
		case 12:
		case 24:
		case 42:
		case 60:
		case 78:  
		case 96: 
		case 125:
		case 155:
		case 185:
			if(neili > neili2)
			{
				message_combatd(HIR"$N頭頂白氣凝聚不散，面色越來越嚴峻，不斷鼓動內勁向$n推去。\n"NOR, me, target);
			}
			else
			{
				message_combatd(HIR"$N頭頂白氣凝聚不散，面色越來越嚴峻，不斷鼓動內勁向$n推去。\n"NOR, target, me);
			}
			break; 
		case 36:
		case 54:
		case 72:
		case 90:
		case 105:
		case 135:
		case 165:
		case 195:
			if(me->query("jiali") < target->query("jiali"))
			{
				message_combatd(HIR"$N只覺手上一沉，對方力道湧來，忙加勁反擊。\n"NOR,me);
			}
			else
			{
				message_combatd(HIR"$N只覺手上一沉，對方力道湧來，忙加勁反擊。\n"NOR,target);
			}
			break;
	} 

	period++;
	me->set_temp("bipin/period", period);
//	target->set_temp("bipin/period", period);
//	me->delete_temp("neili/bipin");
//	target->delete_temp("neili/bipin");
	return 1;	
}

int help(object me)
{
	write(WHT"\n基本內功之內力比拼："NOR"\n");
	write(@HELP

	使用功效：
		與對手比拚內力至不死不休，抑或兩敗俱傷

	出手要求：
		基本內功50級
		內力修爲500
		內力500
HELP
	);
	return 1;
}

