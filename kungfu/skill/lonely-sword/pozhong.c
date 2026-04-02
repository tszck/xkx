// pozhong.c 破衆

#include <ansi.h>
inherit F_SSERVER;

int perform(object me)
{

	object *ob,weapon,target;
	int i, skill, damage,flag=0;
	string msg;

	if(me->query("family/master_id") != "feng qingyang" && userp(me) && !wizardp(me))
		return notify_fail("你不是風清揚嫡傳弟子，不能使用絕招！\n");
  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/pozhong") &&
  !me->query("can_perform/lonely-sword/pozhong") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的外功中沒有這種功能。");

	if( !objectp(target) ) target = offensive_target(me);
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	  !living(target) || target->query_temp("noliving") )
		return notify_fail("獨孤九劍攻招只能對戰鬥中的對手使用。\n");
	skill = me->query_skill("lonely-sword",1);
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不對。\n");
	if( skill < 80)
		return notify_fail("你的獨孤九劍等級不夠，不能「破衆」！\n");
	if( me->query("max_neili") < 800 )
		return notify_fail("你的內力修爲不夠，無法運用「破衆」！\n");
	if( me->query("neili") < 500 )
		return notify_fail("你的內力不夠，無法運用「破衆」！\n");
//	if( environment(me)->query("no_fight") )
//		return notify_fail("在這裏不能攻擊他人。\n");
	me->add("neili", -250);
	me->receive_damage("qi", 10);
	me->start_busy(1);
	message_combatd(HIC"$N清嘯一聲，手中長劍輕轉，劍勢變幻，化出光芒千道，劍尖向四面八方疾速點出！\n"NOR,me);
	ob = all_inventory(environment(me));
	for(i=0; i<sizeof(ob); i++)
	{
		if( !living(ob[i]) ||ob[i]->query_temp("noliving")
		     || ob[i]==me ) continue;
		if( !ob[i]->is_fighting(me))
		          continue;  
		damage=skill-((int)ob[i]->query_skill("dodge",1)/2);
//		if ( damage <= 0 ) continue;
		if( damage>0 )
		{
			ob[i]->receive_damage("jing", damage);
			ob[i]->receive_damage("qi", damage*2);
			ob[i]->receive_wound("qi", damage);
			switch (random(5))
			{
				case 1:
message_combatd(HIC"$N手中劍尖破空，正刺中$n的咽喉！\n"NOR,me,ob[i]);
					break;
				case 2:
message_combatd(HIC"只見$N右手劍尖一點，$n胸口鮮血噴湧而出！\n"NOR,me,ob[i]);
					break;
				case 3:
message_combatd(HIC"$N手中劍光閃處，在$n手腕就是一個透明窟窿！\n"NOR,me,ob[i]);
					break;
				case 4:
message_combatd(HIC"$N手中劍尖斜挑，輕輕插進$n的小腹！\n"NOR,me,ob[i]);
					break;
				default:
message_combatd(HIC"你看見$N手中劍光一閃，正紮在$n左臂肩井穴上！\n"NOR,me,ob[i]);
					break;
			}
			tell_object(ob[i],HIC"你覺得眼前一點寒星直奔而來，頓覺一陣刺痛難忍，眼前發黑。\n"NOR);
		}
		if(userp(ob[i])) ob[i]->fight_ob(me);
		else if( !ob[i]->is_killing(me)) ob[i]->kill_ob(me);
	}
	return 1;
}

int help(object me)
{
	write(WHT"\n獨孤九劍之破衆："NOR"\n");
	write(@HELP

	使用功效：
		對羣毆之敵出手，傷敵精氣氣血

	出手要求：
		身爲風清揚嫡傳弟子
		獨孤九劍80級
		內力修爲50
		內力250
HELP
	);
	return 1;
}

