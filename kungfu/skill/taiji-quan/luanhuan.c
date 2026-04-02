// luanhuan.c 太極拳「亂環訣」
// Last Modified by winder on Aug. 18 2002

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "「亂環訣」"
int perform(object me, object target)
{
	string *circle, msg;
	int foo;
	int flag;
	string fskill,sskill,bskill,pfname,pskill;

	sskill = explode(__FILE__,"/")[<2];
	pfname = explode(__FILE__,"/")[<1][0..<3];
  if (userp(me) && !wizardp(me) &&
   !me->query("perform/"+pfname) &&
   !me->query("can_perform/"+sskill+"/"+pfname) &&
   !me->query_temp("murong/xingyi") &&
   !SCBORN_D->valid_perform(me,sskill,pfname))
   return notify_fail("你所使用的外功中沒有這種功能。\n");

	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"只能對戰鬥中的對手使用。\n");
		
		//兵器空手均可
		
	if( me->query("combat_exp") < 500000 )
		return notify_fail("你實戰經驗不足，不會使用「亂環訣」。\n");

	fskill = "taiji-shengong";
	bskill = "unarmed";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 150 )
		return notify_fail("你的"+to_chinese(fskill)+"修爲不夠，無法運功傷敵。\n");

	if( (int)me->query_skill(sskill, 1) < 150 )
		return notify_fail("你的"+to_chinese(sskill)+"不夠嫺熟，使不出"+PNAME+"。\n");

	if( me->query_skill_mapped("force") != fskill )
		return notify_fail("你所用的內功與「亂環訣」氣路相悖！\n");

	if( !me->query_temp("murong/xingyi") )
	{
		if( userp(me) && !me->query_temp("taiji") && (int)me->query("jiali") )
		return notify_fail("用意不用力，太極圓轉無使斷絕。你加了力難以劃圈成圓。\n");
	}
	
	if( (int)me->query("max_neili") < 2000 )
		return notify_fail("你的內力修爲不夠，無法運功傷敵。\n");

	if( (int)me->query("neili") < 200 )
		return notify_fail("你現在的內力太弱，無法運功傷敵。\n");

	if( (int)me->query("qi") < 200 )
		return notify_fail("你現在的體力太弱，每一招難以暗蓄環勁。\n");

	if( (int)me->query("jing") < 200 )
		return notify_fail("你現在的精神太差，難以劃圓成圈。\n");

	circle = ({
		 "$N「雙風貫耳」，連消帶打，雙手成圓形擊出，隨即左圈右圈，一個圓圈跟着一個圓圈，大圈、小圈、平圈、立圈、正圈、斜圈，一個個太極圓圈發出。",
		 "$N「雲手」使出時連綿不斷，有如白雲行空，一個圓圈未完，第二個圓圈已生。",
		 "$N右肩斜閃，左手憑空劃了幾個圈子。"
	});
	msg = WHT"\n"+ circle[random(sizeof(circle))] +"\n";
	me->receive_damage("jing", 50);
	me->receive_damage("qi", 50);

	foo = me->query_temp("taiji") ? 260 : 220;
	if( random(me->query("combat_exp") * me->query_int() / 100) 
		> (int)target->query("combat_exp") * target->query_int() / foo )
	{
		msg += HIY"結果$N以環形之力，推得$n進了$P的無形圈內。\n"NOR;
		me->start_busy(1);
		call_out("zhen", 1, me, target); 
	}
	else
	{
		msg += CYN"可是$p看破了$P的企圖，並沒有上當。\n"NOR;
		me->start_busy(1+random(2));
	}

	message_combatd(msg, me, target);

	return 1;
}

