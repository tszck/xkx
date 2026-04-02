// yinhuo.c 抽髓掌之銀火
// Last Modified by winder on Feb. 17 2001

#include <ansi.h>
#include <combat.h>
#define PNAME "「銀火」"
inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";
int check_pfm(object me, object target, object ob);
int perform(object me, object target)
{
	object ob;
	int flag;
	string fskill,sskill,bskill,pfname,pskill;

	sskill = explode(__FILE__,"/")[<2];
	pfname = explode(__FILE__,"/")[<1][0..<3];
  if (userp(me) && !wizardp(me) &&
   !me->query("perform/"+pfname) &&
   !me->query("can_perform/"+sskill+"/"+pfname) &&
   !me->query_temp("murong/xingyi") &&
   !SCBORN_D->valid_perform(me,sskill,pfname) )
   return notify_fail("你所使用的外功中沒有這種功能。\n");

	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"只能對戰鬥中的對手使用。\n");
		
	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必須空手才能使用"PNAME"！\n");	

	if(me->query_temp("pfm_chousui"))
		return notify_fail("你正在驅動火堆進行攻擊！\n");
	fskill = "huagong-dafa";
	bskill = "strike";
	pskill = "poison";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
		pskill = "douzhuan-xingyi";
	}
	if( (int)me->query_skill(fskill, 1) < 140 )
		return notify_fail("你的"+to_chinese(fskill)+"修爲不夠，無法使用"+PNAME+"。\n");
	if( (int)me->query_skill(sskill, 1) < 140 )
		return notify_fail("你的"+to_chinese(sskill)+"還不夠嫺熟，無法使用"+PNAME+"。\n");
	if( (int)me->query_skill(pskill, 1) < 110 )
		return notify_fail("你發現自己體內聚毒不夠，無法使用"+PNAME+"進行攻擊。\n");
	if( me->query_skill_mapped("force") != fskill)
		return notify_fail("你發現自己所用的內功無法進行"PNAME"攻擊。\n");
	if( (int)me->query("max_neili") < 1200)
		return notify_fail("你發現自己內力太弱，無法驅動"PNAME"進行攻擊。\n");
	if((int)me->query("neili") < 900)
		tell_object(me,"你發現自己現在真氣太弱，使不出"PNAME"進行攻擊。\n");	   

	if(!objectp(ob = present("huo yan", environment(me))))
	{
		if (userp(me))
		return notify_fail("沒有火堆怎麼驅動「銀火」進行攻擊？\n");
	  message_combatd(HIR"\n$N咬破指尖，數滴鮮血落到地面，再用內力一鼓，轟地一聲燃起一堆熊熊火焰！\n\n"NOR,me);
 	  seteuid(getuid());
	  ob = new("/d/xingxiu/npc/obj/huoyan");
	  ob->move(environment(me));
	}
	message_combatd(YEL"\n$N"YEL"衣袖一拂，一股勁氣直射入"HIR"火焰"YEL"之中。從中又分出一道細細的"WHT"銀火"YEL"，\n便似一條"WHT"銀色長蛇"YEL"橫臥空際，輕輕擺動，顏色又是鮮豔，又是詭異，"RED"光芒"YEL"閃爍不定！\n"NOR,me);
	me->start_busy(2);
	me->set_temp("pfm_chousui", 1);
	if(random(me->query_kar()) > 15) check_pfm(me, target, ob);
	else call_out("check_pfm", 4, me, target, ob);
	return 1;
}

int check_pfm(object me, object target, object ob)
{
	string msg, *limbs;
	int i, neili, ap, dp, damage, p;
	object wep,piece;
	if(!me) return 0;	
	i = (int)me->query_skill("strike", 1);
	neili = (int)me->query("neili");	

	me->delete_temp("pfm_chousui");
	me->start_busy(1);
	if(!living(me) || me->query_temp("noliving") ||
		 me->is_ghost()) return 1;
	if(!living(target) || !target || !me->is_fighting(target) ||
		environment(me)->query("no_fight") ||
		environment(me)!=environment(target))
	{
		message_combatd(HIY"$N衣袖再拂，將升起的"WHT"銀火"HIY"壓回火焰之中。\n"NOR,me);
		return 1;
	}
	if(!objectp(present(ob, environment(me))))
	{
		message_combatd(HIY"$N眼看火堆熄滅，長嘆一聲，散開內息，雙手下垂而立。\n"NOR,me);
		return 1;
	}

	ap = me->query("combat_exp")/1000 * i * me->query_str();
	dp = target->query("combat_exp")/1000 * target->query_skill("parry",1) * target->query_str();
	if (ap < 1) ap = 1;
	if (dp < 1) dp = 1;
	me->add("neili", -500);
	me->receive_damage("jing", 50);

	msg = YEL"\n突然火焰中升起"GRN"綠色鬼火"YEL"，此時"WHT"銀火"YEL"倏地縮回，\n跟着又向$n$l射去，力道極猛，去勢奇快！\n"NOR;	

       
	if(random(ap) > dp/3)
	{
		if(objectp(wep = target->query_temp("weapon")))
		{ 
			msg +=HIY"$n看那銀火來得迅猛無常，避無可避，只得把手中武器舉起來硬擋！\n" NOR;
			if(me->query("neili") < target->query("neili")*2)
			{
				me->start_busy(2);
				msg += HIY "結果只聽一聲大響，$w"HIY"在$W"HIY"上撞出無數飛花，四散濺開！\n" NOR;
			}
			else if(me->query("neili") > target->query("neili")*4)
				{
					if(wep->query("rigidity") >= 50)
					{
						me->start_busy(2);
						target->start_busy(2);
						wep->move(environment(target));
						msg += HIW "結果只聽“嘣”的一聲，在$w"HIW"的猛烈撞擊下，$n虎口震裂，$W"HIW"脫手飛出！\n" NOR;
					}
					else
					{
						me->start_busy(2);
						target->start_busy(2);
						msg += HIW "結果只聽“啪”的一聲巨響，$n手中"+wep->name()+HIW"被$w"HIW"打斷，碎片四散濺落！\n" NOR;
						wep->unequip();
						target->reset_action();
						seteuid(getuid());
		        piece = new("/clone/misc/piece");
      			piece->set_name( "斷掉的"+wep->query("name"), ({wep->query("id"),"piece"}) );
       			piece->set("long", wep->query("long")+"可惜已經被打得粉碎了。\n");
        		piece->move(environment(target));
       			destruct(wep);
					}
				}
				else
				{
					if(wep->query("rigidity") >= 50)
					{
						me->start_busy(2);
						target->start_busy(2);
						msg += HIY "結果只聽一聲大響，$w在$W上撞出無數飛花，四散濺開！\n" NOR;
					}
					else
					{
						me->start_busy(2);
						target->start_busy(2);
						wep->move(environment(target));
						msg += HIW "結果只聽“嘣”的一聲，在$w"HIW"的猛烈撞擊下，$n虎口震裂，$W"HIW"脫手飛出！\n" NOR;
					}
				}
			msg = replace_string(msg, "$W", wep->name());
		}
		else
		{
			damage = i*2+me->query("jiali")*2;
			if(neili > target->query("neili")*2) damage = damage*2;
			if (damage > 1000) damage = 1000;
			target->receive_damage("qi", damage,me);		
			target->receive_wound("qi",damage/2,me);
			target->apply_condition("xx_poison", random(3) + (me->query_skill("poison", 1)/10) + target->query_condition("xx_poison"));
			p = (int)target->query("qi")*100/(int)target->query("max_qi");
			msg += damage_msg(damage, "刺傷");
			msg += "( $n"+eff_status_msg(p)+" )\n";
			me->start_busy(2);
			target->start_busy(2);
		}
	}
	else
	{
		me->start_busy(3);
		msg += HIY"\n$p全力向右一滾，那$w"HIY"堪堪擦肩而過，端的是兇險無比！\n" NOR;
	}
	limbs = target->query("limbs");
	msg = replace_string(msg, "$l", limbs[random(sizeof(limbs))]);
	msg = replace_string(msg, "$w", WHT"銀火"NOR);   
//	if(!target->is_killing(me->query("id"))) target->kill_ob(me);    
	message_combatd(msg, me, target);
	return 1;
}  

string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		傷害對方氣血
		使對手中星宿毒
		毀損或擊落對手兵器

	出手要求：
		化功大法140級
		抽髓掌140級
		基本毒技110級
		內力修爲1200
		內力900
		周圍有火堆
HELP
	);
	return 1;
}