int zhen(object me, object target)
{
	int damage, tjsg, tjq, fooo;
	string *zhen, msg, result, str, type;

	if( !me->is_fighting(target) || !living(target) ) return 0;

	tjsg = (int)me->query_skill("force");
	tjq = (int)me->query_skill("unarmed");

	zhen = ({
		 "但見$N雙臂一圈一轉，使出「六合勁」中的“鑽翻”“螺旋”二勁，已將$n圈住。",
		 "$N接着使出一招「雲手」，左手高，右手低，一個圓圈已將$n套住。"
	});

	fooo = me->query_temp("taiji") ? 120 : 179;
	if( random(me->query_skill("taiji-quan", 1)) > fooo )
	{
		type = "瘀傷";
		msg = HIY"\n只見$N左掌陽、右掌陰，目光凝視左手手臂，雙掌慢慢合攏，竟是凝重如山，卻又輕靈似羽。右捺左收，使得猶如行雲流水，瀟灑無比！\n"NOR
		"$n只覺上盤各路已全處在$P雙掌的籠罩之下，無可閃避，無可抵禦！\n";
	}
	else
	{
		type = "內傷";
		msg = "\n"+zhen[random(sizeof(zhen))] +"隨即潛運神功，企圖以內力震傷$p！\n";
	}

	if( target->query("neili") <= 0 )
	{
		msg += "$p只得強行運勁與$P相抗，不料猛然發覺自己真氣已然枯竭耗盡。\n";
		if( type == "內傷" )
			msg += RED "結果只聽見幾聲喀喀輕響，$n一聲慘叫，像灘軟泥般塌了下去！！\n"NOR;
		else 
			msg += RED "結果只聽見「砰」地一聲巨響，$n像一捆稻草般飛了出去！！\n"NOR;

		target->receive_damage("qi", (int)target->query("qi")+1, me);
	}
	else if( random((tjq + tjsg) * me->query_int() / 100) >
		(target->query_skill("parry") + target->query_skill("dodge")) * target->query_int() / 200 )
	{
		me->start_busy(1+random(2));
		target->start_busy(3);
		
		damage = tjsg + tjq/2;		
		damage = damage/2 + random(damage);

		if( type == "瘀傷" )
			damage = damage + tjq/2;
		if( me->query("neili") > target->query("neili")*2 )
			damage = damage + tjsg/2; 

		target->receive_damage("qi", damage, me);
		target->receive_wound("qi", damage/3, me);
		target->add("neili", -(damage/4));

		me->add("neili", -damage/10);

		result = COMBAT_D->damage_msg(damage, type);
		result = replace_string( result, "$p", target->name() );
		msg += result;

		str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
		msg += "( $n"+str+" )\n";
	}
	else if( random(tjsg) > target->query_skill("force")/2 )
	{
		me->start_busy(1+random(2));
		target->start_busy(2+random(1));
		
		damage = (int)me->query_skill("taiji-shengong", 1);
		damage = damage/2 + random(damage);
		
		target->receive_damage("qi", damage, me);
		target->receive_wound("qi", damage/3, me);
		me->add("neili", -damage/10);

		msg+= HIR"$p只得強行運勁與$N相抗，";
		if( damage < 100 ) 
			msg += "結果受到$P的內力反震，悶哼一聲。\n"NOR;
		else if( damage < 200 ) 
			msg += "結果被$P以內力反震，「嘿」地一聲退了兩步。\n"NOR;
		else if( damage < 400 ) 
			msg += "結果被$P以內力一震，胸口有如受到一記重錘，連退了五六步！\n"NOR;
		else 
			msg += "結果被$P的內力一震，眼前一黑，身子向後飛出丈許！！\n"NOR;
	}
	else if( me->query("neili")*2 < target->query("neili") ) 
	{
		me->start_busy(3);
		target->start_busy(1+random(2));
		
		damage = (int)target->query_skill("force")/2;
		damage = damage/2 + random(damage);
		
		me->receive_damage("qi", damage, me);
		me->receive_wound("qi", damage/3, me);
		target->add("neili", -damage/10);
		
		if( damage < 100 ) 
			msg += HIY "不料$P受到$p的內力反震，悶哼一聲。\n"NOR;
		else if( damage < 200 ) 
			msg += HIY "不料$P被$p以內力反震，「嘿」地一聲退了兩步。\n"NOR;
		else if( damage < 400 ) 
			msg += RED "不料$P被$p以內力反震，胸口有如受到一記重錘，連退了五六步！\n"NOR;
		else 
			msg += HIR "不料$P被$p的內力反震，眼前一黑，身子向後飛出丈許！！\n"NOR;
	}
	else
	{
		me->start_busy(3);
		target->start_busy(3); 
		me->receive_damage("qi", 50);
		me->add("neili", -300);
		target->receive_damage("qi", 50);
		target->add("neili", -300);
		msg += HIY"$p只得強行運勁與$P相抗，兩人身子都是一晃，各自退開幾步！\n"NOR;
	} 

	message_combatd(msg, me, target);
	return 1;
}

/*
緊跟着$N雙臂一合，一招「雙耳貫風」，雙拳擊向$n的左右兩耳。這一招綿勁中蓄，其軟如綿，其堅勝鐵！
*/
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		損傷對方氣血

	出手要求：
		太極神功150級
		太極拳150級
		經驗500000
		內力修爲2000
		內力200
		氣血200
		精氣200
		不能運加力或太極心法
HELP
	);
	return 1;
}
